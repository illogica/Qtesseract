#ifndef AIINFO_H
#define AIINFO_H

#include "aistate.h"
#include "vector.h"
#include "vec.h"

extern int lastmillis;  // last time


namespace ai{

    const int NUMPREVNODES = 6;

    class aiinfo
    {

    public:
        aiinfo();
        ~aiinfo();

        void clearsetup();
        void clear(bool prev = false);
        void wipe(bool prev = false);
        void clean(bool tryit = false);
        void reset(bool tryit = false);
        bool hasprevnode(int n) const;
        void addprevnode(int n);
        aistate &addstate(int t, int r = -1, int v = -1);
        void removestate(int index = -1);
        aistate &getstate(int idx = -1);
        aistate &switchstate(aistate &b, int t, int r = -1, int v = -1);

        vector<aistate> state;
        vector<int> route;
        vec target, spot;
        int enemy, enemyseen, enemymillis, weappref, prevnodes[NUMPREVNODES], targnode, targlast, targtime, targseq,
            lastrun, lasthunt, lastaction, lastcheck, jumpseed, jumprand, blocktime, huntseq, blockseq, lastaimrnd;
        float targyaw, targpitch, views[3], aimrnd[3];
        bool dontmove, becareful, tryreset, trywipe;
    };

}

#endif // AIINFO_H
