#include "line.hpp"

Line::Line() { }

Line::~Line(){  }

QPointF Line::computePoint(const float t){
    return {scale_*1-t, scale_*1-t};
}
QPointF* Line::computePoints(){
    QPointF* points = new QPointF[numPoints_];
    const float stepSize = intervalLength_/static_cast<float>(numPoints_);
    unsigned i=0;
    for(float t=-0.5*intervalLength_; t<0.5*intervalLength_; t +=stepSize){
       points[i] = computePoint(t);
       i++;
    }
    return points;
}
unsigned Line::getNumPoints()const noexcept{
    return numPoints_;
}
