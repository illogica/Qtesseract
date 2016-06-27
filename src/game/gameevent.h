#ifndef GAMEEVENT_H
#define GAMEEVENT_H
#include <QObject>

namespace server {

    class clientinfo;

    class gameevent
    {
        Q_GADGET
    public:
        virtual ~gameevent() {}
    public slots:

        virtual bool flush(clientinfo *ci, int fmillis);
        virtual void process(clientinfo *ci) {}

        virtual bool keepable() const { return false; }
    };

}

Q_DECLARE_METATYPE(server::gameevent)

#endif // GAMEEVENT_H
