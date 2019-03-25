#include "BezierCurve.hpp"

double BezierCurve::getLengthSum(const Bezier& points)
{
    double lengthSum = 0;
    
    for(unsigned int i = 0; i < points.size() - 1; ++i)
    {
        lengthSum += sqrt(pow(points[i+1].x - points[i].x, 2) + pow(points[i+1].y - points[i].y, 2));
    }

    return lengthSum;
}

void BezierCurve::setArcType(ArcType type)
{
    this->m_type = type;
}

int BezierCurve::setBezierCurve(const Bezier& points)
{
    if(points.empty())
    {
        std::cerr << "Error: no points given" << std::endl;
        return -1;
    }
    else if(points.size() == 1)
    {
        std::cerr << "Error: slider cannot have a single point, at least 2 required(how do you even do a slider with a single point, wtf)" << std::endl;
        return -1;
    }
    else if(points.size() >= 2)
    {
        if(points.begin()[0] == points.begin()[1])
        {
            std::cerr << "Error: the first point is a red anchor, please make it normal" << std::endl;
            return -1;
        }
        else if(points.end()[-2] == points.end()[-1])
        {
            std::cerr << "Error: the last point is a red anchor, please make it normal" << std::endl;
            return -1;
        }
        
        this->m_points = points;
        this->m_totalPoints = points.size();
        return 0;
        
    }
}

void BezierCurve::setSegmentAmount(int amount)
{   
    this->m_userTotalArcPoints = amount;
}

void BezierCurve::printReport()
{
    std::cout << "\n";
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "             Osu!Assist ~ Report                " << std::endl;
    std::cout << "Total slider points: " << m_totalPoints << std::endl;
    std::cout << "Total amount of segments created: " << m_userTotalArcPoints << std::endl;
    std::cout << "Slider length: " << m_sliderLength << std::endl;
    std::cout << "Total of " << m_arcPoints.size() << " points were calculated during the program running" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}

void BezierCurve::process()
{
    
    
    for(unsigned int i = 0; i < m_totalPoints; i++) 
    {
        this->m_segment.push_back(this->m_points[i]);
            
        if(i+1 == m_totalPoints) 
        {
            _calculateArc();
            this->m_segment.clear();
        }
            
        if(this->m_points[i] == this->m_points[i+1])
        {
            _calculateArc();	
            this->m_segment.clear();
        }
                
    }
    
    convertToScreen(this->m_arcPoints); 
    
}

void BezierCurve::_calculateArc()
{
    Bezier segmentCopy; 
    
    double segmentLength = getLengthSum(this->m_segment); 
    int segmentPoints = this->m_segment.size();
    
    double precision = 0.0; 
    double precisionAdd = 1 / (segmentLength * 5);
    
    convertToNormal(this->m_segment); 
    
    for(unsigned int k = 0; k < (segmentLength * 5); k++) 
    {
        segmentCopy = this->m_segment; 
        unsigned int layers = segmentPoints - 1; 

        while (layers > 0) 
        {
            for (unsigned int i = 0; i < layers; i++)
            {
                segmentCopy[i] = segmentCopy[i] + precision * (segmentCopy[i+1] - segmentCopy[i]);
            }
            layers--;
        }
        
        this->m_arcPoints.push_back(segmentCopy[0]); 
        
        precision += precisionAdd; 
        
    }
    
}


void BezierCurve::pickSegmentPoints()
{
    int actualPoints = m_userTotalArcPoints - 1; 
    double arcLength = getLengthSum(m_arcPoints);
    
    this->m_sliderLength = arcLength;
    
    double lengthAdd = arcLength / actualPoints; 
    double lengthTrigger = 0.0f;
    
    double distance = 0.0f;
    
    for(int i = 0; i < m_arcPoints.size()-1; i++)
    {

        if(round(distance) == round(lengthTrigger))
        {
            std::cout << m_arcPoints[i] << std::endl;
            
            m_result.push_back(m_arcPoints[i]);
            lengthTrigger += lengthAdd;
            
        }
        
        distance += sqrt(pow(m_arcPoints[i+1].x - m_arcPoints[i].x, 2) + pow(m_arcPoints[i+1].y - m_arcPoints[i].y, 2));
    }
    
}


	
