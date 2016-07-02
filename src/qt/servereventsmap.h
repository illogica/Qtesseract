#ifndef SERVEREVENTSMAP_H
#define SERVEREVENTSMAP_H

#include "eventdata.h"
#include <QList>

class ServerEventsMap
{
public:
    ServerEventsMap();
    void registerEvent(int event, EventData &eventData);
    void clear();
    bool hasEvent(int event);
    QList<EventData> &getEventData(int event);

    //0 to 104 is the current number of defined possible network events
    //from 200 onwoard there are function hooks
    static const int EVENTS_QTY = 300;

private:
    void resetEventsMap();

    QList<EventData> eventsMap[EVENTS_QTY];
};

#endif // SERVEREVENTSMAP_H
