#ifndef HYPOCYCLOID_H
#define HYPOCYCLOID_H
#include "shape.h"

class HypoCycloid : public Shape
{
public:
    HypoCycloid();
    ~HypoCycloid();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>&  points) override;
};

#endif // HYPOCYCLOID_H
