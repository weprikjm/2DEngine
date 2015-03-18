#include "myString.h"


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: UTILITIES



//------------------------------------------------------------------------ LENGTH OF STR
const int myString :: Len(const char* cadena) 
{

		return strlen(cadena);

}
//------------------------------------------------------------------------ FREES MEMORY AND ALLOCS "i" MEMORY IN STR
const void myString :: Alloc(myString& string, int size)
{
		string.size = size;
		string.str = new char[size];
}
const void myString :: Alloc(const unsigned int size)
{
		str = new char[size];
}
//------------------------------------------------------------------------ FREES MEMORY AND ALLOCS 1 MEMORY IN STR
const void myString :: Clear()
{
		str[0] = '\0';
		size = 1;
	
}
//------------------------------------------------------------------------ RETURNS THE REAL SIZE OF STR
const int myString :: Capacity()const
{
		return strlen(str)+1;
}



//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS




//------------------------------------------------------------------------ CONSTRUCTOR MULTIPLE ARRAY/POINTER CHAR SET IN STR


myString :: myString(const char* _string, ...)
{
		size = 0;
		if (_string != NULL)
		{
			static char buff1[4096];
			va_list args;

			va_start(args, _string);
			int res = vsprintf_s(buff1, 4096, _string, args);
		
			va_end(args);

			if (res > 0)
			{
				size = res + 1;
				str = new char[size];
				strcpy_s(str, size, buff1);
			}
		}
		else
		{
			Alloc(1);
			Clear();
		
		}
		size = strlen(str);
	
}
//------------------------------------------------------------------------ CONSTRUCTS CLASS PROPERTY STR EMPTY (ALLOCATING MEMORY FOR \0)
myString :: myString()
{
		Alloc(1);
		Clear();
}



//------------------------------------------------------------------------ CONSTRUCTS CLASS PROPERTY STR WITH REFERENCE MYSTRING& CADENA (ALLOCATING MEMORY)



myString :: myString(const myString& cadena)
{
		if (&cadena != NULL)
		{
			size = cadena.size;
			Alloc(size + 1);
			strcpy_s(str, size + 1, cadena.str);
		}
		else
		{
			Alloc(1);
			Clear();
		}
}


//============================================================================  OPERATORS



//----------------------------------------------------------- OPERATOR == MYSTRING&

bool myString :: operator== (const myString& s) const
{
		if (&s != NULL)
			return strcmp(s.str, str) == 0;
		return false;
}


//----------------------------------------------------------- OPERATOR == CONST CHAR*

bool myString :: operator== (const char* s) const
{
		if (s != NULL)
			return strcmp(s, str) == 0;
		return false;
}


//----------------------------------------------------------- OPERATOR = MYSTRING&

const myString& myString ::  operator= (myString& s)
{

		if (&s != NULL){

			if (strlen(s.str) + 1 > size)
			{
				size = strlen(s.str);
				Alloc(strlen(s.str) + 1);
			}
			else
				Clear();

		
			strcpy_s(str, size + 1, s.str);
	}
			return (*this);
}

//----------------------------------------------------------- OPERATOR = CONST CHAR*

const myString& myString ::  operator= (const char* s)
{
		if (s != NULL)
		{
			if (strlen(s) + 1 > size)	//------------ IF THE CONST CHAR* S PASSED IS BIGGER THAN SIZE IT REALLOCATES MEMORY FOR THE NEW VALUE
			{
				delete[] str;
				size = strlen(s)+1;
				str = new char[strlen(s)+1];
			}
			else
				Clear();

			strcpy_s(str, strlen(s)+1, s);
		}
		else
		{
			Alloc(1);
			Clear();
		}

		return(*this);
}

//----------------------------------------------------------- OPERATOR != MYSTRING&

bool myString :: operator!= (const myString& s) const
{
		if (&s != NULL)
			return strcmp(s.str, str) != 0;
		return true;
}

//----------------------------------------------------------- OPERATOR != CONST CHAR*
bool myString :: operator!= (const char* s) const
{
		if (s != NULL)
			return strcmp(s, str) != 0;
		return true;
}

//----------------------------------------------------------- OPERATOR + MYSTRING&

myString& myString :: operator+ (const myString& s)
{
	
		myString tmp0;
		myString& tmp = tmp0;	

		tmp.Alloc(tmp,strlen(str) + 1);//myString temporal
		strcpy_s(tmp.str, strlen(str)+1,str); //STR is copied to tmp.str

		Alloc(strlen(s.str)+size+1);		//Then memory is allocated for both values
		

		
		strcpy_s(str, strlen(tmp.str)+1, tmp.str); //WE COPY TMP.STR INTO STR NOW WITH ENOUGH SIZE FOR THE NEXT...
		//printf("%d",s.size);
		
		strcat_s(str, strlen(s.str) + size+1, s.str);	//..ARGUMENT WE CONCATENATE 2 MYSTRING.STR
		
		
		return (*this);
	

}

//----------------------------------------------------------- OPERATOR + CONST CHAR*

myString& myString :: operator+ (const char* s) 
{
		if (s != NULL)
		{
			strcat_s(str,strlen(s), s);
			return (*this);
		}
		else
		{
			Alloc(1);
			Clear();
			return (*this);
		}
	
}


//----------------------------------------------------------- OPERATOR += MYSTRING&

myString& myString :: operator+= (const myString& s)
{
		if (&s != NULL)
		{
			myString tmp0;
			myString& tmp = tmp0;

			tmp.Alloc(tmp, strlen(str) + 1);		//MYSTRING TEMPORAL
			strcpy_s(tmp.str, strlen(str) + 1, str); //STR IS COPIED TO TMP.STR
	


			Alloc(strlen(s.str) + tmp.size + 1);		//THEN MEMORY IS ALLOCATED IN THE CURRENT OBJECT FOR BOTH VALUES

			strcpy_s(str, strlen(tmp.str) + tmp.size + 1, tmp.str); //WE COPY TMP.STR INTO STR NOW WITH ENOUGH SIZE FOR THE NEXT...

			strcat_s(str, strlen(s.str) + tmp.size + 1, s.str);	//..ARGUMENT WE CONCATENATE TO MYSTRING.STR

	
			return (*this);
		}
		else
		{ 
			Alloc(1);
			Clear();
			return (*this);
		}
}

//----------------------------------------------------------- OPERATOR += CONST CHAR*

myString& myString :: operator+= (const char* s)
{
		if (s != NULL)
		{

			myString tmp0;
			myString& tmp = tmp0;

			tmp.Alloc(tmp, strlen(str) + 1);		//MYSTRING TEMPORAL
			strcpy_s(tmp.str, strlen(str) + 1, str); //STR IS COPIED TO TMP.STR



			Alloc(strlen(s) + tmp.size + 1);		//THEN MEMORY IS ALLOCATED IN THE CURRENT OBJECT FOR BOTH VALUES

			strcpy_s(str, strlen(tmp.str) + tmp.size + 1, tmp.str); //WE COPY TMP.STR INTO STR NOW WITH ENOUGH SIZE FOR THE NEXT...

			strcat_s(str, strlen(s) + tmp.size + 1, s);	//..ARGUMENT WE CONCATENATE TO MYSTRING.STR

			return (*this);

		}
		else
		{
			Alloc(1);
			Clear();
			return (*this);
		}
	
}



//================================================================= STRING OPERATIONS

char* myString:: GetString()const
{

		return(str);

}




