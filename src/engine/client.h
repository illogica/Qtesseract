#ifndef CLIENT_H
#define CLIENT_H
#include "enet/enet.h"

struct client                   // server side version of "dynent" type
{
    int type;
    int num;
    ENetPeer *peer;
    string hostname;
    void *info;
};

#endif // CLIENT_H
