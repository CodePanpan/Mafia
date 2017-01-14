#include "Mafia.h"
#include <iostream>

Mafia::Mafia(int ID, std::string nm):Player(ID, nm, MAFIA) {

}
std::string Mafia::ChoiceId() {
    std::cout<<"Who do you want to kill?\n";
    std::string ch = "";
    std::getline(std::cin, ch);

    return ch;
}
