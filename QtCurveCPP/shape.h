#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <math.h>
#include <vector>

class Shape{
  public:
    virtual QPointF computePoint(const float t) = 0;
    virtual void computePoints(std::vector<QPointF>&  points) = 0;
    virtual unsigned getNumPoints()const noexcept=0;

       Shape();
       virtual ~Shape();
};

#endif // SHAPE_H
