#include "huygenscycloid.h"

HuygensCycloid::HuygensCycloid(){}
HuygensCycloid::~HuygensCycloid(){}
QPointF HuygensCycloid::computePoint(const float t){
    const float x{scale_*4*(3*cos(t) -cos(3*t))};
    const float y{scale_*4*(3*sin(t) - sin(3*t))};
    return {x, y};
}

void HuygensCycloid::computePoints(QPointF* points){
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    float t{0.f};
    for(unsigned i=0; i<numPoints_; ++i){
       points[i] = computePoint(t);
       t +=stepSize;
    }
}
unsigned HuygensCycloid::getNumPoints()const noexcept{
    return numPoints_;
}
