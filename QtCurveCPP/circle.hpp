#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.h"

class Circle : public Shape
{
public:
    Circle();
    ~Circle();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>&  points) override;
};

#endif // CIRCLE_HPP
