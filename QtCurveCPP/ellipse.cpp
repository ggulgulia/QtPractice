#include "ellipse.hpp"


Ellipse::Ellipse(): Shape{4*M_PI,160, 8}
{

}

Ellipse::~Ellipse()
{

}
QPointF Ellipse::computePoint(const float t){
    const float x{9*cos(0.5f*t)};
    const float y{4*sin(0.5f*t)};
    QPointF point{x,y};
    return this->scale_*point;
}

void Ellipse::computePoints(std::vector<QPointF>&  points){
    const float intervalLength{this->intervalLength_};
    const unsigned numPoints{this->numPoints_};
    const float stepSize = intervalLength/static_cast<float>(numPoints);

    float t{0.f};
    for(unsigned i=0; i<numPoints; ++i){
       points.push_back(computePoint(t));
       t += stepSize;
    }
}

