#ifndef CITIZEN_H_INCLUDED
#define CITIZEN_H_INCLUDED

#include "Player.h"
#include <string>

class Citizen : public Player {
protected:
public:
    Citizen(int ID, std::string nm);
};

#endif // CITIZEN_H_INCLUDED
