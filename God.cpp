#include "God.h"
#include <iostream>

God::God(int game_ID):game_id(game_ID), Player(0, "God", GOD) {
    is_day = true;
    mafia_ct = 3;
    citizen_ct = 3;
    no_of_players = 9;
    players.clear();
    highest_votes.clear();
    second_highest_votes.clear();
}
God::God(const God &cpy):game_id(cpy.GetGameId()), Player(cpy.GetId(), cpy.GetName(), cpy.GetType()) {
    for (register int i = 0; i < cpy.GetNoOfPlayers(); i++) {
        Player *pl = new Player(*(cpy.GetPlayerByIndex(i)));
        players.push_back(pl);
    }
}
God::~God() {
    for (register int i = 0; i < no_of_players; i++)
        delete players[i];
}
void God::Kill(int id) {
    Player *tmp_pl = GetPlayerById(id);
    tmp_pl->SetAlive(false);
}
void God::Heal(int id) {
    Player *tmp_pl = GetPlayerById(id);
    tmp_pl->SetAlive(true);
}
Player *God::GetPlayerById(int id) {
    for (register int i = 0; i < no_of_players; i++) {
        Player *t_pl = GetPlayerByIndex(i);
        if (t_pl->GetId() == id)
            return t_pl;
    }
    return NULL;
}
int God::GetIdByPlayerName(std::string name) {
    for (register int i = 0; i < no_of_players; i++) {
        Player *t_pl = GetPlayerByIndex(i);
        if (t_pl->GetName() == name) {
            return t_pl->GetId();
        }
    }
    return -1;
}
void God::GetMafiasByIds(std::vector<int> &mafias) {
    for (register int i = 0; i < no_of_players; i++) {
        Player *tmp = players[i];
        if (tmp->GetType() == MAFIA && tmp->GetAlive())
            mafias.push_back(tmp->GetId());
    }
}
int God::GetHealerById() {
    for (register int i = 0; i < no_of_players; i++) {
        Player *tmp = players[i];
        if (tmp->GetType() == HEALER && tmp->GetAlive())
            return tmp->GetId();
    }
    return -1;
}
int God::GetDetectiveById() {
    for (register int i = 0; i < no_of_players; i++) {
        Player *tmp = players[i];
        if (tmp->GetType() == DETECTIVE && tmp->GetAlive())
            return tmp->GetId();
    }
    return -1;
}
