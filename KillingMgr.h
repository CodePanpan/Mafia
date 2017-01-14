#ifndef KILLINGMGR_H_INCLUDED
#define KILLINGMGR_H_INCLUDED

#include "God.h"

class KillingMgr {
protected:
public:
    KillingMgr();
    void Kill(int ID, God &gd);
};

#endif // KILLINGMGR_H_INCLUDED
