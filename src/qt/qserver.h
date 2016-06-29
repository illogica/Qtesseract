#ifndef QSERVER_H
#define QSERVER_H

#include <QObject>
#include <QString>
#include <QJSEngine>
#include <QHash>
#include <QList>
#include "eventdata.h"
#include "jsloader.h"
#include "servereventsmap.h"
#include "vec.h"
#include "typedefs.h"
#include "ban.h"
#include "vector.h"
#include "clientinfo.h"
#include "client.h"

namespace server{

    //externs
    extern int gamemillis, nextexceeded;
    extern int mastermode, mastermask;
    extern string smapname;
    extern vector<uint> allowedips;
    extern vector<ban> bannedips;

    extern void sendservmsg(const char *s);
    extern int allowconnect(clientinfo *ci, const char *pwd);
    extern void connected(clientinfo *ci);
    extern void clientdisconnect(int n);
    extern clientinfo *getinfo(int n);

    extern char* serverauth;
}

// engine/server.cpp
extern vector<client *> clients;
extern void disconnect_client(int n, int reason);
extern void delclient(client *c);
extern int getnumclients();
extern void *getclientinfo(int i);
extern bool hasnonlocalclients();

void logoutf(const char *fmt, ...);
extern void conoutf(int type, const char *fmt, ...);

/**
 * @brief The Qserver class
 *
 * note to self: QString uses COW, so it's efficient even without passing it by reference.
 */

class Qserver : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int qtestInt MEMBER testInt)
public:
    explicit Qserver(QObject *parent = 0);
    ~Qserver();

    bool hasEvent(int event);
    bool runEventHooks(int event, QJSValueList &capsule);

    QJSEngine js;
    QJSValue srv;
    int testInt = 5;

signals:

public slots:

    //slot called when the JSLoader has detected a change in file system
    void reloadJs(QStringList &sources);

    //called from js code to register event hooks
    void registerHook(int event, QString functionName, bool bypass);

    //server to javascript api
    void conout(int type, QString s);
    void sendservmsg(QString s);
    void logoutf(QString s);
    int allowconnect(QJSValue ci, QString pwd);
    void disconnect_client(int clientnum, int disconnect_reason);
    void connected(QJSValue ci);
    bool hasnonlocalclients();
    int getnumclients();
    QJSValue getclientinfo(int i);

    //SVAR
    QString serverauth();


private:
    JSLoader* jsLoader;
    ServerEventsMap *eventsMap;
};

#endif // QSERVER_H
