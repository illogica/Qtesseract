#ifndef AISTATE_H
#define AISTATE_H

namespace ai{

    class aistate
    {
    public:
        aistate();
        ~aistate();
        aistate(int m, int t, int r = -1, int v = -1);
        void reset();

        int type, millis, targtype, target, idle;
        bool override;
    };

}

#endif // AISTATE_H
