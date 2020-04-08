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
    QPointF* computePoints() override;
    unsigned getNumPoints()const noexcept override;
};

#endif // CYCLOID_H
