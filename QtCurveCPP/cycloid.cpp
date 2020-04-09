#include "cycloid.h"

Cycloid::Cycloid(){ }
Cycloid::~Cycloid(){ }
QPointF Cycloid::computePoint(const float t){
    const float x{2*scale_*(1 - cos(t))};
    const float y{2*scale_*(t - sin(t))};
    return {x, y};
}

void Cycloid::computePoints(QPointF* points){
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    float t{-0.5f*intervalLength_};
    for(unsigned i=0; i<numPoints_; ++i){
       points[i] = computePoint(t);
       t += stepSize;
    }
}
unsigned Cycloid::getNumPoints()const noexcept{
    return numPoints_;
}
