#include "pet.h"

class dinozaur :
    public Pet
{

public:
    dinozaur(Pet &other);
    void Talk();
    void Eat();
    void operator -- (int);

};
