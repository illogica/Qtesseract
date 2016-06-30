#ifndef GAMEEVENT_H
#define GAMEEVENT_H
#include <QObject>

namespace server {

    class clientinfo;

    class gameevent : public QObject
    {
        Q_OBJECT
    public:
        virtual ~gameevent() {}
    public slots:

        virtual bool flush(clientinfo *ci, int fmillis);
        virtual void process(clientinfo *ci) {}

        virtual bool keepable() const { return false; }
    };

}

#endif // GAMEEVENT_H
