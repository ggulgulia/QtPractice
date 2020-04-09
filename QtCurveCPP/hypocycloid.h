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
    void computePoints(std::vector<QPointF>&  points) override;
    unsigned getNumPoints()const noexcept override;
    void setScale(const float scale) override;
    float getScale()const override;
    void setIntervalLength(const float interLen) override;
    float getIntervalLength()const override;
};

#endif // HYPOCYCLOID_H
