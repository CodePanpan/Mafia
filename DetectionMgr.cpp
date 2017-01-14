#include "DetectionMgr.h"

DetectionMgr::DetectionMgr() {

}
void DetectionMgr::Suspect(int ID, God &gd) {
    Player *tmp_pl = gd.GetPlayerById(ID);
    if (tmp_pl->GetType() == MAFIA)
        std::cout<<"Yes\n";
    else
        std::cout<<"No\n";
}
