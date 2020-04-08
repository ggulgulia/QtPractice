#include "hypocycloid.h"

HypoCycloid::HypoCycloid(){ }
HypoCycloid::~HypoCycloid(){ }

QPointF HypoCycloid::computePoint(const float t){
    const float x{2*scale_*(2*cos(t) + cos(2*t))};
    const float y{2*scale_*(2*sin(t) - sin(2*t))};
    return {x, y};
}

QPointF* HypoCycloid::computePoints(){
    QPointF* points = new QPointF[numPoints_];
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    unsigned i=0;
    for(float t=0; t<intervalLength_; t +=stepSize){
       points[i] = computePoint(t);
       i++;
    }
    return points;
}
unsigned HypoCycloid::getNumPoints()const noexcept{
    return numPoints_;
}
