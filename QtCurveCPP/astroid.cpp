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

void Astroid::computePoints(QPointF* points){
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    float t{0.f};
    for(unsigned i=0; t<numPoints_; i++){
       points[i] = computePoint(t);
       t += stepSize;
    }
}
unsigned Astroid::getNumPoints()const noexcept{
    return numPoints_;
}
