#include "qserver.h"
#include "clientinfo.h"

#include <QDebug>

Qserver::Qserver(QObject *parent) : QObject(parent)
{
    srv = js.newQObject(this);
    js.installExtensions(QJSEngine::ConsoleExtension | QJSEngine::GarbageCollectionExtension);
    js.globalObject().setProperty("server", srv);
    /*js.evaluate("server.testPrint();");
    js.evaluate("server.testSprint('You should see this at the console...');");
    */

    jsLoader = new JSLoader(this);
    connect(jsLoader, SIGNAL(jsSourcesChanged(QStringList&)), this, SLOT(reloadJs(QStringList&)));
    jsLoader->init();

}

void Qserver::reloadJs(QStringList &sources)
{
    eventsMap.clear();

    for( QString s : sources ){
        QJSValue result = js.evaluate(s);
        if (result.isError())
            qDebug()
                    << "Uncaught exception at line"
                    << result.property("lineNumber").toInt()
                    << ":" << result.toString();
    }
}

void Qserver::registerHook(int event, QString functionName, bool bypass)
{
    if(!eventsMap.contains(event)){
        QList<EventData> emptyList;
        eventsMap.insert(event, emptyList);
    }

    //EventData *ed = new EventData(functionName, bypass);
    EventData ed(functionName, bypass);
    eventsMap[event].append(ed);
}

void Qserver::on_N_CONNECT(server::clientinfo *ci, QString password, QString authdesc, QString authname)
{
    qDebug() << "N_CONNECT from " + QString(ci->name);
}

void Qserver::on_N_PING(server::clientinfo *ci)
{
    qDebug() << "Ping request from " + QString(ci->name);
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

void Qserver::testPrint()
{
    qDebug() << "Called from javascript engine - " << testInt;
}

void Qserver::testSprint(const QString s)
{
    qDebug() << "Called from javascript engine - " << s;
}
