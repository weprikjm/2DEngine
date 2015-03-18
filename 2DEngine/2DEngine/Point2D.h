#ifndef Point2D_H
#define Point2D_H
#include <math.h>
#include <stdio.h>
class Point2D
{
public:
	float x, y;
public:

	void SetZero();
	
	bool IsZero() const;
	
	const void Negate();
	
	
	void PrintObject()const;

	float DistanceTo(Point2D);


													//OPERATORS
	Point2D operator+ (const Point2D&) const;
	

	Point2D operator- (const Point2D&) const;


	const Point2D& operator+= (const Point2D&);


	const Point2D& operator-= (const Point2D&);


	const Point2D& operator= (const Point2D&);


	bool operator== (const Point2D&)const;


	bool operator!= (const Point2D&) const;


	float Distance(Point2D&);



};


#endif