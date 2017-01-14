#include "BombingMgr.h"

BombingMgr::BombingMgr() {

}
void BombingMgr::SuicideBomb(int bomber_id, int bombed_id, God &gd) {
    //Flash some message on the window about suicide bombing
    gd.Kill(bomber_id);
    gd.Kill(bombed_id);
}
