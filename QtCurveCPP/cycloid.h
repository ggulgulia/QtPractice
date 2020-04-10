#ifndef CYCLOID_H
#define CYCLOID_H
#include "shape.h"

class Cycloid : public Shape
{
public:
    Cycloid();
    ~Cycloid();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>&  points) override;
};

#endif // CYCLOID_H
