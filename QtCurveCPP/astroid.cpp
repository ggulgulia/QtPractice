#include "astroid.h"

Astroid::Astroid()
{

}

Astroid::~Astroid()
{

}

QPointF Astroid::computePoint(const float t)
{
    const float cos_t{cos(t)};
    const float sin_t{sin(t)};
    const float x{scale_*cos_t*cos_t*cos_t};
    const float y{scale_*sin_t*sin_t*sin_t};
    return {x,y};
}

QPointF* Astroid::computePoints(){

    QPointF* points = new QPointF[numPoints_];
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    unsigned i=0;
    for(float t=0; t<intervalLength_; t +=stepSize){
       points[i] = computePoint(t);
       i++;
    }
    return points;
}
unsigned Astroid::getNumPoints()const noexcept{
    return numPoints_;
}
