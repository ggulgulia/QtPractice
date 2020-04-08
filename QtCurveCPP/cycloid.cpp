#include "cycloid.h"

Cycloid::Cycloid(){ }
Cycloid::~Cycloid(){ }
QPointF Cycloid::computePoint(const float t){
    const float x{2*scale_*(1 - cos(t))};
    const float y{2*scale_*(t - sin(t))};
    return {x, y};
}

QPointF* Cycloid::computePoints(){
    QPointF* points = new QPointF[numPoints_];
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    unsigned i=0;
    for(float t=-0.5*intervalLength_; t<0.5*intervalLength_; t +=stepSize){
       points[i] = computePoint(t);
       i++;
    }
    return points;
}
unsigned Cycloid::getNumPoints()const noexcept{
    return numPoints_;
}
