#include "astroid.h"

Astroid::Astroid()
{

}

Astroid::~Astroid()
{

}

QPointF Astroid::computePoint(const float t)
{
    const float cos_t{cos(t)};
    const float sin_t{sin(t)};
    const float x{cos_t*cos_t*cos_t};
    const float y{sin_t*sin_t*sin_t};
    return {x,y};
}
