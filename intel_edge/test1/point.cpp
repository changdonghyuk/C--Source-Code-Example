#include "point.h"
#include <stdio.h>
#include <iostream>

double point::Dist (point p)
{
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}
point&point::Setp(point p)
{
	x = p.x, y = p.y; 
	return*this;
}
point&point::Setp(int x, int y)
{
	this->x = x;  this->y = y;
}
void point::viewP(const char* s)
{
	printf("%s (%d  %d)\n", s, x, y);

	return *this;
}
point& point::Movep(int  on_x, int on_y)
{
	this->x += on_x;
	this->y += on_y;
	
	return *this;
}

point& point::operator+(point p)
{
	point* p1 = new point(x + p.x, y + p.y);
	return *p1;
}

point& point :: operator++()
{
	x++; y++;
	return *this;
}
point& point :: operator++(int)
{
	point* p1 = new point(x ++, y ++);
	
	return *p1;
}



double point :: operator*(point p)
{
	int w = x - p.x;
	int h = y - p.y;
	double a =w * h;
	return ABS(a);
	
}
