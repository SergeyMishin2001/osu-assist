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
	Point(352, 180),
	Point(350, 216),
	Point(321, 253),
};

int main()
{
	BezierCurve* result = new BezierCurve;
	
	result.setBezierCurve(points);
	result.setSegmentAmount(6);
	result.setArcType(BezierCurve::ArcType::Standard);
	
	result.divideCurve();
	result.calculateSegments();
	
	std::cout << result << std::endl;
	
	delete result;
	
	return 0;
}







std::vector<Point> BezierCurve()
{
	for(auto it = points.begin(); it != points.end(); ++it)
	{
		if(*it == *next(it))
		{
			// Разделим кривые и посчитаем
			// TODO: решить какая из них будет перезаписывать конец(начало) друг друга
		}
	}
	
// Вынести всю хуйню в класс, дистанцию в поле класса, юзер инпут тоже, мультиплаер, пресизшн и прочую хуйню если надо
	
	toNormal(points);

	assert(points.size() > 0 && "Size is 0"); // Спорно

	std::vector<Point> copy_points;
	std::vector<Point> arc_points;

	int lengthSum = getLengthSum(points);
	double multiplier = (lengthSum / (static_cast<double>(arcPoints) - 1.0)) / lengthSum;
	
	double precision = 0.0;
	for(int u = 0; u < arcPoints; u++)
	{
		int layers = points.size() - 1;
		copy_points = points;
		while (layers > 0)
		{
        	for (int i = 0; i < layers; i++)
			{
            	copy_points[i] = copy_points[i] + precision * (copy_points[i+1] - copy_points[i]);
			}
        	layers--;
		}
		
		arc_points.push_back(copy_points[0]);
		arc_points.push_back(copy_points[0]);

		precision += multiplier;
    }

	toScreen(arc_points);

	return arc_points;


}

