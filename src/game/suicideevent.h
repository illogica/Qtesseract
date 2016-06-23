#ifndef SUICIDEEVENT_H
#define SUICIDEEVENT_H

#include "gameevent.h"
#include "clientinfo.h"

namespace server {
    class suicideevent : public gameevent
    {
    public:
        void process(clientinfo *ci);
    };

}

#endif // SUICIDEEVENT_H
