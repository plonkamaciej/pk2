#pragma once
#include "pet.h"
class kot :
    public Pet
{

public:
    kot(Pet& other);
    void Talk();
    void Eat();
    void operator -- (int);
};

