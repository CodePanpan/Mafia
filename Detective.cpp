#include "Detective.h"
#include <iostream>

Detective::Detective(int ID, std::string nm):Player(ID, nm, DETECTIVE) {

}
std::string Detective::SuspectWho() {
    std::cout<<"Do you suspect someone?";
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
