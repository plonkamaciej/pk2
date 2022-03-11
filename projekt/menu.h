#ifndef MENU_H
#define MENU_H

class menu
{
    int opcja;

public:
    string set_back();
    void display_menu();
    void display_ending();
    void graj();
    void reset();
    int wyjdz();
};

#endif