#ifndef ANIMINTERPINFO_H
#define ANIMINTERPINFO_H

#include "animinfo.h"

class animinterpinfo // used for animation blending of animated characters
{
public:
    animinterpinfo();

    void reset();

    animinfo prev, cur;
    int lastswitch;
    void *lastmodel;
};

#endif // ANIMINTERPINFO_H
