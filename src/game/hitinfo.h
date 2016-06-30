#ifndef HITINFO_H
#define HITINFO_H

#include <QObject>
#include "vec.h"

namespace server {
    class hitinfo : public QObject
    {
        Q_OBJECT
    public:
        hitinfo(QObject *parent = 0){}
        ~hitinfo(){}
        int target;
        int lifesequence;
        int rays;
        float dist;
        vec dir;
    };
}

#endif // HITINFO_H
