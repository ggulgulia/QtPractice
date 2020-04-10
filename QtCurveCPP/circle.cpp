#include "circle.hpp"

Circle::Circle(): Shape{2*M_PI,128, 10}
{

}

Circle::~Circle()
{

}
QPointF Circle::computePoint(const float t){
    const float x{2*this->scale_*cos(t)};
    const float y{2*this->scale_*sin(t)};
    return {x, y};
}

void Circle::computePoints(std::vector<QPointF>&  points){
    const float intervalLength{this->intervalLength_};
    const unsigned numPoints{this->numPoints_};
    const float stepSize = intervalLength/static_cast<float>(numPoints);

    float t{0.f};
    for(unsigned i=0; i<numPoints; ++i){
       points.push_back(computePoint(t));
       t += stepSize;
    }
}
