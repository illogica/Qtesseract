#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>

struct vec;

class gamestate
{
    Q_GADGET
public:
    gamestate();
    //~gamestate();

    bool canpickup(int type);
    void pickup(int type);
    void respawn();
    void spawnstate(int gamemode);
    int dodamage(int damage);
    int hasammo(int gun, int exclude = -1);

    int health, maxhealth;
    int gunselect, gunwait;
    int aitype, skill;
    //int ammo[NUMGUNS];
    int ammo[2];
};

Q_DECLARE_METATYPE(gamestate)

#endif // GAMESTATE_H
