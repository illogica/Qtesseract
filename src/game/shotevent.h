#ifndef SHOTEVENT_H
#define SHOTEVENT_H

#include <QObject>
#include "hitinfo.h"
#include "clientinfo.h"
#include "timedevent.h"
#include "vec.h"
#include "vector.h"

namespace server{

    class shotevent : public timedevent
    {
        Q_OBJECT
        Q_PROPERTY(int id MEMBER id)
        Q_PROPERTY(int atk MEMBER atk)
        Q_PROPERTY(QVariantList from READ _from WRITE _setFrom)
        Q_PROPERTY(QVariantList to READ _to WRITE _setTo)

    public:
        shotevent(QObject *parent = 0){}
        ~shotevent(){}
        int id, atk;
        vec from, to;
        vector<hitinfo> hits;

    public slots:
        void process(clientinfo *ci);

        QVariantList _from(){
            QVariantList retval;
            retval << from.x << from.y << from.z;
            return retval;
        }

        void _setFrom(const QVariantList &list){
            from.x = list.at(0).toFloat();
            from.y = list.at(1).toFloat();
            from.z = list.at(2).toFloat();
        }

        QVariantList _to(){
            QVariantList retval;
            retval << to.x << to.y << to.z;
            return retval;
        }

        void _setTo(const QVariantList &list){
            to.x = list.at(0).toFloat();
            to.y = list.at(1).toFloat();
            to.z = list.at(2).toFloat();
        }
    };

}

#endif // SHOTEVENT_H
