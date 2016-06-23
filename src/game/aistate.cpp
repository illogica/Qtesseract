#include "aistate.h"

namespace ai{

    aistate::aistate(){

    }

    aistate::aistate(int m, int t, int r, int v) : type(t), millis(m), targtype(r), target(v)
    {
        reset();
    }

    aistate::~aistate() {}

    void aistate::reset()
    {
        idle = 0;
        override = false;
    }
}


