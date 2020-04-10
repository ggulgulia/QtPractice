#ifndef HEART_HPP
#define HEART_HPP
#include "shape.h"

class Heart : public Shape
{
public:
     Heart();
    ~Heart();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>&  points) override;
};

#endif // HEART_HPP
