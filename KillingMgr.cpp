#include "KillingMgr.h"

KillingMgr::KillingMgr() {

}
void KillingMgr::Kill(int ID, God &gd) {
    gd.Kill(ID);
}
