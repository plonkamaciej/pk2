#include "los.h"


template<typename T>
T los<T>::losowanie(list<T> r)
{
	srand(time(Null));
	int tmp = rand() % r.size();
	return r[tmp];
}
