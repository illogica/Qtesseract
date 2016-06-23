#include "animinterpinfo.h"

animinterpinfo::animinterpinfo() : lastswitch(-1), lastmodel(0)
{

}

void animinterpinfo::reset()
{
    lastswitch = -1;
}
