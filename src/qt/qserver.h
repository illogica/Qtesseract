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

    extern char* serverauth;
}

void logoutf(const char *fmt, ...);
extern void disconnect_client(int n, int reason);

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
    void sendservmsg(QString s);
    void logoutf(QString s);
    int allowconnect(QJSValue ci, QString pwd);
    void disconnect_client(int sender, int disconnect_reason);
    void connected(QJSValue ci);

    QString serverauth();

    //delete this...
    void on_N_CONNECT(server::clientinfo *ci, QString password, QString authdesc, QString authname);
    void on_N_PING(server::clientinfo *ci);
    void on_N_AUTHANS(server::clientinfo *ci, QString desc, QString ans, uint id);
    void on_N_POS(server::clientinfo *ci, server::clientinfo *cp, vec pos, int mag, int dir, vec vel);
    void on_N_TELEPORT(server::clientinfo *ci, server::clientinfo *cp, int teleport, int teledest);
    void on_N_JUMPPAD(server::clientinfo *ci, server::clientinfo *cp, int jumppad);
    void on_N_FROMAI(server::clientinfo *ci, server::clientinfo *cq);
    void on_N_EDITMODE(server::clientinfo *ci, int val);
    void on_N_MAPCRC(server::clientinfo *ci, int crc, QString mapname);
    void on_N_CHECKMAPS(server::clientinfo *ci);

private:
    JSLoader* jsLoader;
    ServerEventsMap *eventsMap;
};

#endif // QSERVER_H
