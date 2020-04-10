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
    virtual unsigned getNumPoints()const noexcept;
    virtual void setScale(const float scale);
    virtual float getScale()const;
    virtual void setIntervalLength(const float interLen);
    virtual float getIntervalLength()const;

       Shape();
       Shape(const float interval, const unsigned numPoints,
             const unsigned scale);

       virtual ~Shape();
};

#endif // SHAPE_H
