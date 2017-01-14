#ifndef GAMEMGR_H_INCLUDED
#define GAMEMGR_H_INCLUDED

#include "God.h"
#include "DayNightMgr.h"
#include "SleepAwakeMgr.h"
#include "KillingMgr.h"
#include "VotingMgr.h"
#include "Mafia.h"
#include "Citizen.h"
#include "Healer.h"
#include "Detective.h"
#include "Dacoit.h"

class GameMgr {
protected:
    God *my_god;
    int trials;
    std::vector<int> _dead_today;
    DayNightMgr _dn_mgr;
    SleepAwakeMgr _sa_mgr;
    KillingMgr _kl_mgr;
    VotingMgr _vt_mgr;
public:
    GameMgr(God *gd);
    GameMgr(const GameMgr &cpy);
    ~GameMgr();

    //Getters
    God *GetGod() const {return my_god;}
    std::vector<int> GetDeadToday() const {return _dead_today;}
    int GetTrials() const {return trials;}

    //Additional Functions
    void StartGame();
    void EnterMafias();
    void EnterCitizens();
    void EnterHealer();
    void EnterDetective();
    void EnterDacoit();

    void SetDayNight(bool day);
    void SleepTheCity();

    void MafiaKillings();
    void HealerOperations();
    void DetectiveActivity();

    void KillOperationsForToday();
    void CalculateCount(std::vector<int> ousted_players);
    bool CheckGameEnded();

    void CityOpenEyes();
    void VoteOut();
};

#endif // GAMEMGR_H_INCLUDED
