#ifndef HYPOCYCLOID_H
#define HYPOCYCLOID_H
#include "shape.h"

class HypoCycloid : public Shape
{
private:
    float intervalLength_{4*M_PI};
    unsigned numPoints_{256};
    unsigned scale_{4};

public:
    HypoCycloid();
    ~HypoCycloid();
    QPointF computePoint(const float t) override;
    QPointF* computePoints() override;
    unsigned getNumPoints()const noexcept override;
};

#endif // HYPOCYCLOID_H
