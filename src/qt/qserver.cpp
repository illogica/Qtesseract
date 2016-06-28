#include "qserver.h"
#include <QDebug>

Qserver::Qserver(QObject *parent) : QObject(parent)
{
    eventsMap = new ServerEventsMap();

    srv = js.newQObject(this);
    js.installExtensions(QJSEngine::ConsoleExtension | QJSEngine::GarbageCollectionExtension);
    js.globalObject().setProperty("server", srv);

    jsLoader = new JSLoader(this);
    connect(jsLoader, SIGNAL(jsSourcesChanged(QStringList&)), this, SLOT(reloadJs(QStringList&)));
    jsLoader->init();
}

Qserver::~Qserver()
{
    delete eventsMap;
}

bool Qserver::hasEvent(int event)
{
    return eventsMap->hasEvent(event);
}

void Qserver::reloadJs(QStringList &sources)
{
    eventsMap->clear();
    int counter = 0;
    bool error = false;
    for( QString s : sources ){
        QJSValue result = js.evaluate(s);
        if (result.isError()){
            QString err("Uncaught exception at line");
            err += result.property("lineNumber").toString();
            err += ": ";
            err += result.toString();
            sendservmsg(err);
            qDebug() << err;
            logoutf(err);
            error = true;
        }
        counter++;
    }
    QString success("JS: reloaded ");
    success += " .js files. ";
    success += error ? " WARINING - ERRORS IN JS FILES" : "No errors.";
    qDebug() << success;
    sendservmsg(success);
    logoutf(success);
}

//Called by javascript
void Qserver::registerHook(int event, QString functionName, bool bypass)
{
    EventData ed(functionName, bypass);
    eventsMap->registerEvent(event, ed);
}

bool Qserver::runEventHooks(int event, QJSValueList &capsule)
{
    bool bypass = false;
    for(EventData ed : eventsMap->getEventData(event)){
        if(js.globalObject().hasProperty(ed.jsFunctionName)){
            QJSValue result = js.globalObject().property(ed.jsFunctionName).call(capsule);
            if (result.isError()){
                QString err("Uncaught exception at line");
                err += result.property("lineNumber").toString();
                err += ": ";
                err += result.toString();
                sendservmsg(err);
                qDebug() << err;
                logoutf(err);
            }
        }
        bypass |= ed.bypass;
    }
    return bypass;
}

void Qserver::sendservmsg(QString s){  server::sendservmsg(s.toLocal8Bit().data()); }
void Qserver::logoutf(QString s){ ::logoutf(s.toLocal8Bit().data()); }

int Qserver::allowconnect(QJSValue ci, QString pwd)
{
    //server::clientinfo tci;
    //tci = js.fromScriptValue<server::clientinfo>(ci);
    //return server::allowconnect(&tci, pwd.toLocal8Bit().data());
    //return server::allowconnect(js.fromScriptValue<server::clientinfo*>(ci), pwd.toLocal8Bit().data());

    return server::allowconnect((server::clientinfo*)ci.toQObject(), pwd.toLocal8Bit().data());
}

void Qserver::disconnect_client(int sender, int disconnect_reason)
{
    ::disconnect_client(sender, disconnect_reason);
}

void Qserver::connected(QJSValue ci)
{
    //server::clientinfo tci;
    //tci = js.fromScriptValue<server::clientinfo>(ci);
    //server::connected(&tci);
    //server::connected(js.fromScriptValue<server::clientinfo*>(ci));
    server::connected(qobject_cast<server::clientinfo*>(ci.toQObject()));
}

QString Qserver::serverauth() { return QString::fromLocal8Bit(server::serverauth);}

void Qserver::on_N_CONNECT(server::clientinfo *ci, QString password, QString authdesc, QString authname)
{
    qDebug() << "N_CONNECT from " + QString(ci->name);
}

void Qserver::on_N_PING(server::clientinfo *ci)
{
    //qDebug() << "Ping request from " + QString(ci->name);
}

void Qserver::on_N_AUTHANS(server::clientinfo *ci, QString desc, QString ans, uint id)
{
    qDebug() << "N_AUTHANS from " + QString(ci->name);
}

void Qserver::on_N_POS(server::clientinfo *ci, server::clientinfo *cp, vec pos, int mag, int dir, vec vel)
{
    //qDebug() << "N_POS from " << QString(ci->name) << ", pos x: " << pos[0] << ", pos y: " << pos[1] << ", pos z: " << pos[2] << "\n";
}

void Qserver::on_N_TELEPORT(server::clientinfo *ci, server::clientinfo *cp, int teleport, int teledest)
{
    qDebug() << "N_TELEPORT from " + QString(ci->name);
}

void Qserver::on_N_JUMPPAD(server::clientinfo *ci, server::clientinfo *cp, int jumppad)
{
    qDebug() << "N_JUMPPAD from " + QString(ci->name);
}

void Qserver::on_N_FROMAI(server::clientinfo *ci, server::clientinfo *cq)
{
    qDebug() << "N_FROMAI from " + QString(ci->name);
}

void Qserver::on_N_EDITMODE(server::clientinfo *ci, int val)
{
    qDebug() << "N_EDITMODE from " + QString(ci->name);
}

void Qserver::on_N_MAPCRC(server::clientinfo *ci, int crc, QString mapname)
{
    qDebug() << "N_MAPCRC from " + QString(ci->name);
}

void Qserver::on_N_CHECKMAPS(server::clientinfo *ci)
{
    qDebug() << "N_CHECKMAPS from " + QString(ci->name);
}
