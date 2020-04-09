#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <math.h>
#include <vector>
#include <exception>

class Shape{
  public:
    virtual QPointF computePoint(const float t) = 0;
    virtual void computePoints(std::vector<QPointF>&  points) = 0;
    virtual unsigned getNumPoints()const noexcept=0;
    virtual void setScale(const float scale) = 0;
    virtual float getScale()const = 0;

       Shape();
       virtual ~Shape();
};

#endif // SHAPE_H
