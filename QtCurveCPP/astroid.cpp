#include "astroid.h"

Astroid::Astroid(): Shape{2*M_PI,256,90}
{

}

Astroid::~Astroid()
{

}

QPointF Astroid::computePoint(const float t)
{
    const float cos_t{cos(t)};
    const float sin_t{sin(t)};
    return {this->scale_*cos_t*cos_t*cos_t, this->scale_*sin_t*sin_t*sin_t};
}

void Astroid::computePoints(std::vector<QPointF>&  points){
    const float intervalLength{this->intervalLength_};
    const unsigned numPoints{this->numPoints_};
    const float stepSize = intervalLength/static_cast<float>(numPoints);

    float t{0.f};
    for(unsigned i=0; t<numPoints; i++){
       points.push_back(computePoint(t));
       t += stepSize;
    }
}
