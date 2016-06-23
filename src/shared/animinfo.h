#ifndef ANIMINFO_H
#define ANIMINFO_H


class animinfo // description of a character's animation
{
public:
    animinfo();

    int anim, frame, range, basetime;
    float speed;
    unsigned int varseed;

    bool operator==(const animinfo &o) const;
    bool operator!=(const animinfo &o) const;
};

#endif // ANIMINFO_H
