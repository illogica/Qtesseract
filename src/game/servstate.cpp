#include "servstate.h"
#include "ents.h"

#include "server_entity.h"

#include "geom.h"

namespace server{

    servstate::servstate() : state(CS_DEAD), editstate(CS_DEAD), lifesequence(0)
    {}

    servstate::~servstate()  {}

    bool servstate::isalive(int gamemillis)
    {
        return state==CS_ALIVE || (state==CS_DEAD && gamemillis - lastdeath <= DEATHMILLIS);
    }

    bool servstate::waitexpired(int gamemillis)
    {
        return gamemillis - lastshot >= gunwait;
    }

    void servstate::reset()
    {
        if(state!=CS_SPECTATOR) state = editstate = CS_DEAD;
        maxhealth = 1;
        projs.reset();

        timeplayed = 0;
        effectiveness = 0;
        frags = flags = deaths = teamkills = shotdamage = damage = 0;

        lastdeath = 0;

        respawn();
    }

    void servstate::respawn()
    {
        gamestate::respawn();
        o = vec(-1e10f, -1e10f, -1e10f);
        deadflush = 0;
        lastspawn = -1;
        lastshot = 0;
    }

    void servstate::reassign()
    {
        respawn();
        projs.reset();
    }
}
