#include "line.hpp"

Line::Line(): Shape{100.0f, 100, 10}
{

}

Line::~Line()
{

}

QPointF Line::computePoint(const float t){
    return {scale_*(1-t), scale_*(1-t)};
}
void Line::computePoints(std::vector<QPointF>&  points){
    const float intervalLength{this->intervalLength_};
    const unsigned numPoints{this->numPoints_};
    const float stepSize = intervalLength/static_cast<float>(numPoints);

    float t{-0.5f*intervalLength};
    for(unsigned i=0; i<numPoints; ++i){
       points.push_back(computePoint(t));
       t +=stepSize;
    }
}
