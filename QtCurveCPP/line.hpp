#ifndef LINE_HPP
#define LINE_HPP

#include "shape.h"

class Line : public Shape
{
public:
     Line();
    ~ Line();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>& points) override;

};

#endif // LINE_HPP
