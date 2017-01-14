#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

enum Type {
    GOD = 0,
    MAFIA,
    CITIZEN,
    HEALER,
    DETECTIVE,
    DACOIT
};

class Player {
protected:
    const int id;
    const Type type;
    const std::string name;
    bool is_awake;
    bool is_alive;
public:
    Player(int ID, std::string nm, Type tp);

    //Setters
    void SetAwake(bool state) {is_awake = state;}
    void SetAlive(bool state) {is_alive = state;}

    //Getters
    int GetId() const {return id;}
    Type GetType() const {return type;}
    std::string GetName() const {return name;}
    bool GetAwake() const {return is_awake;}
    bool GetAlive() const {return is_alive;}
};

#endif // PLAYER_H_INCLUDED
