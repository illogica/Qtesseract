#ifndef QSERVER_H
#define QSERVER_H

#include <QObject>
#include <QString>
#include <QJSEngine>
#include "jsloader.h"
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
}


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

    QJSEngine js;
    QJSValue srv;
    int testInt = 5;

signals:

public slots:

    //slot called when the JSLoader has detected a change in file system
    void reloadJs(QStringList &sources);

    void testPrint();
    void testSprint(const QString s);

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
};

#endif // QSERVER_H
