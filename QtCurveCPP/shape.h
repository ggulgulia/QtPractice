#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <math.h>

class Shape{
  public:
    virtual QPointF computePoint(const float t) = 0;
    virtual QPointF* computePoints() = 0;
    virtual unsigned getNumPoints()const noexcept=0;

       Shape();
       virtual ~Shape();
};

#endif // SHAPE_H
