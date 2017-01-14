#include "DayNightMgr.h"

DayNightMgr::DayNightMgr() {
    tracker.clear();
}
void DayNightMgr::Toggle(bool ID, God &gd) {
    tracker.push_back(ID);
    gd.SetDay(ID);
}
