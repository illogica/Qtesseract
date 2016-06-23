#ifndef TIMEDEVENT_H
#define TIMEDEVENT_H

#include "gameevent.h"

namespace server {

    class timedevent : public gameevent
    {
    public:
        timedevent(){}
        ~timedevent(){}

        bool flush(clientinfo *ci, int fmillis);
        int millis;
    };

}

#endif // TIMEDEVENT_H
