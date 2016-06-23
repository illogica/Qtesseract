#ifndef SERVSTATE_H
#define SERVSTATE_H

#include "gamestate.h"
#include "projectilestate.h"

#include "vec.h"

namespace server{

    class servstate : public gamestate
    {
    public:
        servstate();
        bool isalive(int gamemillis);
        bool waitexpired(int gamemillis);
        void reset();
        void respawn();
        void reassign();

        vec o;
        int state, editstate;
        int lastdeath, deadflush, lastspawn, lifesequence;
        int lastshot;
        projectilestate<8> projs;
        int frags, flags, deaths, teamkills, shotdamage, damage;
        int lasttimeplayed, timeplayed;
        float effectiveness;
    };

}

#endif // SERVSTATE_H
