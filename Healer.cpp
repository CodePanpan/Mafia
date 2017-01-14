#include "Healer.h"
#include <iostream>

Healer::Healer(int ID, std::string nm):Player(ID, nm, HEALER) {
    has_healed = false;
    has_killed = false;
}
bool Healer::SaveChoiceId(std::string name) {
    std::cout<<"This person is dead: "<<name<<". Do you want to save him\n";
    bool ch;
    std::string choice;
    std::cin>>choice;
    if (choice == "YES" || choice == "Yes" || choice == "yes" || choice == "y" || choice == "Y")
        ch = true;
    else
        ch = false;

    return ch;
}
std::string Healer::KillChoiceId() {
    std::cout<<"Do you want to kill someone?\n";
    bool ch;
    std::string choice;
    std::string who = "";
    std::cin>>choice;
    if (choice == "YES" || choice == "Yes" || choice == "yes" || choice == "y" || choice == "Y")
        ch = true;
    else
        ch = false;
    std::cout<<"Who?\n";
    if (ch) {
        std::cin>>who;
    }
    return who;
}

