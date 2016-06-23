#ifndef PICKUPEVENT_H
#define PICKUPEVENT_H

#include "gameevent.h"
#include "clientinfo.h"

namespace server{

    class pickupevent : public gameevent
    {
    public:
        int ent;

        void process(clientinfo *ci);
    };
}

#endif // PICKUPEVENT_H
