#ifndef HITINFO_H
#define HITINFO_H

struct vec;

namespace server {
    class hitinfo
    {
    public:
        int target;
        int lifesequence;
        int rays;
        float dist;
        vec dir;
    };
}

#endif // HITINFO_H
