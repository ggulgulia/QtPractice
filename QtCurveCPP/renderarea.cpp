#include "renderarea.h"

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
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
}
