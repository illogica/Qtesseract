#ifndef EVENTDATA_H
#define EVENTDATA_H

#include <QString>

/**
 * @brief The EventData struct
 * A simple data structure to store network events registered by javascript
 */
struct EventData
{
    EventData(QString n, bool b) : jsFunctionName(n), bypass(b){}
    QString jsFunctionName;
    bool bypass;
};


#endif // EVENTDATA_H
