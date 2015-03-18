	#include "Point2D.h"



//================================================================================		UTILITIES


void Point2D :: PrintObject()const
{

	printf("%f, %f", x, y);

}

void Point2D :: SetZero()
{
	x = y = 0.0f;							
}


bool Point2D :: IsZero() const
{
	return x == 0 && y == 0;
}

const void Point2D :: Negate()
{
	x = -x;
	y = -y;
}



//================================================================================		OPERATORS	


//--------------------------------------------------------- EACH ONE OF THE OPERATORS ACTS ON PROPERTIES X AND Y IN RELATION WITH THE OBJECT PASSED AND ITS SIGN

Point2D Point2D :: operator+ (const Point2D& p) const
{
	Point2D tmp;
	//Point2D& tmp=tmp0;
	tmp.x = x + p.x;
	tmp.y = y + p.y;

	return (tmp);
}

Point2D Point2D :: operator- (const Point2D& p) const
{

	Point2D tmp;
	tmp.x = x - p.x;
	tmp.y = y - p.y;

	return (tmp);

}

const Point2D& Point2D :: operator+= (const Point2D& p)
{
	Point2D tmp;
	x += p.x;
	y += p.y;
	
	return (*this);
}

const Point2D& Point2D :: operator-= (const Point2D& p)
{

	Point2D tmp;
	x -= p.x;
	y -= p.y;

	return (*this);

}

const Point2D& Point2D :: operator= (const Point2D& p)
{

	x = p.x;
	y = p.y;

	return (*this);
}
//--------------------------------------------------------- COMPARE WETHER X,Y OF BOTH SIDES OF THE OPERATOR ARE EQUAL OR NOT EQUAL

bool Point2D :: operator ==(const Point2D& v) const
{
	return (x == v.x && y == v.y);
}

bool Point2D :: operator !=(const Point2D& v) const
{
	return (x != v.x || y != v.y);
}

//======================================================================================= POINT OPERATIONS


float Point2D::Distance(Point2D& p1)
{
	float distance;
	distance = sqrt((p1.x - x)*(p1.x - x) + (p1.y - y)*(p1.y - y));
	return distance;
}

