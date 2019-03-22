#ifndef CONVERT_HPP_INCLUDED
#define CONVERT_HPP_INCLUDED

#include <vector>

#include "Point.hpp"

constexpr int SCR_WIDTH = 512;
constexpr int SCR_HEIGHT = 384;

void convertToScreen(std::vector<Point>& points)
{
	for(auto &value: points)
	{
		value.x = value.x  - SCR_WIDTH / 2;
		value.y = -value.y  + SCR_HEIGHT / 2;
	}
}


void convertToNormal(std::vector<Point>& points)
{
	for(auto &value: points)
	{
		value.x = value.x + SCR_WIDTH / 2;
		value.y = SCR_HEIGHT / 2 - value.y;
	}
}

#endif