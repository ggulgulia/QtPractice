#include "line.hpp"

Line::Line() { }

Line::~Line(){  }

QPointF Line::computePoint(const float t){
    return {scale_*(1-t), scale_*(1-t)};
}
void Line::computePoints(std::vector<QPointF>&  points){
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    float t{-0.5f*intervalLength_};
    for(unsigned i=0; i<numPoints_; ++i){
       points.push_back(computePoint(t));
       t +=stepSize;
    }
}
unsigned Line::getNumPoints()const noexcept{
    return numPoints_;
}

void Line::setScale(const float scale)
{
    if(scale < 0.0){
        throw std::invalid_argument(" negative scale value not permitted\n");
    }
    scale_ = scale;
}

float Line::getScale() const
{
    return scale_;
}

void Line::setIntervalLength(const float interLen)
{
    intervalLength_ = interLen;
}

float Line::getIntervalLength() const
{
    return intervalLength_;
}
