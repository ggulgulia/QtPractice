#ifndef ASTROID_H
#define ASTROID_H
#include "shape.h"

class Astroid : public Shape
{
private:
    float intervalLength_{2*M_PI};
    unsigned numPoints_{256};
    unsigned scale_{96};
    /**
        scale_ = 96;
        intervalLength_ = 2*M_PI;
        stepCount_ = 256;
        */
public:
    Astroid();
    ~Astroid();
    QPointF computePoint(const float t) override;
    void computePoints(QPointF* points) override;
    unsigned getNumPoints()const noexcept override;
};

#endif // ASTROID_H
