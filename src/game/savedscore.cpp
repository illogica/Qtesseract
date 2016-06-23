#include "savedscore.h"

namespace server{

    savedscore::savedscore()
    {
    }

    void savedscore::save(servstate &gs)
    {
        frags = gs.frags;
        flags = gs.flags;
        deaths = gs.deaths;
        teamkills = gs.teamkills;
        shotdamage = gs.shotdamage;
        damage = gs.damage;
        timeplayed = gs.timeplayed;
        effectiveness = gs.effectiveness;
    }

    void savedscore::restore(servstate &gs)
    {
        gs.frags = frags;
        gs.flags = flags;
        gs.deaths = deaths;
        gs.teamkills = teamkills;
        gs.shotdamage = shotdamage;
        gs.damage = damage;
        gs.timeplayed = timeplayed;
        gs.effectiveness = effectiveness;
    }

}
