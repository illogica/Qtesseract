#ifndef GAMEENT_H
#define GAMEENT_H

#include "dynent.h"
#include "gamestate.h"
#include "aiinfo.h"
#include "typedefs.h"

struct editinfo;
class vec;

extern void freeeditinfo(editinfo *&e);

class gameent : public dynent, public gamestate
{
    Q_GADGET

public:
    gameent();
    ~gameent();

    void hitpush(int damage, const vec &dir, gameent *actor, int atk);
    void respawn();
    void startgame();

    int weight;                         // affects the effectiveness of hitpush
    int clientnum, privilege, lastupdate, plag, ping;
    int lifesequence;                   // sequence id for each respawn, used in damage test
    int respawned, suicided;
    int lastpain;
    int lastaction, lastattack;
    int attacking;
    int lasttaunt;
    int lastpickup, lastpickupmillis, flagpickup;
    int frags, flags, deaths, totaldamage, totalshots;
    editinfo *edit;
    float deltayaw, deltapitch, deltaroll, newyaw, newpitch, newroll;
    int smoothmillis;

    string name, info;
    int team, playermodel, playercolor;
    ai::aiinfo *ai;
    int ownernum, lastnode;

    vec muzzle;
};

Q_DECLARE_METATYPE(gameent)

#endif // GAMEENT_H
