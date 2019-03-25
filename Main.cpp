#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

#include "Point.hpp"
#include "Convert.hpp"
#include "BezierCurve.hpp"

std::vector<Point> points =
{
	Point(186, 275),
	Point(160, 215),
	Point(178, 155),
/*	Point(226, 113),
	Point(279, 109),
	Point(329, 137),
	Point(329, 137),
	Point(352, 180),
	Point(350, 216),
	Point(321, 253),
	Point(270, 153),
	Point(270, 153),
	Point(130, 10),
	Point(60, 50),
	Point(300, 200),
	Point(300, 200),
	Point(180, 40)
	*/
};

int main()
{
	BezierCurve* result = new BezierCurve;
	
	int result_id = result->setBezierCurve(points);
    
    if(result_id == 0)
    {
        result->setSegmentAmount(10);
        result->setArcType(BezierCurve::ArcType::Standard);
	
        result->process();
	
        result->print();
    
    }
    
	delete result;
	
	return 0;
}


