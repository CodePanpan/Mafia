#ifndef DAYNIGHTMGR_H_INCLUDED
#define DAYNIGHTMGR_H_INCLUDED

#include "God.h"
#include <vector>

class DayNightMgr {
protected:
    std::vector<bool> tracker;
public:
    DayNightMgr();
    void Toggle(bool id, God &gd);
};

#endif // DAYNIGHTMGR_H_INCLUDED
