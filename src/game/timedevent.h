#ifndef TIMEDEVENT_H
#define TIMEDEVENT_H

#include <QObject>
#include "gameevent.h"

namespace server {

    class timedevent : public gameevent
    {
        Q_OBJECT
        Q_PROPERTY(int millis MEMBER millis)
    public:
        timedevent(QObject *parent = 0){}
        ~timedevent(){}

        int millis;

    public slots:
        bool flush(clientinfo *ci, int fmillis);

    };

}

#endif // TIMEDEVENT_H
