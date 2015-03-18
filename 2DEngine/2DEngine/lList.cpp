#include "lList.h"
#include <stdio.h>
#include <assert.h>

#pragma once

template<class TYPE>
class lList
{

public:
	node*<TYPE> start;
	node*<TYPE> iterator;

	lList();
	//Main methods
	void add(int);
	int count();
	void remove(node*<TYPE>);

		//[ METHODS OF REMOVE
	int findNode(const node*<TYPE> const);
		void deleteNode();
		void changePointers();
							//]

};

