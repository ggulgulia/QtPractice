#ifndef HUYGENSCYCLOID_H
#define HUYGENSCYCLOID_H
#include "shape.h"

class HuygensCycloid : public Shape
{
public:
    HuygensCycloid();
    ~HuygensCycloid();
    QPointF computePoint(const float t)override;
};

#endif // HUYGENSCYCLOID_H
