#ifndef CLIENTINFO_H
#define CLIENTINFO_H

#include <QObject>
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
    public:
        clientinfo(QObject *parent = 0);
        ~clientinfo();

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

        enum
        {
            PUSHMILLIS = 3000
        };

        int clientnum, ownernum, connectmillis, sessionid, overflow;
        string name, mapvote;
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
