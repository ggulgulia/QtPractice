#ifndef HYPOCYCLOID_H
#define HYPOCYCLOID_H
#include "shape.h"

class HypoCycloid : public Shape
{
private:
    float intervalLength_{2*M_PI};
    unsigned numPoints_{256};
    unsigned scale_{15};

public:
    HypoCycloid();
    ~HypoCycloid();
    QPointF computePoint(const float t) override;
    void computePoints(QPointF* points) override;
    unsigned getNumPoints()const noexcept override;
};

#endif // HYPOCYCLOID_H
