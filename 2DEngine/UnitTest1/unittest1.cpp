#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CustomLog\Point2D.h"
#include "..\CustomLog\Log.h"
#include "..\CustomLog\myString.h"
#include "..\CustomLog\Point2D.cpp"
#include "..\CustomLog\myString.cpp"
#include "..\CustomLog\DynamicArray.h"
#include "..\CustomLog\DynamicArray.cpp"
#include <stdio.h>
#define LOG(format, ...) LogPrint(__FILE__, __LINE__, format, __VA_ARGS__);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		//======================================================================= MYSTRING METHODS
		TEST_METHOD(TestMethod1)
		{
			DynamicArray fulles;
			int* leaves = new int[6];
			int* trees = new int[7];


			trees[0] = 1;
			trees[1] = 2;
			trees[2] = 3;
			trees[3] = 4;
			trees[4] = 5;			//Reallocate
			trees[5] = 6;
			trees[6] = 7;
			trees[7] = 8;


			leaves[0] = 1;
			leaves[1] = 2;
			leaves[2] = 3;
			leaves[3] = 4;


			fulles.Reallocate(7);
			Assert::AreEqual(fulles.numElements, (unsigned int)7);

	
		}

		TEST_METHOD(TestMethod2)
		{
	

		}

		TEST_METHOD(TestMethod3)
		{
			
			myString string("%s", "Hola");

														 //---------- METHOD LEN
			Assert::AreEqual(string.Len(string.str), 4);
		}

		TEST_METHOD(TestMethod4)
		{
			myString string("%s%s", "Hi", "Yeah");//---------------  CONSTRUCTOR MULTIPLE STRINGS %S FOR EACH ARGUMENT.
			Assert::AreEqual(string.Len(string.str), 6);
			Assert::AreEqual(string.str,"HiYeah");
		}

		TEST_METHOD(TestMethod5)
		{
			myString string;		 //--------------------------------- EMPTY CONSTRUCTOR
			Assert::AreEqual(string.Len(string.str), 0);
			Assert::AreEqual(string.str, "");

		}

		TEST_METHOD(TestMethod6)
		{
			myString String("Ruben");		//----------------------- CONSTRUCTOR WITH ONE ARGUMENT
			Assert::AreEqual(String.size, (unsigned int)5);
			Assert::AreEqual(String.str, "Ruben");
		}

		TEST_METHOD(TestMethod7)
		{
			myString m("Ruben");		//---------------------- COPY CONSTRUCTOR WITH A MYSTRING AS A PARAMETER
			myString& p = m;

			myString string1(p);

			Assert::AreEqual(string1.size, (unsigned int)5);
			Assert::AreEqual(string1.str,"Ruben");
		}

		TEST_METHOD(TestMethod8)
		{
			myString m;
			myString p;									//------------------------- EMPTY STRING == OPERATOR  
			Assert::IsTrue(m == p);
		}

		TEST_METHOD(TestMethod9)
		{
			myString m;				//----------------------------- STRING CONST CHAR* ==
			
			m = "Hola";

			Assert::IsTrue(m == "Hola");
		}

		TEST_METHOD(TestMethod10)
		{
			myString m;
			myString p;		//----------------------------- STRING == MYSTRING&

			myString& rm = m;
			myString& rp = p;


			m = "Hola";
			p = "Hola";


			Assert::IsTrue(rm == rp);
		}


		TEST_METHOD(TestMethod11)
		{
			myString m;
			myString p;		//----------------------------- STRING = MYSTRING&

			myString& rm = m;
			myString& rp = p;

			m = "toalla";
			rp = rm;

			Assert::AreEqual(rp.str, "toalla");
		}

		TEST_METHOD(TestMethod12)
		{
			myString m;
			
			m = "Hola";								//------------------------------- STRING = CONST CHAR*
			Assert::AreEqual(m.str,"Hola");
		}
		TEST_METHOD(TestMethod13)
		{							
			myString m;
			myString p;

			myString& rm=m;
			myString& rp=p;

			m = "Hola";						//---------------------------------- STRING != MYSTRING&
			p = "Adeu";

			

			Assert::IsTrue(rm != rp);
		}
		TEST_METHOD(TestMethod14)
		{
			myString m;
			m = "Hola";						//-------------------------------------- STRING != CONST CHAR*
			
			Assert::IsTrue(m == "Hola");
		}
		TEST_METHOD(TestMethod15)
		{
			myString m;
			myString p;						//-------------------------------------- STRING += CONST CHAR*

			m = "Blood";
			p = "Thunder";

			m += p;

			Assert::AreEqual(m.str,"BloodThunder");



		}
		TEST_METHOD(TestMethod16)
		{
			myString m;						//-------------------------------------- STRING += MYSTRING&
			myString& rm = m;



			m = "Blood";
			rm += "Thunder";

			Assert::AreEqual(rm.str, "BloodThunder");
		}

		


		TEST_METHOD(TestMethod17)
		{
			myString m;

			m = "Hola";

			Assert::AreEqual(m.GetString(), "Hola");			//------------------------- STRING GETSTRING 
			Assert::AreEqual(m.GetString(), m.str);
		}
		
		TEST_METHOD(TestMethod18)
		{
			myString m;
			m = "Hola";							//---------------------------------------- STRING CAPACITY

			Assert::AreEqual(m.Capacity(), 5);
		}


		//=================================================================================================================  CHANGE CLASS
		
		//============================================================================= POINT2D METHODS
		TEST_METHOD(TestMethod19)
		{
			Point2D p1;
			Point2D p2;

			p1.x = 5;
			p1.y = 5;
			p2.x = 5;
			p2.y = 5;

			p1 = p1 - p2;						//---------------------------------------- - OPERATOR

			Assert::AreEqual(p1.x, 0.0f);
			Assert::AreEqual(p1.y, 0.0f);
		}

		TEST_METHOD(TestMethod20)
		{
			Point2D p1;
			Point2D p2;

			p1.x = 5;
			p1.y = 5;							//---------------------------------------- + OPERATOR
			p2.x = 5;
			p2.y = 5;

			p1 = p1 + p2;

			Assert::AreEqual(p1.x, 10.0f);
			Assert::AreEqual(p1.y, 10.0f);
		}
		TEST_METHOD(TestMethod21)
		{

			Point2D p1;
			Point2D p2;

			p1.x = 5;
			p1.y = 5;
			p2.x = 5;
			p2.y = 5;

			p1 += p2;						//---------------------------------------- += OPERATOR

			Assert::AreEqual(p1.x, 10.0f);
			Assert::AreEqual(p1.y, 10.0f);

			
			
		}
		TEST_METHOD(TestMethod22)
		{

			Point2D p1;
			Point2D p2;

			p1.x = 5;
			p1.y = 5;
			p2.x = 5;
			p2.y = 5;


			p1 -= p2;						//---------------------------------------- -= OPERATOR

			Assert::AreEqual(p1.x, 0.0f);
			Assert::AreEqual(p1.y, 0.0f);
	
			
			
		}
		TEST_METHOD(TestMethod23)
		{
			Point2D p1;
			Point2D p2;

			p1.x = 5;
			p1.y = 5;
			p2.x = 5;
			p2.y = 5;

			Assert::IsTrue(p1 == p2);			//---------------------------------------- == OPERATOR

		}

		TEST_METHOD(TestMethod24)
		{
			Point2D p1;
			Point2D p2;

			p1.x = 5;
			p1.y = 4;							//---------------------------------------- != OPERATOR
			p2.x = 5;
			p2.y = 5;


			Assert::IsTrue(p1 != p2);
		}

		//------------------------------------ STRING UTILITIES

		TEST_METHOD(TestMethod25)
		{
			Point2D p1;

			p1.SetZero();
										//---------------------------------------- SETZERO
			Assert::AreEqual(p1.x, 0.0f);
		}

		TEST_METHOD(TestMethod26)
		{
			Point2D p1;

			p1.SetZero();				//---------------------------------------- ISZERO

			
			Assert::IsTrue(p1.IsZero());
		}

		TEST_METHOD(TestMethod27)
		{
			Point2D p1;
			Point2D p2;

			p1.x = 1;
			p1.y = 1;				//---------------------------------------- DISTANCETO
			p2.x = 3;
			p2.y = 3;

										

			Assert::AreEqual(p1.Distance(p2),sqrtf(8));
		}

		TEST_METHOD(Reallocate)
		{
			DynamicArray fulles;
			int* leaves = new int[6];
			int* trees = new int[7];


			trees[0] = 1;
			trees[1] = 2;
			trees[2] = 3;
			trees[3] = 4;
			trees[4] = 5;			//Reallocate
			trees[5] = 6;
			trees[6] = 7;
			trees[7] = 8;


			leaves[0] = 1;
			leaves[1] = 2;
			leaves[2] = 3;
			leaves[3] = 4;


			fulles.Reallocate(7);
			Assert::AreEqual(fulles.numElements, (unsigned int)7);


		}

		TEST_METHOD(Pushback)
		{
			DynamicArray fulles;

			fulles.Reallocate(7);

			fulles.data[0] = 1;
			fulles.data[1] = 2;
			fulles.data[2] = 3;
			fulles.data[3] = 4;
			fulles.data[4] = 5;
			fulles.data[5] = 6;
			fulles.data[6] = 7;
			fulles.PushBack(8);


			Assert::AreEqual(fulles.data[7], 8);


		}
		TEST_METHOD(Pushback2)
		{
			DynamicArray fulles(1);

			
			fulles.PushBack(1);



			Assert::AreEqual(fulles.data[1], 1);
			

		}
		TEST_METHOD(POP)
		{
			DynamicArray fulles;

			fulles.Reallocate(7);

			fulles.data[0] = 1;
			fulles.data[1] = 2;
			fulles.data[2] = 3;
			fulles.data[3] = 4;
			fulles.data[4] = 5;
			fulles.data[5] = 6;
			fulles.data[6] = 7;
			
			int i = fulles.Pop();



			Assert::AreEqual(i, 7);


		}


	

	
		
	};
}