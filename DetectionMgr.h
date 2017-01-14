#ifndef DETECTIONMGR_H_INCLUDED
#define DETECTIONMGR_H_INCLUDED

#include <iostream>
#include "God.h"

class DetectionMgr {
protected:
public:
    DetectionMgr();
    void Suspect(int ID, God &gd);
};

#endif // DETECTIONMGR_H_INCLUDED
