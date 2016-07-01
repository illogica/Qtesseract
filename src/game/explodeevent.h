#ifndef EXPLODEEVENT_H
#define EXPLODEEVENT_H

#include <QObject>
#include "timedevent.h"
#include "clientinfo.h"
#include "hitinfo.h"

template <class T> struct vector;

namespace server {

    class explodeevent : public timedevent
    {
        Q_OBJECT
        Q_PROPERTY(int id MEMBER id)
        Q_PROPERTY(int atk MEMBER atk)

    public:
        explodeevent(QObject *parent = 0){}
        ~explodeevent(){}

        int id, atk;
        vector<hitinfo> hits;

    public slots:
        bool keepable() const { return true; }
        void process(clientinfo *ci);
    };

}

#endif // EXPLODEEVENT_H
