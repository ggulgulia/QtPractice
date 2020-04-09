#include "hypocycloid.h"

HypoCycloid::HypoCycloid(){ }
HypoCycloid::~HypoCycloid(){ }

QPointF HypoCycloid::computePoint(const float t){
    const float x{2*scale_*(2*cos(t) + cos(2*t))};
    const float y{2*scale_*(2*sin(t) - sin(2*t))};
    return {x, y};
}

void HypoCycloid::computePoints(QPointF* points){
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    float t{0.f};
    for(unsigned i=0; i<numPoints_ ; ++i){
       points[i] = computePoint(t);
       t +=stepSize;
    }
}
unsigned HypoCycloid::getNumPoints()const noexcept{
    return numPoints_;
}
