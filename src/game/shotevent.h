#ifndef SHOTEVENT_H
#define SHOTEVENT_H

#include "hitinfo.h"
#include "clientinfo.h"
#include "timedevent.h"

struct vec;
template <class T> struct vector;

namespace server{

    class shotevent : public timedevent
    {
    public:
        int id, atk;
        vec from, to;
        vector<hitinfo> hits;

        void process(clientinfo *ci);
    };

}

#endif // SHOTEVENT_H
