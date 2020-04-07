#include "renderarea.h"
#include <math.h>

RenderArea::RenderArea(QWidget *parent):
    QWidget(parent),
    backgroundColor_{0, 0, 255},
    shapeColor_{255,255,255},
    shape_{ShapeType::Astroid_}
{
    onShapeChange();
}

QSize RenderArea::minimumSizeHint() const{
    return QSize{200, 200};
}

QSize RenderArea::sizeHint() const {
    return QSize{400, 400};
}

void RenderArea::setShapes(ShapeType shape){
    shape_ = shape;
    onShapeChange();
}
QPointF RenderArea::computeAstroid(const float t){

    const float cos_t{cos(t)};
    const float sin_t{sin(t)};
    const float x{cos_t*cos_t*cos_t};
    const float y{sin_t*sin_t*sin_t};
    return {x,y};
}

void RenderArea::onShapeChange(){
    switch(shape_){
        case ShapeType::Astroid_:
        backgroundColor_ = Qt::red;
        scale_ = 40;
        intervalLength_ = 2*M_PI;
        stepCount_ = 256;
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
}

void RenderArea::paintEvent(QPaintEvent* event){
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setBrush(backgroundColor_);
    painter.setPen(shapeColor_);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    QPoint center{rect().center()};

    stepSize_ = intervalLength_/static_cast<float>(stepCount_);
    for(float t=0; t<intervalLength_; t += stepSize_){
        QPointF point = computeAstroid(t);
        QPoint pixel{point.x()*scale_+center.x(), point.y()*scale_+center.y()};
        painter.drawPoint(pixel);
    }
}
