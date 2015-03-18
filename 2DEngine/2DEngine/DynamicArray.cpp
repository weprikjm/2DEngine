#include "DynamicArray.h"
#include <stdio.h>
#include <string>
#include <Assert.h>
void DynamicArray :: Reallocate(unsigned int newMemorySize)
{
			assert(newMemorySize != 0);
			delete[] data;
			data=new int[newMemorySize];
			allocatedMemory = newMemorySize;
			numElements = newMemorySize;
}



void DynamicArray::PushBack(int value)
{
	if (numElements>0)
	{

		if (numElements-allocatedMemory == 0)   //------------------------- if the difference is equal to 0 it means there's not enough memory allocated
		{
			int* tmp = new int[numElements];
			CopyArray(tmp,data);
			Reallocate(numElements+1);   //---------------------We call Reallocate to increase by one the array's capacity

			CopyArray(data, tmp);
			data[numElements-1] = value;

		}
		else if (allocatedMemory > numElements)   //--------------------- if the difference is > 0 it means that there's enough memory to add 1 or more elements.
		{
			data[numElements - 1] = value;
		}

	}
	else
	{
		Reallocate(1);
		data[numElements-1] = value;
	}
}





void DynamicArray::CopyArray(int* dest, int* src)
{
	for (int i = 0; i < numElements; i++)
	{
		dest[i] = src[i];   //-----------------------------We copy data into a temp array.
	}

}


const int DynamicArray::Pop()
{
	int value = 0;

	if (numElements>0)
	{
		
		value = data[numElements - 1];//We save the last value to return

		//Update values
		--numElements;

		return value;
	}
	else
	{
		return NULL;

	}
}





/*
const int DynamicArray::Pop()
{
	int value=0;

	if (numElements>0)
	{
		
		int* tmp = new int[(numElements)];
		CopyArray(tmp, data);

		delete[] data;//We delete the memory to avoid memory leaks

		value = tmp[numElements - 1];//We save the last value to return

		data = new int[numElements - 1];//Allocate the same memory less 1

		for (int i = 0; i < (numElements-1); i++)//Notice that we use numElements-1 to ignore the last value
		{
			data[i] = tmp[i];
		}

		//Update values
		--numElements;
		
		return value;
	}
	else
	{
		return -13;
	
	}
}
*/


/*
//Extracts the first element of the array [0]
int DynamicArray::Pop()
{
	int* tmp = new int[numElements];
	int firstElement;

	firstElement = data[0]; //-------------------------- We save the first element in a variable which we'll return later.
	
	CopyArray(tmp,data); //----------------------------- We copy the data in an tmp array

	data = new int[numElements-1]; //------------------ We save 

	for (int i = 1; i <= numElements;i++)
	{
		data[i-1] = tmp[i];
		
	}
	//Update values
	--numElements;
	--allocatedMemory;

	return firstElement;
}
*/

/*
To insert a value we save the original array in two separate arrays, we destroy and allocate
memory for data, and finally we unite them-
*/


void DynamicArray::Insert(int value, unsigned position)
{
	if (position>= 0 && position<=numElements && (allocatedMemory==numElements))
	{
		int* tmpHead = new int[(position+1)];
		int* tmpTail = new int[(numElements-position)];

		for (int i=0; i < position; i++)
		{
			tmpHead[i] = data[i];
	
		}
		tmpHead[position] = value;//------------------ We save the value in the middle of the two arrays

		int counter = 0;
		for (int i = position; i < numElements; i++)
		{
			tmpTail[counter] = data[i];
			counter++;
		}
	
		if (allocatedMemory == numElements)
		{
			Reallocate(numElements+1); //------------------ We reallocate memory in case there's  not enough space
		}

		CopyArray(data,tmpHead);//------------------------------------- We copy tmpHead into data (tmpHead also has the value to be inserted)
		
		counter = 0;
		for (int i = position+1; i < numElements; i++)
		{	
			data[i] = tmpTail[counter]; //------------------------------------- We copy tmpTail (the rest of the array)
			counter++;
		}

		delete[] tmpHead;
		delete[] tmpTail;
	}
}

int& DynamicArray::operator[](unsigned int index)
{
	printf("no constant");
	assert(index <numElements);
	return (data[index]);
}


const int& DynamicArray::operator[](unsigned int index)const
{
	printf("constant");
	assert(index <numElements);
	return (data[index]);
}