#ifndef SERVSTATE_H
#define SERVSTATE_H

#include <QObject>
#include "gamestate.h"
#include "projectilestate.h"

#include "vec.h"

namespace server{

    class servstate : public gamestate
    {
        Q_GADGET
        Q_PROPERTY(int state MEMBER state)
        Q_PROPERTY(int editstate MEMBER editstate)
        Q_PROPERTY(int lastdeath MEMBER lastdeath)
        Q_PROPERTY(int deadflush MEMBER deadflush)
        Q_PROPERTY(int lastspawn MEMBER lastspawn)
        Q_PROPERTY(int lifesequence MEMBER lifesequence)
        Q_PROPERTY(int lastshot MEMBER lastshot)
        Q_PROPERTY(int frags MEMBER frags)
        Q_PROPERTY(int flags MEMBER flags)
        Q_PROPERTY(int deaths MEMBER deaths)
        Q_PROPERTY(int teamkills MEMBER teamkills)
        Q_PROPERTY(int shotdamage MEMBER shotdamage)
        Q_PROPERTY(int damage MEMBER damage)
        Q_PROPERTY(int lasttimeplayed MEMBER lasttimeplayed)
        Q_PROPERTY(int timeplayed MEMBER timeplayed)
        Q_PROPERTY(float effectiveness MEMBER effectiveness)

    public:
        servstate();
        ~servstate();

        vec o; //TODO: js bindings
        int state, editstate;
        int lastdeath, deadflush, lastspawn, lifesequence;
        int lastshot;
        projectilestate<8> projs; //TODO: js bindings
        int frags, flags, deaths, teamkills, shotdamage, damage;
        int lasttimeplayed, timeplayed;
        float effectiveness;

    public slots:
        bool isalive(int gamemillis);
        bool waitexpired(int gamemillis);
        void reset();
        void respawn();
        void reassign();

    };

}
Q_DECLARE_METATYPE(server::servstate)

#endif // SERVSTATE_H

