#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdlib.h>

class DynamicArray
{
public:
	int* data;
	unsigned int allocatedMemory;
	unsigned int numElements;




public: 
	DynamicArray() : data(NULL), allocatedMemory(0), numElements(0){}
	DynamicArray(unsigned int initialSize){ Reallocate(initialSize); allocatedMemory = initialSize; numElements = initialSize; }

	//===== UTILITIES =====
	void CopyArray(int*, int*);

	void setData();

	void Reallocate(unsigned int newMemorySize);
	void PushBack(int value);
	const int Pop();

	void Insert(int value, unsigned position);
	int& operator[](unsigned int);
	const int& operator[](unsigned int)const;






	~DynamicArray()
	{
		if (data != NULL)
		{
			delete[] data;
		}
	}

};
#endif