#ifndef PHYSENT_H
#define PHYSENT_H

#include "vec.h"

class physent
{
    Q_GADGET
public:
    physent();
    ~physent(){}

    void resetinterp();
    void reset();
    vec feetpos(float offset = 0) const;
    vec headpos(float offset = 0) const;
    bool crouched() const;

    vec o, vel, falling;                        // origin, velocity
    vec deltapos, newpos;                       // movement interpolation
    float yaw, pitch, roll;
    float maxspeed;                             // cubes per second, 100 for player
    int timeinair;
    float radius, eyeheight, maxheight, aboveeye; // bounding box size
    float xradius, yradius, zmargin;
    vec floor;                                  // the normal of floor the dynent is on

    int inwater;
    bool jumping;
    char move, strafe, crouching;

    unsigned char physstate;                            // one of PHYS_* above
    unsigned char state, editstate;                     // one of CS_* above
    unsigned char type;                                 // one of ENT_* above
    unsigned char collidetype;                          // one of COLLIDE_* above

    bool blocked;                               // used by physics to signal ai
};

Q_DECLARE_METATYPE(physent)

#endif // PHYSENT_H
