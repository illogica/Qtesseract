#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>

struct vec;

class gamestate
{
    Q_GADGET
    Q_PROPERTY(int health MEMBER health)
    Q_PROPERTY(int maxhealth MEMBER maxhealth)
    Q_PROPERTY(int gunselect MEMBER gunselect)
    Q_PROPERTY(int gunwait MEMBER gunwait)
    Q_PROPERTY(int aitype MEMBER aitype)
    Q_PROPERTY(int skill MEMBER skill)

public:
    gamestate();
    //~gamestate();

    int health, maxhealth;
    int gunselect, gunwait;
    int aitype, skill;
    //int ammo[NUMGUNS];
    int ammo[2];

public slots:
    bool canpickup(int type);
    void pickup(int type);
    void respawn();
    void spawnstate(int gamemode);
    int dodamage(int damage);
    int hasammo(int gun, int exclude = -1);

};

Q_DECLARE_METATYPE(gamestate)

#endif // GAMESTATE_H
