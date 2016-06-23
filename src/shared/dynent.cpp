#include "dynent.h"

dynent::dynent() : ragdoll(0), query(0), lastrendered(0)
{
    reset();
}

dynent::~dynent()
{
#ifndef STANDALONE
    extern void cleanragdoll(dynent *d);
    if(ragdoll) cleanragdoll(this);
#endif
}

void dynent::stopmoving()
{
    k_left = k_right = k_up = k_down = jumping = false;
    move = strafe = crouching = 0;
}

void dynent::reset()
{
    physent::reset();
    stopmoving();
    loopi(MAXANIMPARTS) animinterp[i].reset();
}

vec dynent::abovehead()
{
    return vec(o).addz(aboveeye+4);
}
