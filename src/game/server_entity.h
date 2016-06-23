#ifndef SERVER_ENTITY_H
#define SERVER_ENTITY_H

namespace server {

    static const int DEATHMILLIS = 300;

    class server_entity            // server side version of "entity" type
    {
    public:
        int type;
        int spawntime;
        bool spawned;
    };

}

#endif // SERVER_ENTITY_H
