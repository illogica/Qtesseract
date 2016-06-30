#ifndef SUICIDEEVENT_H
#define SUICIDEEVENT_H

#include "gameevent.h"
#include "clientinfo.h"

namespace server {
    class suicideevent : public gameevent
    {
        Q_OBJECT
    public:
        suicideevent(QObject *parent = 0){}
        ~suicideevent(){}

    public slots:
        void process(clientinfo *ci);
    };

}

#endif // SUICIDEEVENT_H
