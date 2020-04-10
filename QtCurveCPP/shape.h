#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <math.h>
#include <vector>
#include <exception>

class Shape{
protected:
    float intervalLength_;
    unsigned numPoints_;
    unsigned scale_;
  public:
    virtual QPointF computePoint(const float t) = 0;
    virtual void computePoints(std::vector<QPointF>&  points) = 0;
    unsigned getNumPoints()const noexcept;
    void setScale(const float scale) noexcept;
    float getScale()const noexcept;
    void setIntervalLength(const float interLen) noexcept;
    float getIntervalLength()const noexcept;
    void setStepCounts(const unsigned numPoints)noexcept;
    unsigned getStepCounts()const noexcept;

       Shape();
       Shape(const float interval, const unsigned numPoints,
             const unsigned scale);

       virtual ~Shape();
};

#endif // SHAPE_H
