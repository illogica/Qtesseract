#include "gameent.h"
#include "vec.h"
//#include "enums.h"
#include "game.h"

gameent::gameent() : weight(100), clientnum(-1), privilege(PRIV_NONE), lastupdate(0), plag(0), ping(0), lifesequence(0), respawned(-1), suicided(-1), lastpain(0), frags(0), flags(0), deaths(0), totaldamage(0), totalshots(0), edit(NULL), smoothmillis(-1), team(0), playermodel(-1), playercolor(0), ai(NULL), ownernum(-1), muzzle(-1, -1, -1)
{
    name[0] = info[0] = 0;
    respawn();
}

gameent::~gameent()
{
    freeeditinfo(edit);
    if(ai) delete ai;
}

void gameent::hitpush(int damage, const vec &dir, gameent *actor, int atk)
{
    vec push(dir);
    push.mul((actor==this && attacks[atk].exprad ? EXP_SELFPUSH : 1.0f)*attacks[atk].hitpush*damage/weight);
    vel.add(push);
}

void gameent::respawn()
{
    dynent::reset();
    gamestate::respawn();
    respawned = suicided = -1;
    lastaction = 0;
    lastattack = -1;
    attacking = ACT_IDLE;
    lasttaunt = 0;
    lastpickup = -1;
    lastpickupmillis = 0;
    flagpickup = 0;
    lastnode = -1;
}

void gameent::startgame()
{
    frags = flags = deaths = 0;
    totaldamage = totalshots = 0;
    maxhealth = 1;
    lifesequence = -1;
    respawned = suicided = -2;
}

