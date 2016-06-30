#ifndef EVENTDATA_H
#define EVENTDATA_H

#include <QObject>
#include <QString>

/**
 * @brief The EventData struct
 * A simple data structure to store network events registered by javascript
 */
struct EventData
{
    Q_GADGET
    Q_PROPERTY(bool bypass MEMBER bypass)
public:
    EventData(){}
    EventData(QString n, bool b = false) : jsFunctionName(n), bypass(b){}
    QString jsFunctionName;
    bool bypass;
};
Q_DECLARE_METATYPE(EventData)

#endif // EVENTDATA_H
