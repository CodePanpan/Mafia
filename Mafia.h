#ifndef MAFIA_H_INCLUDED
#define MAFIA_H_INCLUDED

#include "player.h"
#include <string>

class Mafia : public Player {
protected:
public:
    Mafia(int ID, std::string nm);

    std::string ChoiceId();
};

#endif // MAFIA_H_INCLUDED
