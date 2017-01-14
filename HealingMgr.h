#ifndef HEALINGMGR_H_INCLUDED
#define HEALINGMGR_H_INCLUDED

#include "God.h"

class HealingMgr {
protected:
public:
    HealingMgr();
    void Heal(int ID, God &gd);
};

#endif // HEALINGMGR_H_INCLUDED
