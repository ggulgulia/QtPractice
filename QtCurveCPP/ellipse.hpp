#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse();
    ~Ellipse();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>&  points) override;
};

#endif // ELLIPSE_HPP
