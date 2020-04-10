#include "shape.h"

Shape::Shape()
{

}

Shape::Shape(const float interval, const unsigned numPoints, const unsigned scale):
    intervalLength_{interval}, numPoints_{numPoints}, scale_{scale}
{

}

Shape::~Shape()
{

}

unsigned Shape::getNumPoints()const noexcept{
    return numPoints_;
}

void Shape::setScale(const float scale)
{
    if(scale < 0.0){
        throw std::invalid_argument(" negative scale value not permitted\n");
    }
    scale_ = scale;
}

float Shape::getScale() const
{
    return scale_;
}

void Shape::setIntervalLength(const float interLen)
{
    intervalLength_ = interLen;
}

float Shape::getIntervalLength() const
{
    return intervalLength_;
}
