#include "GameMgr.h"

GameMgr::GameMgr(God *gd) {
    my_god = gd;
    _dead_today.clear();
    trials = 0;
}
GameMgr::GameMgr(const GameMgr &cpy) {
    my_god = new God(*cpy.GetGod());
    _dead_today = cpy.GetDeadToday();
}
GameMgr::~GameMgr() {
    delete my_god;
}
void GameMgr::StartGame() {
    std::cout<<"Welcome to Mafia/Citizen game\n";

    EnterMafias();
    EnterCitizens();
    EnterHealer();
    EnterDetective();
    EnterDacoit();

    SetDayNight(true);

    register int game_trials = 0;

    do {
        _dead_today.clear();

        SleepTheCity();
        MafiaKillings();
        HealerOperations();
        DetectiveActivity();
        KillOperationsForToday();
        CalculateCount(_dead_today);
        if (CheckGameEnded())
            break;
        CityOpenEyes();
        VoteOut();
        CalculateCount(my_god->GetHighestVotes());
        if (CheckGameEnded())
            break;
        trials++;
    } while(trials < 10);
}
void GameMgr::EnterMafias() {
    std::string name;
    //Enter mafias
    for (register int i = 1; i <= 3; i++) {
        std::cout<<"Enter your name\n";
        std::cin>>name;
        Mafia *my_mafia = new Mafia(i, name);
        //Add mafias to god
        my_god->AddPlayer(my_mafia);
    }
}
void GameMgr::EnterCitizens() {
    std::string name;
    //Enter citizens
    for (register int i = 4; i <= 6; i++) {
        std::cout<<"Enter your name\n";
        std::cin>>name;
        Citizen *my_citizen = new Citizen(i, name);
        //Add citizens to god
        my_god->AddPlayer(my_citizen);
    }
}
void GameMgr::EnterHealer() {
    std::string name;
    //Enter healer
    std::cout<<"Enter your name\n";
    std::cin>>name;
    Healer *my_healer = new Healer(7, name);

    //Add healer to god
    my_god->AddPlayer(my_healer);
}
void GameMgr::EnterDetective() {
    std::string name;
    //Enter detective
    std::cout<<"Enter your name\n";
    std::cin>>name;
    Detective *my_detective = new Detective(8, name);
    //Add detective to god
    my_god->AddPlayer(my_detective);
}
void GameMgr::EnterDacoit() {
    std::string name;
    //Enter dacoit
    std::cout<<"Enter your name\n";
    std::cin>>name;
    Dacoit *my_dacoit = new Dacoit(9, name);
    //Add dacoit to god
    my_god->AddPlayer(my_dacoit);
}
void GameMgr::SetDayNight(bool day) {
    //Set day/night
    _dn_mgr.Toggle(day, *my_god);
}
void GameMgr::SleepTheCity() {
    //Get the city to sleep
    std::cout<<"City go to sleep\n";
    _sa_mgr.CitySleep(*my_god);
    _dn_mgr.Toggle(false, *my_god);
}
void GameMgr::MafiaKillings() {
    //dummy read
    std::string ch;
    std::getline(std::cin, ch);
    //Ask Mafias to open eyes
    std::cout<<"Mafia open your eyes\n";
    std::vector<int> mafias;
    std::vector<int> choices;
    my_god->GetMafiasByIds(mafias);
    for (register int i = 0; i < mafias.size(); i++)
        _sa_mgr.Awake(mafias[i], *my_god);
    for (register int i = 0; i < mafias.size(); i++) {
        Mafia *tmp_mf = static_cast<Mafia *>(my_god->GetPlayerById(mafias[i]));
        choices.push_back(my_god->GetIdByPlayerName(tmp_mf->ChoiceId()));
    }
    /** Fix this **/
    int mx = -1;
    if (choices[0] == choices[1])
        mx = choices[0];
    else if (choices[0] == choices[2])
        mx = choices[0];
    else if (choices[1] == choices[2])
        mx = choices[1];
    if (mx != -1) {
        _dead_today.push_back(mx);
    }
    //Ask Mafias to go to sleep
    std::cout<<"Mafias go to sleep\n";
    for (register int i = 0; i < mafias.size(); i++) {
        _sa_mgr.Sleep(mafias[i], *my_god);
    }
}
void GameMgr::HealerOperations() {
    //Ask Healer to open eyes
    std::cout<<"Healer open your eyes\n";
    int healer_id = my_god->GetHealerById();
    if (healer_id != -1) {
        Healer *healer = static_cast<Healer *>(my_god->GetPlayerById(healer_id));
        _sa_mgr.Awake(healer_id, *my_god);
        if (_dead_today.size() != 0 && !healer->GetHasHealed()) {
            if (healer->SaveChoiceId(my_god->GetPlayerById(_dead_today[0])->GetName())) {
                _dead_today.clear();
                healer->SetHasHealed();
            }
        }
        if (!healer->GetHasKilled()) {
            int healer_kill = my_god->GetIdByPlayerName(healer->KillChoiceId());
            if (healer_kill != -1) {
                _dead_today.push_back(healer_kill);
                healer->SetHasKilled();
            }
        }
        _sa_mgr.Sleep(healer_id, *my_god);
    }
    std::cout<<"Healer close your eyes\n";
}
void GameMgr::DetectiveActivity() {
    //Ask Detective to open eyes
    std::cout<<"Detective open your eyes\n";
    int detective_id = my_god->GetDetectiveById();
    if (detective_id != -1) {
        _sa_mgr.Awake(detective_id, *my_god);
        Detective *detective = static_cast<Detective *>(my_god->GetPlayerById(detective_id));
        int suspect = my_god->GetIdByPlayerName(detective->SuspectWho());
        if (suspect != -1 && my_god->GetPlayerById(suspect)->GetType() == MAFIA)
            std::cout<<"YES\n";
        else if (suspect != -1)
            std::cout<<"NO\n";
        _sa_mgr.Sleep(detective_id, *my_god);
    }
    std::cout<<"Detective close your eyes\n";
}
void GameMgr::KillOperationsForToday() {
    //Kill the players for today
    for (register int i = 0; i < _dead_today.size(); i++)
        _kl_mgr.Kill(_dead_today[i], *my_god);
}
void GameMgr::CalculateCount(std::vector<int> ousted_players) {
    //Calculate count
    for (register int i = 0; i < ousted_players.size(); i++) {
        if (my_god->GetPlayerById(ousted_players[i])->GetType() == MAFIA) {
            my_god->DecrementMafiaCt();
        }
        else if (my_god->GetPlayerById(ousted_players[i])->GetType() == CITIZEN) {
            my_god->DecrementCitizenCt();
        }
    }
}
bool GameMgr::CheckGameEnded() {
    //Check win-loss
    if (my_god->GetMafiaCt() == 0 && my_god->GetCitizenCt() == 0) {
        std::cout<<"No one has won\n";
        return true;
    } else if (my_god->GetMafiaCt() == 0 && my_god->GetCitizenCt() != 0) {
        std::cout<<"Citizens have won\n";
        return true;
    } else if (my_god->GetMafiaCt() != 0 && my_god->GetCitizenCt() == 0) {
        std::cout<<"Mafias have won\n";
        return true;
    }
    return false;
}
void GameMgr::CityOpenEyes() {
    //Ask city to open eyes
    std::cout<<"City open your eyes\n";
    _sa_mgr.CityAwake(*my_god);
    _dn_mgr.Toggle(true, *my_god);
    if (_dead_today.size() == 0)
        std::cout<<"No one is dead\n";
    else {
        for (register int i = 0; i < _dead_today.size(); i++)
            std::cout<<my_god->GetPlayerById(_dead_today[i])->GetName()<<" is dead\n";
    }
}
void GameMgr::VoteOut() {
    //Voting begins
    register int vote_ct = 0;
    std::cout<<"Cast your votes and being the discussions\n";
    while (vote_ct < 2 || my_god->GetHighestVotes().size() != 1) {
        my_god->ClearVotes();
        _vt_mgr.Vote(*my_god);
        _vt_mgr.ClearPlayers();
        vote_ct++;
        for (register int i = 0; i < my_god->GetHighestVotes().size(); i++) {
            std::cout<<my_god->GetPlayerById(my_god->GetHighestVotes()[i])->GetName()<<" has highest votes\n";
        }
        for (register int i = 0; i < my_god->GetSecondHighestVotes().size(); i++) {
            std::cout<<my_god->GetPlayerById(my_god->GetSecondHighestVotes()[i])->GetName()<<" has second highest votes\n";
        }
    }
    //Voted out
    std::cout<<my_god->GetPlayerById(my_god->GetHighestVotes()[0])->GetName()<<" has been voted out\n";
    _kl_mgr.Kill(my_god->GetHighestVotes()[0], *my_god);
}
