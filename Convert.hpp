#ifndef CONVERT_HPP_INCLUDED
#define CONVERT_HPP_INCLUDED

#include <vector>

#include "Point.hpp"

constexpr int SCR_WIDTH = 512;
constexpr int SCR_HEIGHT = 384;

void convertToScreen(std::vector<Point>& points);

void convertToNormal(std::vector<Point>& points);

#endif
