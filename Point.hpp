#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include <iostream>

class Point
{
public:
	int x,y;
	Point(int x, int y);
	
	friend Point operator+(const Point& a, const Point& b);
	friend Point operator-(const Point& a, const Point& b);
	friend Point operator*(double t, const Point& b);
	friend Point operator==(const Point& a, const Point& b);
	
	friend std::ostream& operator<<(std::ostream& out, const Point& p);
};

#endif