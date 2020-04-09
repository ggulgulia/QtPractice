#ifndef HUYGENSCYCLOID_H
#define HUYGENSCYCLOID_H
#include "shape.h"

class HuygensCycloid : public Shape
{
private:
    float intervalLength_{4*M_PI};
    unsigned numPoints_{256};
    unsigned scale_{4};

public:
    HuygensCycloid();
    ~HuygensCycloid();
    QPointF computePoint(const float t)override;
    void computePoints(std::vector<QPointF>&  points) override;
    unsigned getNumPoints()const noexcept override;
};

#endif // HUYGENSCYCLOID_H
