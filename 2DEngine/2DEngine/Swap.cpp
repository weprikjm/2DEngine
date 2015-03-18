#include "Swap.h"



template<class TIPUS>
void swap(TIPUS& a, TIPUS& b)
{
	
	TIPUS tmp;
	tmp = a;
	a = b;
	b = tmp;
}


