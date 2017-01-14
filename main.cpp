#include <iostream>
#include "Player.h"
#include "God.h"
#include "Mafia.h"
#include "Citizen.h"
#include "Dacoit.h"
#include "Detective.h"
#include "Healer.h"
#include "GameMgr.h"
#include "DayNightMgr.h"
#include "DetectionMgr.h"
#include "HealingMgr.h"
#include "KillingMgr.h"
#include "SleepAwakeMgr.h"
#include "VotingMgr.h"

using namespace std;

int main()
{
    God *my_god = new God(0);
    GameMgr gm_mgr(my_god);

    gm_mgr.StartGame();

    return 0;
}
