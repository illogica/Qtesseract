#ifndef EXPLODEEVENT_H
#define EXPLODEEVENT_H

#include "timedevent.h"
#include "clientinfo.h"
#include "hitinfo.h"

template <class T> struct vector;

namespace server {

    class explodeevent : public timedevent
    {
    public:
        int id, atk;
        vector<hitinfo> hits;

        bool keepable() const { return true; }

        void process(clientinfo *ci);
    };

}

#endif // EXPLODEEVENT_H
