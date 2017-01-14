#include "SleepAwakeMgr.h"

SleepAwakeMgr::SleepAwakeMgr() {

}
void SleepAwakeMgr::Sleep(int ID, God &gd) {
    Player *tmp_pl = gd.GetPlayerById(ID);
    tmp_pl->SetAwake(false);
}
void SleepAwakeMgr::Awake(int ID, God &gd) {
    Player *tmp_pl = gd.GetPlayerById(ID);
    tmp_pl->SetAwake(true);
}
void SleepAwakeMgr::CitySleep(God &gd) {
    for (register int i = 0; i < gd.GetNoOfPlayers(); i++) {
        Player *tmp_pl = gd.GetPlayerByIndex(i);
        tmp_pl->SetAwake(false);
    }
}
void SleepAwakeMgr::CityAwake(God &gd) {
    for (register int i = 0; i < gd.GetNoOfPlayers(); i++) {
        Player *tmp_pl = gd.GetPlayerByIndex(i);
        tmp_pl->SetAwake(true);
    }
}

