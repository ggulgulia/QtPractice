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

void Shape::setScale(const float scale) noexcept
{
    scale_ = scale;
}

float Shape::getScale() const noexcept
{
    return scale_;
}

void Shape::setIntervalLength(const float interLen) noexcept
{
    intervalLength_ = interLen;
}

float Shape::getIntervalLength() const noexcept
{
    return intervalLength_;
}

void Shape::setStepCounts(const unsigned numPoints) noexcept
{
    numPoints_ = numPoints;
}

unsigned Shape::getStepCounts() const noexcept
{
    return numPoints_;
}
