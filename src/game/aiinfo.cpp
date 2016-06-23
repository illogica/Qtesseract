#include "aiinfo.h"
#include "loops.h"
#include "enums.h"
#include "enumsai.h"

namespace ai {

    aiinfo::aiinfo()
    {
        clearsetup();
        reset();
        loopk(3) views[k] = 0.f;
    }

    aiinfo::~aiinfo() {}

    void aiinfo::clearsetup()
    {
        weappref = GUN_RAIL;
        spot = target = vec(0, 0, 0);
        lastaction = lasthunt = lastcheck = enemyseen = enemymillis = blocktime = huntseq = blockseq = targtime = targseq = lastaimrnd = 0;
        lastrun = jumpseed = lastmillis;
        jumprand = lastmillis+5000;
        targnode = targlast = enemy = -1;
    }

    void aiinfo::clear(bool prev)
    {
        if(prev) memset(prevnodes, -1, sizeof(prevnodes));
        route.setsize(0);
    }

    void aiinfo::wipe(bool prev)
    {
        clear(prev);
        state.setsize(0);
        addstate(AI_S_WAIT);
        trywipe = false;
    }

    void aiinfo::clean(bool tryit)
    {
        if(!tryit) becareful = dontmove = false;
        targyaw = rnd(360);
        targpitch = 0.f;
        tryreset = tryit;
    }

    void aiinfo::reset(bool tryit) { wipe(); clean(tryit); }

    bool aiinfo::hasprevnode(int n) const
    {
        loopi(NUMPREVNODES) if(prevnodes[i] == n) return true;
        return false;
    }

    void aiinfo::addprevnode(int n)
    {
        if(prevnodes[0] != n)
        {
            memmove(&prevnodes[1], prevnodes, sizeof(prevnodes) - sizeof(prevnodes[0]));
            prevnodes[0] = n;
        }
    }

    aistate &aiinfo::addstate(int t, int r, int v)
    {
        return state.add(aistate(lastmillis, t, r, v));
    }

    void aiinfo::removestate(int index)
    {
        if(index < 0) state.pop();
        else if(state.inrange(index)) state.remove(index);
        if(!state.length()) addstate(AI_S_WAIT);
    }

    aistate &aiinfo::getstate(int idx)
    {
        if(state.inrange(idx)) return state[idx];
        return state.last();
    }

    aistate &aiinfo::switchstate(aistate &b, int t, int r, int v)
    {
        if((b.type == t && b.targtype == r) || (b.type == AI_S_INTEREST && b.targtype == AI_T_NODE))
        {
            b.millis = lastmillis;
            b.target = v;
            b.reset();
            return b;
        }
        return addstate(t, r, v);
    }

}
