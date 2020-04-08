#include "hypocycloid.h"

HypoCycloid::HypoCycloid(){ }
HypoCycloid::~HypoCycloid(){ }

QPointF HypoCycloid::computePoint(const float t){
    const float x{scale_*0.f};
    const float y{scale_*0.f};
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
