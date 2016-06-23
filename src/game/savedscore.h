#ifndef SAVEDSCORE_H
#define SAVEDSCORE_H

//#include "tools.h"
#include "servstate.h"

#ifndef MAXSTRLEN
#define MAXSTRLEN 260
typedef char string[MAXSTRLEN];
#endif


namespace server{

    class savedscore
    {
    public:
        savedscore();
        void save(servstate &gs);
        void restore(servstate &gs);

        unsigned int ip;
        string name;
        int frags, flags, deaths, teamkills, shotdamage, damage;
        int timeplayed;
        float effectiveness;
    };

}

#endif // SAVEDSCORE_H
