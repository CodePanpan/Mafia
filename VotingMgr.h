#ifndef VOTINGMGR_H_INCLUDED
#define VOTINGMGR_H_INCLUDED

#include "God.h"
#include <iostream>
#include <vector>

class VotingMgr {
protected:
    std::vector<std::pair<int, int> > players;

    std::vector<int> GetHighestVoteIds(std::vector<int> &highs, std::vector<int> &second_highs);
public:
    VotingMgr();
    void Vote(God &gd);
    void ClearPlayers() {players.clear();}
};

#endif // VOTINGMGR_H_INCLUDED
