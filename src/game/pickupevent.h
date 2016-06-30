#ifndef PICKUPEVENT_H
#define PICKUPEVENT_H

#include "gameevent.h"
#include "clientinfo.h"

namespace server{

    class pickupevent : public gameevent
    {
        Q_OBJECT
        Q_PROPERTY(int ent MEMBER ent)
    public:
        pickupevent(QObject *parent = 0){}
        ~pickupevent(){}

        int ent;

    public slots:
        void process(clientinfo *ci);
    };
}

#endif // PICKUPEVENT_H
