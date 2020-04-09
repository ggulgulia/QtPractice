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
    return {scale_*cos_t*cos_t*cos_t,scale_*sin_t*sin_t*sin_t};
}

void Astroid::computePoints(std::vector<QPointF>&  points){
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    float t{0.f};
    for(unsigned i=0; t<numPoints_; i++){
       points.push_back(computePoint(t));
       t += stepSize;
    }
}
unsigned Astroid::getNumPoints()const noexcept{
    return numPoints_;
}
