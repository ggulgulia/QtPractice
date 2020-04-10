#include "heart.hpp"

Heart::Heart(): Shape{2*M_PI,128, 10}
{

}

Heart::~Heart()
{

}
QPointF Heart::computePoint(const float t){
    const float x{16*sin(t)*sin(t)*sin(t)};
    const float y{((13*cos(t))-(5*cos(2*t))-(2*cos(3*t))-cos(4*t))};
    /* mul with -1 makes the heart
     * with correct orientation
     */
    QPointF point{x,-1*y};
    return this->scale_*point;
}

void Heart::computePoints(std::vector<QPointF>&  points){
    const float intervalLength{this->intervalLength_};
    const unsigned numPoints{this->numPoints_};
    const float stepSize = intervalLength/static_cast<float>(numPoints);

    float t{-0.5f*intervalLength};
    for(unsigned i=0; i<numPoints; ++i){
       points.push_back(computePoint(t));
       t += stepSize;
    }
}

