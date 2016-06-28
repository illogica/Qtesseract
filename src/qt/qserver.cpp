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

void Qserver::disconnect_client(int clientnum, int disconnect_reason)
{
    ::disconnect_client(clientnum, disconnect_reason);
}

void Qserver::connected(QJSValue ci)
{
    //server::clientinfo tci;
    //tci = js.fromScriptValue<server::clientinfo>(ci);
    //server::connected(&tci);
    //server::connected(js.fromScriptValue<server::clientinfo*>(ci));
    server::connected(qobject_cast<server::clientinfo*>(ci.toQObject()));
}

bool Qserver::hasnonlocalclients(){ return ::hasnonlocalclients();}

QString Qserver::serverauth() { return QString::fromLocal8Bit(server::serverauth);}


