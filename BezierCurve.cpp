#include "BezierCurve.hpp"


int BezierCuve::getLengthSum(const Bezier& points)
{
	double lengthSum = 0;
	for(int i = 0; i < points.size() - 1; ++i)
	{
		lengthSum += sqrt(pow(points[i+1].x - points[i].x, 2) + pow(points[i+1].y - points[i].y, 2));
	}

	return static_cast<int>(lengthSum);
}

void BezierCurve::setBezierCurve(const Bezier& points)
{
	this->m_points = points;
	this->m_totalPoints = points.size();
	this->m_totalLength = getLengthSum(points);
	this->precision = 0.0;	
}

void BezierCurve::setSegmentAmount(int amount)
{
	this->m_userTotalArcPoints = amount;
	this->precision_add = (m_totalLength / (static_cast<double>(m_userTotalArc_points) - 1.0)) / m_totalLength;
	
}

/* Разделить
	написать функцию калькулейтАрк и считать до нужного расстояния, высчитать нужное расстояние в 
	зависимости от мультиплаера
	сохранять в глобальнуж переменную куррентЛЕнгт
*/

// #1
void BezierCurve::divideCurve()
{
	for(auto it = this->points.begin(); it != this->points.end(); ++it)
	{
		this->segment.push_back(*it);
		
		if((*it = *next(it)) || (next(it) != this->points.end()))
		{
			calculateArc();	
			this->segment.clear()
		}
			
	}
}
	
// #2 pod voprosom
void BezierCurve::calculateArc()
{
	Bezier m_segmentCopy;
	int segmentLength = getLengthSum(m_segmentCopy);
	this->m_precisionAdd = 1 / (segmentLength * 2);
	
	if(!arcPoints.empty())
		if(arcPoints.back() == m_segmentCopy[0])
			arcPoints.pop_back();
	
	for(int k = 0; k < (segmentLength * 2); k++) // Новая точка
	{
		m_segmentCopy = this->m_segment;
		
		int layers = m_totalPoints - 1;
		
		while (layers > 0)
		{
        	for (int i = 0; i < layers; i++)
			{
            	m_segmentCopy[i] = m_segmentCopy[i] + this->m_precision * (m_segmentCopy[i+1] - m_segmentCopy[i]);
			}
        	layers--;
		}
		
		
		arcPoints.push_back(m_segmentCopy[0]);
		
		this->precision += this->m_precisionAdd;
		
	}
}
	
// #3
void BezierCurve::pickSegmentPoints()
{
	double m_totalArcLength = getLengthSum(this->arcPoints);
	double m_lengthAdder = totalArcLength / m_userTotalArcPoints;
	double m_currentLength = 0;
	
	int distance = 0;
	
	for(int i = 0; i < arcPoints.size() - 1; i++)
	{
		distance += sqrt(pow(points[i+1].x - points[i].x, 2) + pow(points[i+1].y - points[i].y, 2));
		
		if(distance == static_cast<int>(m_currentLength))
		{
			
		}
	}
}
	
std::ostream& operator<<(std::ostream& out, const BezierCurve& bc)
{
	for(int i = 0; i < bc.result.size(); i++)
	{
		std::cout << "x: " << bc.result[i].x << "\t" << "y: " << bc.result[i].y << std:endl;
	}
	return out;
}
	