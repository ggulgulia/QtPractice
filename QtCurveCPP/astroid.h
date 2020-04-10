#ifndef ASTROID_H
#define ASTROID_H
#include "shape.h"

class Astroid : public Shape
{
public:
    Astroid();
    ~Astroid();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>&  points) override;
};

#endif // ASTROID_H
