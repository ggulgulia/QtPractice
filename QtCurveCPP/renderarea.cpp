#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent):
    QWidget(parent),
    backgroundColor_{0, 0, 255},
    shapeColor_{255,255,255}
{

}

QSize RenderArea::minimumSizeHint() const{
    return QSize{200, 200};
}

QSize RenderArea::sizeHint() const {
    return QSize{400, 400};
}

void RenderArea::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    painter.setBrush(backgroundColor_);
    painter.setPen(shapeColor_);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
}
