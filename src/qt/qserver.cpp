#include "qserver.h"
#include <QDebug>

Qserver::Qserver(QObject *parent) : QObject(parent)
{
    eventsMap = new ServerEventsMap();

    srv = js.newQObject(this);
    //the following line requires Qt5.6.x
    //js.installExtensions(QJSEngine::ConsoleExtension | QJSEngine::GarbageCollectionExtension);
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
void Qserver::registerHook(int event, QString functionName/*, bool bypass*/)
{
    EventData ed(functionName, false);
    eventsMap->registerEvent(event, ed);
}


bool Qserver::runEventHooks(int event, QJSValueList &capsule)
{
    bool bypass = false;
    for(EventData ed : eventsMap->getEventData(event)){
        if(js.globalObject().hasProperty(ed.jsFunctionName)){
            capsule << js.toScriptValue<EventData>(ed);  //so script can edit the bypass value
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
            ed.bypass = (js.fromScriptValue<EventData>(capsule.last())).bypass;
        }
        bypass |= ed.bypass;
    }
    //js.collectGarbage();
    return bypass;
}

void Qserver::conout(int type, QString s){ ::conoutf(type, s.toLocal8Bit().data());}
void Qserver::sendservmsg(QString s){  server::sendservmsg(s.toLocal8Bit().data()); }

void Qserver::sendplayermsg(int cn, QString msg)
{
    server::clientinfo* ci = (server::clientinfo*)(::getclientinfo(cn));
    string s;
    strcpy(s, msg.toLocal8Bit().data());

    vector<uchar> playermsg;
    putuint(playermsg, N_SERVMSG);
    sendstring(s, playermsg);

    packetbuf p(MAXTRANS, ENET_PACKET_FLAG_RELIABLE);
    putuint(p, N_CLIENT);
    putint(p, ci->clientnum);
    putint(p, playermsg.length());
    p.put(playermsg.getbuf(), playermsg.length());
    sendpacket(ci->clientnum, 1, p.finalize(), -1);
}

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

int Qserver::getnumclients(){ return ::getnumclients();}

void Qserver::forcespectator(int cn)
{
    server::clientinfo* ci = (server::clientinfo*)(::getclientinfo(cn));
    server::forcespectator(ci);
}

void Qserver::rename(int cn, QString newname)
{
    server::clientinfo* ci = (server::clientinfo*)(::getclientinfo(cn));
    string s;
    strcpy(s, newname.toLocal8Bit().data());

    putuint(ci->messages, N_SWITCHNAME);
    sendstring(s, ci->messages);

    vector<uchar> renamemsg;
    putuint(renamemsg, N_SWITCHNAME);
    sendstring(s, renamemsg);

    packetbuf p(MAXTRANS, ENET_PACKET_FLAG_RELIABLE);
    putuint(p, N_CLIENT);
    putint(p, ci->clientnum);
    putint(p, renamemsg.length());
    p.put(renamemsg.getbuf(), renamemsg.length());
    sendpacket(ci->clientnum, 1, p.finalize(), -1);
    strcpy( ci->name, s);
}

void Qserver::playsound(int cn, int sound)
{
    server::clientinfo* ci = (server::clientinfo*)(::getclientinfo(cn));

    vector<uchar> smsg;
    putuint(smsg, N_SOUND);
    putint(smsg, sound);

    packetbuf p(MAXTRANS, ENET_PACKET_FLAG_RELIABLE);
    putuint(p, N_CLIENT);
    putint(p, ci->clientnum);
    putint(p, smsg.length());
    p.put(smsg.getbuf(), smsg.length());
    sendpacket(ci->clientnum, 1, p.finalize(), -1);
}

void Qserver::reqauth(int cn, QString domain)
{
    server::clientinfo* ci = (server::clientinfo*)(::getclientinfo(cn));
    string s;
    strcpy(s, domain.toLocal8Bit().data());

    vector<uchar> reqmsg;
    putuint(reqmsg, N_REQAUTH);
    sendstring(s, reqmsg);

    packetbuf p(MAXTRANS, ENET_PACKET_FLAG_RELIABLE);
    putuint(p, N_CLIENT);
    putint(p, ci->clientnum);
    putint(p, reqmsg.length());
    p.put(reqmsg.getbuf(), reqmsg.length());
    sendpacket(ci->clientnum, 1, p.finalize(), -1);
}

void Qserver::adduser(QString name, QString domain, QString pubkey, QString privilege)
{
    server::adduser(name.toLocal8Bit().data(), domain.toLocal8Bit().data(), pubkey.toLocal8Bit().data(), privilege.toLocal8Bit().data());
}

void Qserver::clearusers() {server::clearusers();}

void Qserver::quit() {::quit();}

void Qserver::maxclients(int n){::maxclients = n;}

QJSValue Qserver::getclientinfo(int i){ return js.newQObject((server::clientinfo*)(::getclientinfo(i))); }

QString Qserver::serverauth() { return QString::fromLocal8Bit(server::serverauth);}


