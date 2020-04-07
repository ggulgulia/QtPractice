#include "renderarea.h"
#include <math.h>

RenderArea::RenderArea(QWidget *parent):
    QWidget(parent),
    backgroundColor_{0, 0, 255},
    shapeColor_{255,255,255},
    shape_{ShapeType::Astroid_}
{

}

QSize RenderArea::minimumSizeHint() const{
    return QSize{200, 200};
}

QSize RenderArea::sizeHint() const {
    return QSize{400, 400};
}

QPointF RenderArea::computeAstroid(const float t){

    const float cos_t{cos(t)};
    const float sin_t{sin(t)};
    const float x{cos_t*cos_t*cos_t};
    const float y{sin_t*sin_t*sin_t};
    return {x,y};
}
void RenderArea::paintEvent(QPaintEvent* event){
    Q_UNUSED(event);
    QPainter painter(this);

    switch(shape_){
        case ShapeType::Astroid_:
        backgroundColor_ = Qt::red;
        break;
    case ShapeType::Cycloid_:
        backgroundColor_ = Qt::green;
        break;
    case ShapeType::HuygensCycloid_:
        backgroundColor_ = Qt::yellow;
        break;
    case ShapeType::HypoCycloid_:
        backgroundColor_ = Qt::magenta;
        break;
    default:
        break;
    }

    painter.setBrush(backgroundColor_);
    painter.setPen(shapeColor_);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    QPoint center{rect().center()};
    float intervalLen{2*M_PI};
    unsigned stepCount{64};
    const unsigned scale{40};
    float stepSize = intervalLen/static_cast<float>(stepCount);
    for(float t=0; t<intervalLen; t += stepSize){
        QPointF point = computeAstroid(t);
        QPoint pixel{point.x()*scale+center.x(), point.y()*scale+center.y()};
        painter.drawPoint(pixel);
    }
}
