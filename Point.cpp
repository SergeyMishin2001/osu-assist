#include "Point.hpp"

Point::Point(int x, int y) : x(x), y(y) {}

Point operator+(const Point& a, const Point& b)
{
	return Point(a.x + b.x, a.y + b.y);
}

Point operator==(const Point& a, const Point& b)
{
	return (a.x == b.x) && (a.y == b.y);
}

Point operator-(const Point& a, const Point& b)
{
	return Point(a.x - b.x, a.y - b.y);
}

Point operator*(double t, const Point& b)
{
	return Point(t * b.x, t * b.y);
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << "x: " << p.x << "\t" << "y: " << p.y << std::endl;
	return out;
}