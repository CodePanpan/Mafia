#ifndef GOD_H_INCLUDED
#define GOD_H_INCLUDED

#include "Player.h"
#include <vector>

class God : public Player {
protected:
    bool is_day;
    int mafia_ct;
    int citizen_ct;
    int no_of_players;
    const int game_id;
    std::vector<Player *> players;
    std::vector<int> highest_votes;
    std::vector<int> second_highest_votes;
public:
    God(int game_ID);
    God(const God &cpy);
    ~God();
    //Setters
    void SetDay(bool day) {is_day = day;}
    void SetMafiaCt(int ct) {mafia_ct = ct;}
    void SetCitizenCt(int ct) {citizen_ct = ct;}
    void SetNoOfPlayers(int n) {no_of_players = n;}
    //void SetPlayers(std::vector<int> plyers) {players = plyers;}
    void SetHighestVotes(std::vector<int> ht_votes) {highest_votes = ht_votes;}
    void SetSecondHtVotes(std::vector<int> sht_votes) {second_highest_votes = sht_votes;}

    //Getters
    int GetGameId() const {return game_id;}
    int GetDay() const {return is_day;}
    int GetMafiaCt() const {return mafia_ct;}
    int GetCitizenCt() const {return citizen_ct;}
    int GetNoOfPlayers() const {return no_of_players;}
    Player *GetPlayerByIndex(int ind) const {return players[ind];}
    std::vector<int> GetHighestVotes() const {return highest_votes;}
    std::vector<int> GetSecondHighestVotes() const {return second_highest_votes;}
    void ClearVotes() {
        highest_votes.clear();
        second_highest_votes.clear();
    }

    //Additional Functions
    Player *GetPlayerById(int id);
    int GetIdByPlayerName(std::string name);
    void GetMafiasByIds(std::vector<int> &mafias);
    int GetHealerById();
    int GetDetectiveById();
    void AddPlayer(Player *pl) {players.push_back(pl);}
    void DecrementMafiaCt() {mafia_ct--;}
    void DecrementCitizenCt() {citizen_ct--;}
    void Kill(int id);
    void Heal(int id);
};

#endif // GOD_H_INCLUDED
