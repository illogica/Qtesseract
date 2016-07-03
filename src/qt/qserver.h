#ifndef QSERVER_H
#define QSERVER_H

#include <QObject>
#include <QString>
#include <QJSEngine>
#include <QHash>
#include <QList>
#include <game.h>
#include "eventdata.h"
#include "jsloader.h"
#include "servereventsmap.h"
#include "vec.h"
#include "typedefs.h"
#include "defs.h"
#include "ban.h"
#include "vector.h"
#include "clientinfo.h"
#include "client.h"
#include "enums.h"
#include "databuf.h"
#include "packetbuf.h"

namespace server{

    //externs
    extern int gamemillis, nextexceeded;
    extern int mastermode, mastermask;
    extern bool notgotitems;        // true when map has changed and waiting for clients to send item
    extern int gamemode;
    extern int gamemillis;
    extern int gamelimit;
    extern int nextexceeded;
    extern int gamespeed;
    extern bool gamepaused;
    extern bool shouldstep;
    extern string smapname;
    extern vector<uint> allowedips;
    extern vector<ban> bannedips;

    extern void sendservmsg(const char *s);
    extern int allowconnect(clientinfo *ci, const char *pwd);
    extern void connected(clientinfo *ci);
    extern void clientdisconnect(int n); //use very carefully, 4 hrs to solve a segfault.
    extern void forcespectator(clientinfo *ci);
    extern clientinfo *getinfo(int n);
    extern void adduser(char *name, char *desc, char *pubkey, char *priv);
    extern void clearusers();

    extern char* serverauth;
}

// engine/server.cpp
extern vector<client *> clients;
extern void disconnect_client(int n, int reason);
extern void delclient(client *c);
extern int getnumclients();
extern void *getclientinfo(int i);
extern bool hasnonlocalclients();
extern ENetPacket *sendf(int cn, int chan, const char *format, ...);
extern void sendpacket(int n, int chan, ENetPacket *packet, int exclude);

extern int maxclients;

void logoutf(const char *fmt, ...);
extern void conoutf(int type, const char *fmt, ...);

// shared/tools.cpp
extern void putint(ucharbuf &p, int n);
extern void putint(packetbuf &p, int n);
extern void putint(vector<uchar> &p, int n);
extern void putuint(ucharbuf &p, int n);
extern void putuint(packetbuf &p, int n);
extern void putuint(vector<uchar> &p, int n);
extern void sendstring(const char *t, ucharbuf &p);
extern void sendstring(const char *t, packetbuf &p);
extern void sendstring(const char *t, vector<uchar> &p);

// engine/main.cpp
extern void quit();


/**
 * @brief The Qserver class
 *
 * note to self: QString uses COW, so it's efficient even without passing it by reference.
 */

class Qserver : public QObject
{
    Q_OBJECT

public:
    explicit Qserver(QObject *parent = 0);
    ~Qserver();

    bool hasEvent(int event);
    bool runEventHooks(int event, QJSValueList &capsule);

    QJSEngine js;
    QJSValue srv;

signals:

public slots:

    //slot called when the JSLoader has detected a change in file system
    void reloadJs(QStringList &sources);

    //called from js code to register event hooks
    void registerHook(int event, QString functionName);

    //server to javascript api
    void conout(int type, QString s);
    void sendservmsg(QString s);
    void sendplayermsg(int cn, QString msg);
    void logoutf(QString s);
    int allowconnect(QJSValue ci, QString pwd);
    void disconnect_client(int clientnum, int disconnect_reason);
    void connected(QJSValue ci);
    bool hasnonlocalclients();
    int getnumclients();
    void forcespectator(int cn);
    void rename(int cn, QString newname);
    void playsound(int cn, int sound);
    void reqauth(int cn, QString domain);
    void adduser(QString name, QString domain, QString pubkey, QString privilege);
    void clearusers();
    void quit();
    void maxclients(int n);
    QJSValue getclientinfo(int i);
    bool isCtf();
    bool isTeammode();
    bool isOvertime();
    bool isRail();
    bool isPulse();
    bool isDemo();
    bool isLobby();
    bool isTimed();
    bool isBotmode();

    //SVAR
    QString serverauth();


private:
    JSLoader* jsLoader;
    ServerEventsMap *eventsMap;
};

#endif // QSERVER_H
