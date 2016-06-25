#include "servereventsmap.h"

ServerEventsMap::ServerEventsMap()
{
    for(int i=0; i<EVENTS_QTY; i++) eventsMap[i] = QList<EventData>();
    resetEventsMap();
}

void ServerEventsMap::registerEvent(int event, EventData &eventData)
{
    eventsMap[event].append(eventData);
}

void ServerEventsMap::clear()
{
    resetEventsMap();
}

bool ServerEventsMap::hasEvent(int event)
{
    return !(eventsMap[event].empty());
}

QList<EventData> &ServerEventsMap::getEventData(int event)
{
    return eventsMap[event];
}


void ServerEventsMap::resetEventsMap(){
    for(int i=0; i<EVENTS_QTY; i++){
        eventsMap[i].clear();
    }
}
