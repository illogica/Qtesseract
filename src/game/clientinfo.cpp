#include "clientinfo.h"
#include <limits.h>
#include "qstringutils.h"
#include "ents.h"
#include "tools.h"


namespace server{

    clientinfo::clientinfo(QObject *parent) :  QObject(parent), getdemo(NULL), getmap(NULL), clipboard(NULL), authchallenge(NULL), authkickreason(NULL)
    {
        reset();
    }
    clientinfo::~clientinfo()
    {
         events.deletecontents();
         cleanclipboard();
         cleanauth();
    }

    void clientinfo::addevent(gameevent *e)
    {
        if(state.state==CS_SPECTATOR || events.length()>100) delete e;
        else events.add(e);
    }

    int clientinfo::calcpushrange()
    {
        ENetPeer *peer = getclientpeer(ownernum);
        return PUSHMILLIS + (peer ? peer->roundTripTime + peer->roundTripTimeVariance : ENET_PEER_DEFAULT_ROUND_TRIP_TIME);
    }

    bool clientinfo::checkpushed(int millis, int range)
    {
        return millis >= pushed - range && millis <= pushed + range;
    }

    void clientinfo::scheduleexceeded()
    {
        if(state.state!=CS_ALIVE || !exceeded) return;
        int range = calcpushrange();
        if(!nextexceeded || exceeded + range < nextexceeded) nextexceeded = exceeded + range;
    }

    void clientinfo::setexceeded()
    {
        if(state.state==CS_ALIVE && !exceeded && !checkpushed(gamemillis, calcpushrange())) exceeded = gamemillis;
        scheduleexceeded();
    }

    void clientinfo::setpushed()
    {
        pushed = max(pushed, gamemillis);
        if(exceeded && checkpushed(exceeded, calcpushrange())) exceeded = 0;
    }

    bool clientinfo::checkexceeded()
    {
        return state.state==CS_ALIVE && exceeded && gamemillis > exceeded + calcpushrange();
    }

    void clientinfo::mapchange()
    {
        mapvote[0] = 0;
        modevote = INT_MAX;
        state.reset();
        events.deletecontents();
        overflow = 0;
        timesync = false;
        lastevent = 0;
        exceeded = 0;
        pushed = 0;
        clientmap[0] = '\0';
        mapcrc = 0;
        warned = false;
        gameclip = false;
    }

    void clientinfo::reassign()
    {
        state.reassign();
        events.deletecontents();
        timesync = false;
        lastevent = 0;
    }

    void clientinfo::cleanclipboard(bool fullclean)
    {
        if(clipboard) { if(--clipboard->referenceCount <= 0) enet_packet_destroy(clipboard); clipboard = NULL; }
        if(fullclean) lastclipboard = 0;
    }

    void clientinfo::cleanauthkick()
    {
        authkickvictim = -1;
        DELETEA(authkickreason);
    }

    void clientinfo::cleanauth(bool full)
    {
        authreq = 0;
        if(authchallenge) { freechallenge(authchallenge); authchallenge = NULL; }
        if(full) cleanauthkick();
    }

    void clientinfo::reset()
    {
        name[0] = 0;
        team = 0;
        playermodel = -1;
        playercolor = 0;
        privilege = PRIV_NONE;
        connected = local = false;
        connectauth = 0;
        position.setsize(0);
        messages.setsize(0);
        ping = 0;
        aireinit = 0;
        needclipboard = 0;
        cleanclipboard();
        cleanauth();
        mapchange();
    }

    int clientinfo::geteventmillis(int servmillis, int clientmillis)
    {
        if(!timesync || (events.empty() && state.waitexpired(servmillis)))
        {
            timesync = true;
            gameoffset = servmillis - clientmillis;
            return servmillis;
        }
        else return gameoffset + clientmillis;
    }

    QString clientinfo::_name()
    {
        return QString(name);
    }

    void clientinfo::_setName(const QString &s)
    {
        char* result = qstrtochar(s);
        strcpy(name, result);
    }

    QString clientinfo::_mapvote()
    {
        return QString(mapvote);
    }

    void clientinfo::_setMapvote(const QString &s)
    {
        char* result = qstrtochar(s);
        strcpy(mapvote, result);
    }

}
