#ifndef BOMBINGMGR_H_INCLUDED
#define BOMBINGMGR_H_INCLUDED

#include "God.h"

class BombingMgr {
protected:
public:
    BombingMgr();
    void SuicideBomb(int bomber_id, int bombed_id, God &gd);
};

#endif // BOMBINGMGR_H_INCLUDED
