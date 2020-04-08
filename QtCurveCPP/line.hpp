#ifndef LINE_HPP
#define LINE_HPP

#include "shape.h"

class Line : public Shape
{
private:
    float intervalLength_{200.0f};
    unsigned numPoints_{100};
    unsigned scale_{10};

public:
     Line();
    ~ Line();
    QPointF computePoint(const float t) override;
    QPointF* computePoints() override;
    unsigned getNumPoints()const noexcept override;

};

#endif // LINE_HPP
