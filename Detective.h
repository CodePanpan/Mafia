#ifndef DETECTIVE_H_INCLUDED
#define DETECTIVE_H_INCLUDED

#include "Player.h"
#include <string>

class Detective : public Player {
protected:
public:
    Detective(int ID, std::string nm);
    std::string SuspectWho();
};

#endif // DETECTIVE_H_INCLUDED
