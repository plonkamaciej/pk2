#include "header.h"
#include "pet.h"

#ifndef MENU_H
#define MENU_H

class menu
{
    int opcja;

public:
    
    string set_back();
    void display_menu(Pet & pet);
    void display_ending(Pet pet);
    void graj(Pet & pet);
    void reset(Pet & pet);
    int wyjdz();
};

#endif