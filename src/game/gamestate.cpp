#include "gamestate.h"
#include "game.h"

gamestate::gamestate() : maxhealth(1), aitype(AI_NONE), skill(0)
{

}

bool gamestate::canpickup(int type)
{
    return validitem(type);
}

void gamestate::pickup(int type)
{
}

void gamestate::respawn()
{
    health = maxhealth;
    gunselect = GUN_RAIL;
    gunwait = 0;
    loopi(NUMGUNS) ammo[i] = 0;
}

void gamestate::spawnstate(int gamemode)
{
    if(m_rail)
    {
        gunselect = GUN_RAIL;
        ammo[GUN_RAIL] = 1;
    }
    else if(m_pulse)
    {
        gunselect = GUN_PULSE;
        ammo[GUN_PULSE] = 1;
    }
    else if(m_edit)
    {
        gunselect = GUN_RAIL;
        loopi(NUMGUNS) ammo[i] = 1;
    }
}

// just subtract damage here, can set death, etc. later in code calling this
int gamestate::dodamage(int damage)
{
    health -= damage;
    return damage;
}

int gamestate::hasammo(int gun, int exclude)
{
    return validgun(gun) && gun != exclude && ammo[gun] > 0;
}
