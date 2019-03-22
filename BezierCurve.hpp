#ifndef BEZIERCURVE_HPP_INCLUDED
#define BEZIERCURVE_HPP_INCLDED

#include <vector>
#include <cmath>
#include "Point.hpp"

typedef std::vector<Point> Bezier;

class BezierCurve
{
private:
//

// FIELDS
	ArcType type;
	
	Bezier m_points;
	Bezier m_segment;
	Bezier m_arcPoints;
	Bezier m_result;
	
	int m_totalLength;
	
	double m_precision;
	double m_precisionAdd;
	
	int m_totalSegments;
	int m_userTotalArcPoints;
	int m_totalPoints;
	
// METHODS
	static int getLengthSum();

public:
//
	enum class ArcType
	{
		Normal = 0,
		Standard,
		Increasing,
		Decreasing,
		Waving,
		OneSide,
		Random
	};
	
// METHODS
	void setBezierCurve(const Bezier& points);
	
	void setArcType(ArcType type);
	
	void setSegmentAmount(int amount);
	
	void divideCurve();
	
	void calculateArc();
	
	friend std::ostream operator<<(std::ostream& out, const BezierCurve& bc);
	
}


#endif