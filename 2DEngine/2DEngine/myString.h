#ifndef MYSTRING_H
#define MYSTRING_H
#include <string.h>
#include <iostream>
#include <stdarg.h>
#include <Assert.h>
#define TMP_STRING_SIZE 4096
using namespace std;
class myString
{
public:
	//Propietats
	unsigned int size;
	char* str;
	

	//CONSTRUCTORS
	myString();

	myString(const myString&);
	
	myString(const char*, ...);
	

	//UTILITIES
	const int Len(const char*);
	const void Clear();
	const void Alloc(myString&,const int);
	const void Alloc(const unsigned int);
	
	//OPERATORS
	bool operator== (const myString&) const;
	


	bool operator== (const char* s) const;




	const myString& operator= (myString&);




	const myString& operator= (const char* s);




	bool operator!= (const myString&) const;



	bool operator!= (const char* s) const;


	myString& operator+ (const myString&);


	myString& operator+ (const char*);

	myString& operator+= (const myString&);

	myString& operator+= (const char*);
	
	//STRING OPERATIONS
	char* GetString()const;

	const int Capacity()const;


	//Metodes

	//METHODS


	~myString()
	{
		delete[] str; 
	}
};

#endif