#ifndef HEALER_H_INCLUDED
#define HEALER_H_INCLUDED

#include "Player.h"
#include <string>

class Healer : public Player {
protected:
    bool has_healed;
    bool has_killed;
public:
    Healer(int ID, std::string nm);

    //Setters
    void SetHasHealed() {has_healed = true;}
    void SetHasKilled() {has_killed = true;}

    //Getters
    bool GetHasHealed() const {return has_healed;}
    bool GetHasKilled() const {return has_killed;}

    //Additional Functions
    bool SaveChoiceId(std::string name);
    std::string KillChoiceId();
};

#endif // HEALER_H_INCLUDED
