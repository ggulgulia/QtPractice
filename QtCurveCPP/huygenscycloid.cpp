#include "huygenscycloid.h"

HuygensCycloid::HuygensCycloid(){}
HuygensCycloid::~HuygensCycloid(){}
QPointF HuygensCycloid::computePoint(const float t){
    const float x{scale_*4*(3*cos(t) -cos(3*t))};
    const float y{scale_*4*(3*sin(t) - sin(3*t))};
    return {x, y};
}

void HuygensCycloid::computePoints(std::vector<QPointF>&  points){
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    float t{0.f};
    for(unsigned i=0; i<numPoints_; ++i){
       points.push_back(computePoint(t));
       t +=stepSize;
    }
}
unsigned HuygensCycloid::getNumPoints()const noexcept{
    return numPoints_;
}

void HuygensCycloid::setScale(const float scale)
{
    if(scale < 0.0){
        throw std::invalid_argument(" negative scale value not permitted\n");
    }
    scale_ = scale;
}

float HuygensCycloid::getScale() const
{
    return scale_;
}

void HuygensCycloid::setIntervalLength(const float interLen)
{
    intervalLength_ = interLen;
}

float HuygensCycloid::getIntervalLength() const
{
    return intervalLength_;
}
