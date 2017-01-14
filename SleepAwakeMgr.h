#ifndef SLEEPAWAKEMGR_H_INCLUDED
#define SLEEPAWAKEMGR_H_INCLUDED

#include "God.h"

class SleepAwakeMgr {
protected:
public:
    SleepAwakeMgr();

    //Additional Functions
    void Sleep(int id, God &gd);
    void Awake(int id, God &gd);
    void CitySleep(God &gd);
    void CityAwake(God &gd);
};


#endif // SLEEPAWAKEMGR_H_INCLUDED
