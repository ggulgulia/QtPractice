#include "cycloid.h"

Cycloid::Cycloid(): Shape{4*M_PI,128, 10}
{

}

Cycloid::~Cycloid()
{

}
QPointF Cycloid::computePoint(const float t){
    const float x{(1 - cos(t))};
    const float y{(t - sin(t))};
    /** get a horizontal hypocycloid */
    QPointF point{y,-1*x};
    return this->scale_*point;
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
