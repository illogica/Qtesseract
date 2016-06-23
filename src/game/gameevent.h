#ifndef GAMEEVENT_H
#define GAMEEVENT_H

namespace server {

    class clientinfo;

    class gameevent
    {
    public:
        virtual ~gameevent() {}
        virtual bool flush(clientinfo *ci, int fmillis);
        virtual void process(clientinfo *ci) {}

        virtual bool keepable() const { return false; }
    };

}

#endif // GAMEEVENT_H
