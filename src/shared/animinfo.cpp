#include "animinfo.h"

#include "ents.h"

animinfo::animinfo() : anim(0), frame(0), range(0), basetime(0), speed(100.0f), varseed(0)
{

}

bool animinfo::operator==(const animinfo &o) const
{
    return frame==o.frame && range==o.range && (anim&(ANIM_SETTIME|ANIM_DIR))==(o.anim&(ANIM_SETTIME|ANIM_DIR)) && (anim&ANIM_SETTIME || basetime==o.basetime) && speed==o.speed;
}

bool animinfo::operator!=(const animinfo &o) const
{
    return frame!=o.frame || range!=o.range || (anim&(ANIM_SETTIME|ANIM_DIR))!=(o.anim&(ANIM_SETTIME|ANIM_DIR)) || (!(anim&ANIM_SETTIME) && basetime!=o.basetime) || speed!=o.speed;
}
