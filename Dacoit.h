#ifndef DACOIT_H_INCLUDED
#define DACOIT_H_INCLUDED

#include "Player.h"
#include <string>

class Dacoit : public Player {
protected:
public:
    Dacoit(int ID, std::string nm);
};

#endif // DACOIT_H_INCLUDED
