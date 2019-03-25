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
        std::cerr << "Error: slider cannot have one points, at least 2 required" << std::endl;
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
        
        std::cout << points.size() << std::endl;
        
        this->m_points = points;
        return 0;
        
    }
}

void BezierCurve::setSegmentAmount(int amount)
{   
	this->m_userTotalArcPoints = amount;
}

void BezierCurve::process()
{
    for(unsigned int i = 0; i < this->m_points.size(); i++) 
    {
        this->m_segment.push_back(this->m_points[i]);
            
        if(i+1 == this->m_points.size()) 
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

void BezierCurve::print()
{
    for(const auto &i : m_arcPoints)
    {
        std::cout << i << std::endl;
    }
    
    std::cout << "Total points calculated: " << m_arcPoints.size() << std::endl;
}

void BezierCurve::_calculateArc()
{
    std::cout << "Segment-------------" << std::endl;
	Bezier segmentCopy; // Создаём вектор для копирования вектора сегмента
    
	double segmentLength = getLengthSum(this->m_segment); // Получаем длину между изначальными точками 
    int segmentPoints = this->m_segment.size(); // Получаем кол-во точек из которые задают кривую
    
    double precision = 0.0; // Множитель вычисления кривой
	double precisionAdd = 1 / (segmentLength * 2); // Слагаемое к множителю
	
    convertToNormal(this->m_segment); // Конвертация координат экрана в декартовые координаты
    
	for(unsigned int k = 0; k < (segmentLength * 2); k++) // <- Здесь начинается вычисление новой точки
	{
		segmentCopy = this->m_segment; /*Копируем вектор сегмента в новый вектор. Так как вектор меняется 
                                        при вычислениях и нам нужно сохранить оригинальные данные */
		
		unsigned int layers = segmentPoints - 1; // Кол-во "слоёв" при вычислении кривой
		
		while (layers > 0) // процесс вычисления одной точки
		{
        	for (unsigned int i = 0; i < layers; i++)
			{
            	segmentCopy[i] = segmentCopy[i] + precision * (segmentCopy[i+1] - segmentCopy[i]);
			}
        	layers--;
		}
        
		this->m_arcPoints.push_back(segmentCopy[0]); // Добавляем точку в массив вычисленных точек
		
		precision += precisionAdd; // Увеличиваем процент и вычисляем следующие точки
		
	}
	
}

/*
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
	
	
*/
