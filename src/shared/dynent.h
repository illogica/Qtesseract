#ifndef DYNENT_H
#define DYNENT_H

#include "physent.h"
#include "animinterpinfo.h"

#define MAXANIMPARTS 3

struct occludequery;
struct ragdolldata;

class dynent : public physent // animated characters, or characters that can receive input
{
    Q_GADGET
public:
    dynent();
    ~dynent();

    void stopmoving();
    void reset();
    vec abovehead();

    bool k_left, k_right, k_up, k_down;         // see input code

    animinterpinfo animinterp[MAXANIMPARTS];
    ragdolldata *ragdoll;
    occludequery *query;
    int lastrendered;
};

Q_DECLARE_METATYPE(dynent)

#endif // DYNENT_H
