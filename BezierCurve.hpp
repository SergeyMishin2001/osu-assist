#ifndef BEZIERCURVE_HPP_INCLUDED
#define BEZIERCURVE_HPP_INCLUDED

#include <vector>
#include <cmath>

#include "Point.hpp"
#include "Convert.hpp"


typedef std::vector<Point> Bezier;

class BezierCurve
{
public: enum class ArcType;
private:
//

// FIELDS
	ArcType m_type;
	
	Bezier m_points;
	Bezier m_segment;
	Bezier m_arcPoints;
	Bezier m_result;
	
// VERBOSE
	int m_userTotalArcPoints;
    int m_totalPoints;
    double m_sliderLength;

	
// METHODS
	static double getLengthSum(const Bezier& points);

    void _calculateArc();
	
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
	int setBezierCurve(const Bezier& points);
	
	void setArcType(ArcType type);
	
	void setSegmentAmount(int amount);
	
	void process();
    
    void pickSegmentPoints();
    
    void printReport();
	
	friend std::ostream& operator<<(std::ostream& out, const BezierCurve& bc);
	
};


#endif
