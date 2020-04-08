#include "huygenscycloid.h"

HuygensCycloid::HuygensCycloid(){}
HuygensCycloid::~HuygensCycloid(){}
QPointF HuygensCycloid::computePoint(const float t){
    const float x{scale_*4*(3*cos(t) -cos(3*t))};
    const float y{scale_*4*(3*sin(t) - sin(3*t))};
    return {x, y};
}

QPointF* HuygensCycloid::computePoints(){
    QPointF* points = new QPointF[numPoints_];
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    unsigned i=0;
    for(float t=0; t<intervalLength_; t +=stepSize){
       points[i] = computePoint(t);
       i++;
    }
    return points;
}
unsigned HuygensCycloid::getNumPoints()const noexcept{
    return numPoints_;
}
