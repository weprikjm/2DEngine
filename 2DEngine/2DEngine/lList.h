#include <stdio.h>

#pragma once

template<class TYPE>
class node
{
public:
	TYPE val;
	node<TYPE>* next;

	node(){}
};


template<class TYPE>
class lList
{
public:
	node<TYPE>* start;
	node<TYPE>* iterator;


		node*TYPE newNode = new TYPE node;
		newNode->val = valor;
		newNode->next = NULL;

		if (start == NULL)
		{
			start = new node;
			start = newNode;
			iterator = start;
		}
		else
		{
			while (iterator->next != NULL)
				iterator = iterator->next;
			iterator->next = newNode;
			iterator = start;
		}
	
};

int lList :: count()
{

		int i = 0;
		while (iterator->next != NULL)
		{
			iterator = iterator->next;
			i++;
		}
		return i;

}

// 3 CASES. REMOVED FROM START, REMOVED FROM MIDDLE AND REMOVED FROM END
void lList::remove(node* toRemove)
{

		findNode(toRemove);
		changePointers();
		deleteNode();

}


	lList()
	{
		start = NULL;
		iterator = NULL;
	}

	void add(TYPE valor)
	{
		node<TYPE>* newNode = new node<TYPE>;
		newNode->val = valor;
		newNode->next = NULL;


		if (start == NULL)
		{
			start = new node<TYPE>;
			start = newNode;
			iterator = start;
		}
		else
		{
			while (iterator->next != NULL)
				iterator = iterator->next;
			iterator->next = newNode;
			iterator = start;
		}
	}




void lList :: findNode(const node* const toRemove)
{

		assert(toRemove != NULL);

		previous = iterator;
		while (iterator != toRemove)

	int count()
	{
		int i = 0;
		while (iterator->next != NULL)

		{
			iterator = iterator->next;
			i++;
		}


		
		//Si no hi és.
}

void lList :: changePointers()
{
		if (previous == iterator)//REMOVING THE FIRST ELEMENT
		{

				//DOESN'T DO ANYTHING

		}

		else if (iterator->next == NULL)//REMOVING THE LAST ELEMENT
		{

				previous->next = NULL;

		}
		else
		{

				previous = iterator->next;

		}

}

void lList :: deleteNode()
{

		assert(iterator != NULL);

		delete iterator;

}
//Cridar al destructor de la llista
void delList()
{
		if (start != NULL)
		{ 
	
			node* tmp = start;
			while (tmp->next!=NULL)
			{
				node* tmp_2 = tmp;
				tmp = tmp->next;
				delete tmp_2;
			}
			delete tmp; start = NULL;
	
		}

}




	~lList()
	{
		node<TYPE>* temp;
		iterator = start;
		while (iterator) {
			temp = iterator;
			iterator = temp->next;
			delete temp;
		}
	}

	void deleteNode(node<TYPE>* node)
	{
		if (node != NULL && start != NULL)
		{
			if (node != start)
			{
				node<TYPE>* nextNode = start;
				while ()
				{
					nextNode = nextNode->next;
				}
				nextNode->next = node->next;
			}
			else
			{
				start = start->next;
			}
			delete node;
		}
	}


	void delList()
	{
		if(start != NULL)
		{
			node<TYPE>* tmp = start;
			while (tmp->next != NULL)
			{
				node<TYPE>* tmp_2 = tmp;
				tmp = tmp->next;
				delete tmp_2;
			
			}
			delete tmp;
			start = NULL;
		
		}
	
	}

};

