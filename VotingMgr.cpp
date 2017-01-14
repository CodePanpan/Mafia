#include "VotingMgr.h"

VotingMgr::VotingMgr() {
    players.clear();
}
std::vector<int> VotingMgr::GetHighestVoteIds(std::vector<int> &highs, std::vector<int> &second_highss) {
    //Find Max
    int mx = -1;
    for (register int i = 0; i < players.size(); i++) {
        if (players[i].second > mx)
            mx = players[i].second;
    }
    int second_mx = -1;
    for (register int i = 0; i < players.size(); i++) {
        if (players[i].second > second_mx && players[i].second < mx)
            second_mx = players[i].second;
    }
    for (register int i = 0; i < players.size(); i++) {
        if (players[i].second == mx)
            highs.push_back(players[i].first);
        else if (players[i].second == second_mx)
            second_highss.push_back(players[i].first);
    }
}
void VotingMgr::Vote(God &gd) {
    for (register int i = 0; i < gd.GetNoOfPlayers(); i++) {
        std::pair<int, int> this_pair(gd.GetPlayerByIndex(i)->GetId(), 0);
        players.push_back(this_pair);
    }
    for (register int i = 0; i < gd.GetNoOfPlayers(); i++) {
        Player *tmp = gd.GetPlayerByIndex(i);
        if (tmp->GetAlive()) {
            std::cout<<"Enter your vote by player name\n";
            std::string this_vote;
            std::cin>>this_vote;
            players[gd.GetIdByPlayerName(this_vote) - 1].second++;
        } else {
            players[i].second = -1;
        }
    }
    std::vector<int> highest_votes, second_ht_votes;
    GetHighestVoteIds(highest_votes, second_ht_votes);
    gd.SetHighestVotes(highest_votes);
    gd.SetSecondHtVotes(second_ht_votes);
}
