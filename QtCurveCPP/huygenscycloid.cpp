#include "huygenscycloid.h"
HuygensCycloid::HuygensCycloid():Shape{4*M_PI, 256, 4}
{

}

HuygensCycloid::~HuygensCycloid()
{

}

QPointF HuygensCycloid::computePoint(const float t){
    const float x{scale_*4*(3*cos(t) -cos(3*t))};
    const float y{scale_*4*(3*sin(t) - sin(3*t))};
    return {x, y};
}

void HuygensCycloid::computePoints(std::vector<QPointF>&  points){
    const float intervalLength{this->intervalLength_};
    const unsigned numPoints{this->numPoints_};
    const float stepSize = intervalLength/static_cast<float>(numPoints);

    float t{0.f};
    for(unsigned i=0; i<numPoints; ++i){
       points.push_back(computePoint(t));
       t +=stepSize;
    }
}
