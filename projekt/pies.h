#pragma once
#include "pet.h"
class pies :
    public Pet
{
public:
    pies(Pet& other);
    void Talk();
    void Eat(int food = 4);
    void operator -- (int);
};

