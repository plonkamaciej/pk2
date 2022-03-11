#include "pet_cs.h"
#include "extern.h"

pet_cs::pet_cs() {
	HP = 100 - pet.GetMood();
	ATT = 25 - pet.GetMood()*(rand()%6+5)/100;
}