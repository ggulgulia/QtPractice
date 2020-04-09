#include "hypocycloid.h"

HypoCycloid::HypoCycloid(){ }
HypoCycloid::~HypoCycloid(){ }

QPointF HypoCycloid::computePoint(const float t){
    const float x{2*scale_*(2*cos(t) + cos(2*t))};
    const float y{2*scale_*(2*sin(t) - sin(2*t))};
    return {x, y};
}

void HypoCycloid::computePoints(std::vector<QPointF>&  points){
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    float t{0.f};
    for(unsigned i=0; i<numPoints_ ; ++i){
      points.push_back(computePoint(t));
       t +=stepSize;
    }
}
unsigned HypoCycloid::getNumPoints()const noexcept{
    return numPoints_;
}

void HypoCycloid::setScale(const float scale)
{
    if(scale < 0.0){
        throw std::invalid_argument(" negative scale value not permitted\n");
    }
    scale_ = scale;
}

float HypoCycloid::getScale() const
{
    return scale_;
}
