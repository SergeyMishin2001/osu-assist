#include "Convert.hpp"

void convertToScreen(std::vector<Point>& points)
{
	for(auto &value: points)
	{
		value.x = value.x  - SCR_WIDTH / 2.0f;
		value.y = -value.y  + SCR_HEIGHT / 2.0f;
	}
}

void convertToNormal(std::vector<Point>& points)
{
	for(auto &value: points)
	{
		value.x = value.x + SCR_WIDTH / 2.0f;
		value.y = SCR_HEIGHT / 2.0f - value.y;
	}
}
