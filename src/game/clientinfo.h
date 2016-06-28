#ifndef CLIENTINFO_H
#define CLIENTINFO_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QJSValue>
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
        //Q_GADGET
        Q_OBJECT
        Q_PROPERTY(int clientnum MEMBER clientnum)
        Q_PROPERTY(int ownernum MEMBER ownernum)
        Q_PROPERTY(int connectmillis MEMBER connectmillis)
        Q_PROPERTY(int sessionid MEMBER sessionid)
        Q_PROPERTY(int overflow MEMBER overflow)
        Q_PROPERTY(QString name READ _name WRITE _setName)
        //Q_PROPERTY(QString mapvote READ _mapvote WRITE _setMapvote)
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
        //Q_PROPERTY(QJSValue state READ _state WRITE _setState)
        //Q_PROPERTY(QJSValue position READ _position WRITE _setPosition)
        //Q_PROPERTY(int wslen MEMBER wslen)
        //Q_PROPERTY(QJSValue bots READ _bots WRITE _setBots)
        //Q_PROPERTY(QJSValue events READ _events WRITE _setEvents)
        Q_PROPERTY(int ping MEMBER ping)
        Q_PROPERTY(int aireinit MEMBER aireinit)
        Q_PROPERTY(QString clientmap READ _clientmap WRITE _setClientmap)
        Q_PROPERTY(int mapcrc MEMBER mapcrc)
        Q_PROPERTY(bool warned MEMBER warned)
        Q_PROPERTY(bool gameclip MEMBER gameclip)
        Q_PROPERTY(int lastclipboard MEMBER lastclipboard)
        Q_PROPERTY(int needclipboard MEMBER needclipboard)
        Q_PROPERTY(int connectauth MEMBER connectauth)
        //Q_PROPERTY(uint authreq MEMBER authreq)
        //Q_PROPERTY(uchar wsdata READ _wsdata WRITE _setWsdata)
        Q_PROPERTY(QString authname READ _authname WRITE _setAuthname)
        Q_PROPERTY(QString authdesc READ _authdesc WRITE _setAuthdesc)
        Q_PROPERTY(int authkickvictim MEMBER authkickvictim)
        Q_PROPERTY(QString authkickreason READ _authkickreason WRITE _setAuthkickreason)

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
        //QJSValue _state();
        //void _setState(const QJSValue &s);
        QString _clientmap();
        void _setClientmap(const QString &s);
        QString _authname();
        void _setAuthname(const QString &s);
        QString _authdesc();
        void _setAuthdesc(const QString &s);
        QString _authkickreason();
        void _setAuthkickreason(const QString &s);
        //QJSValue _position();
        //void _setPosition(const QJSValue &l);
        //uchar _wsdata();
        //void _setWsdata(uchar data);
        //QJSValue _bots();
        //void _setBots(const QJSValue &l);
        //QJSValue _events();
        //void _setEvents(const QJSValue &l);*/

    public:
        clientinfo(QObject *parent = 0);
        ~clientinfo();
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
        uchar *wsdata;  //TODO: js bindings??
        int wslen;
        vector<clientinfo *> bots;
        int ping, aireinit;
        string clientmap;
        int mapcrc;
        bool warned, gameclip;
        ENetPacket *getdemo, *getmap, *clipboard; // TODO: js bindings
        int lastclipboard, needclipboard;
        int connectauth;
        uint authreq;
        string authname, authdesc;
        void *authchallenge; // TODO: js bindings
        int authkickvictim;
        char *authkickreason;

        QJSEngine *engine;

    };
}
Q_DECLARE_METATYPE(server::clientinfo*)

#endif // CLIENTINFO_H
