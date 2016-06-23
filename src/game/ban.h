#ifndef BAN_H
#define BAN_H

namespace server {

class ban
{
    public:
        int time, expire;
        uint ip;
    };
}

#endif // BAN_H
