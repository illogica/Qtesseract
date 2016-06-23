#include "physent.h"

#include "ents.h"

physent::physent() : o(0, 0, 0), deltapos(0, 0, 0), newpos(0, 0, 0), yaw(0), pitch(0), roll(0), maxspeed(100),
    radius(4.1f), eyeheight(18), maxheight(18), aboveeye(2), xradius(4.1f), yradius(4.1f), zmargin(0),
    state(CS_ALIVE), editstate(CS_ALIVE), type(ENT_PLAYER),
    collidetype(COLLIDE_ELLIPSE),
    blocked(false)
{ reset(); }

void physent::resetinterp()
{
    newpos = o;
    deltapos = vec(0, 0, 0);
}

void physent::reset()
{
    inwater = 0;
    timeinair = 0;
    eyeheight = maxheight;
    jumping = false;
    strafe = move = crouching = 0;
    physstate = PHYS_FALL;
    vel = falling = vec(0, 0, 0);
    floor = vec(0, 0, 1);
}

vec physent::feetpos(float offset) const { return vec(o).addz(offset - eyeheight); }
vec physent::headpos(float offset) const { return vec(o).addz(offset); }

bool physent::crouched() const { return fabs(eyeheight - maxheight*CROUCHHEIGHT) < 1e-4f; }
