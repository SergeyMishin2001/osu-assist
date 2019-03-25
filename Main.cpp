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
	Point(226, 113),
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
	
};

int main()
{
	BezierCurve* result = new BezierCurve;
	int userInput = 2;
    
    while(true)
    {
        std::cout << "Type amount of segments to create(from 2 to 100): ";
        std::cin >> userInput;
        
        if(std::cin.fail())
        {
           std::cin.ignore(32767, '\n');
           std::cin.clear();
        }
        else break;
    }
    
	int result_id = result->setBezierCurve(points);
    
    if(result_id == 0)
    {
        result->setSegmentAmount(userInput);
        
        result->setArcType(BezierCurve::ArcType::Standard);
	
        result->process();
        
        result->pickSegmentPoints();
	
        result->printReport();
    
    }
    
	delete result;
	
	return 0;
}


