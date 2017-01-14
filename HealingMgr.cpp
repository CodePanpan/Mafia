#include "HealingMgr.h"

HealingMgr::HealingMgr() {

}
void HealingMgr::Heal(int ID, God &gd) {
    gd.Heal(ID);
}
