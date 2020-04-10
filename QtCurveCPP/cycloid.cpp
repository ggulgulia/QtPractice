#include "cycloid.h"

Cycloid::Cycloid(): Shape{8*M_PI,128, 4}
{

}

Cycloid::~Cycloid()
{

}
QPointF Cycloid::computePoint(const float t){
    const float x{2*this->scale_*(1 - cos(t))};
    const float y{2*this->scale_*(t - sin(t))};
    return {x, y};
}

void Cycloid::computePoints(std::vector<QPointF>&  points){
    const float intervalLength{this->intervalLength_};
    const unsigned numPoints{this->numPoints_};
    const float stepSize = intervalLength/static_cast<float>(numPoints);

    float t{-0.5f*intervalLength};
    for(unsigned i=0; i<numPoints; ++i){
       points.push_back(computePoint(t));
       t += stepSize;
    }
}
