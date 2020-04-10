#include "hypocycloid.h"
/**
float intervalLength_{2*M_PI};
unsigned numPoints_{256};
unsigned scale_{15};
**/
HypoCycloid::HypoCycloid():Shape{2*M_PI, 256, 15}
{

}

HypoCycloid::~HypoCycloid()
{

}

QPointF HypoCycloid::computePoint(const float t){
    const float x{2*scale_*(2*cos(t) + cos(2*t))};
    const float y{2*scale_*(2*sin(t) - sin(2*t))};
    return {x, y};
}

void HypoCycloid::computePoints(std::vector<QPointF>&  points){
    const float intervalLength{this->intervalLength_};
    const unsigned numPoints{this->numPoints_};
    const float stepSize = intervalLength/static_cast<float>(numPoints);

    float t{0.f};
    for(unsigned i=0; i<numPoints; ++i){
       points.push_back(computePoint(t));
       t +=stepSize;
    }
}
