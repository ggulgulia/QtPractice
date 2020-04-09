#ifndef LINE_HPP
#define LINE_HPP

#include "shape.h"

class Line : public Shape
{
private:
    float intervalLength_{100.0f};
    unsigned numPoints_{256};
    unsigned scale_{10};

public:
     Line();
    ~ Line();
    QPointF computePoint(const float t) override;
    void computePoints(std::vector<QPointF>& points) override;
    unsigned getNumPoints()const noexcept override;
    void setScale(const float scale) override;
    float getScale()const override;
    void setIntervalLength(const float interLen) override;
    float getIntervalLength()const override;

};

#endif // LINE_HPP
