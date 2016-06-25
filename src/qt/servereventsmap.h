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

    static const int EVENTS_QTY = 150; //0 to 104 is the current number of defined possible network events

private:
    void resetEventsMap();

    QList<EventData> eventsMap[EVENTS_QTY];
};

#endif // SERVEREVENTSMAP_H
