#ifndef CYCLOID_H
#define CYCLOID_H
#include "shape.h"

class Cycloid : public Shape
{
private:
    float intervalLength_{8*M_PI};
    unsigned numPoints_{128};
    unsigned scale_{4};

public:
    Cycloid();
    ~Cycloid();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>&  points) override;
    unsigned getNumPoints()const noexcept override;
    void setScale(const float scale) override;
    float getScale()const override;
    void setIntervalLength(const float interLen) override;
    float getIntervalLength()const override;
};

#endif // CYCLOID_H
