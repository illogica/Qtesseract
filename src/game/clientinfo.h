#ifndef CLIENTINFO_H
#define CLIENTINFO_H

#include <QObject>
#include <QString>
#include "vec.h"
#include "vector.h"
#include "servstate.h"
#include "gameevent.h"
#include "enet/enet.h"
#include "typedefs.h"

extern ENetPeer *getclientpeer(int i);
extern void freechallenge(void *answer);

namespace server{

    extern int gamemillis, nextexceeded;

    class clientinfo : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(int clientnum MEMBER clientnum)
        Q_PROPERTY(int ownernum MEMBER ownernum)
        Q_PROPERTY(int connectmillis MEMBER connectmillis)
        Q_PROPERTY(int sessionid MEMBER sessionid)
        Q_PROPERTY(int overflow MEMBER overflow)
        Q_PROPERTY(QString name READ _name WRITE _setName)
        Q_PROPERTY(QString mapvote READ _mapvote WRITE _setMapvote)
        Q_PROPERTY(int team MEMBER team)
        Q_PROPERTY(int playermodel MEMBER playermodel)
        Q_PROPERTY(int playercolor MEMBER playercolor)
        Q_PROPERTY(int modevote MEMBER modevote)
        Q_PROPERTY(int privilege MEMBER privilege)
        Q_PROPERTY(bool connected MEMBER connected)
        Q_PROPERTY(bool local MEMBER local)
        Q_PROPERTY(bool timesync MEMBER timesync)
        Q_PROPERTY(int gameoffset MEMBER gameoffset)
        Q_PROPERTY(int lastevent MEMBER lastevent)
        Q_PROPERTY(int pushed MEMBER pushed)
        Q_PROPERTY(int exceeded MEMBER exceeded)

    public slots:

        void addevent(gameevent *e);
        int calcpushrange();
        bool checkpushed(int millis, int range);
        void scheduleexceeded();
        void setexceeded();
        void setpushed();
        bool checkexceeded();
        void mapchange();
        void reassign();
        void cleanclipboard(bool fullclean = true);
        void cleanauthkick();
        void cleanauth(bool full = true);
        void reset();
        int geteventmillis(int servmillis, int clientmillis);

        QString _name();
        void _setName(const QString &s);
        QString _mapvote();
        void _setMapvote(const QString &s);

    public:
        clientinfo(QObject *parent = 0);
        ~clientinfo();
        enum
        {
            PUSHMILLIS = 3000
        };

        int clientnum, ownernum, connectmillis, sessionid, overflow;
        string name, mapvote;
        //QString name, mapvote;
        int team, playermodel, playercolor;
        int modevote;
        int privilege;
        bool connected, local, timesync;
        int gameoffset, lastevent, pushed, exceeded;
        servstate state;
        vector<gameevent *> events;
        vector<uchar> position, messages;
        uchar *wsdata;
        int wslen;
        vector<clientinfo *> bots;
        int ping, aireinit;
        string clientmap;
        int mapcrc;
        bool warned, gameclip;
        ENetPacket *getdemo, *getmap, *clipboard;
        int lastclipboard, needclipboard;
        int connectauth;
        uint authreq;
        string authname, authdesc;
        void *authchallenge;
        int authkickvictim;
        char *authkickreason;
    };

}

#endif // CLIENTINFO_H
