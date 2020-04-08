#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent):
    QWidget(parent),
    backgroundColor_{0, 0, 255},
    shapeColor_{255,255,255},
    shape_{ShapeType::Astroid_},
    shape2_{new Astroid()}
{
}

QSize RenderArea::minimumSizeHint() const{
    return QSize{200, 200};
}

QSize RenderArea::sizeHint() const {
    return QSize{400, 400};
}

void RenderArea::setShape(ShapeType shape){
    shape_ = shape;
}

void RenderArea::setShape(Shape* shape){
    //free memory
    if(shape2_){ delete shape2_;}
    shape2_ = shape;
}

void RenderArea::transformPoints(QPointF* points, const QPoint point,
                                 const unsigned numPoints){
    QPointF pointf = static_cast<QPointF>(point);
    for(unsigned i=0; i<numPoints; ++i){
        points[i]+= pointf;
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

     QPointF* points = shape2_->computePoints();
     const unsigned numPoints{shape2_->getNumPoints()};

     transformPoints(points, center, numPoints);
     painter.drawPolyline(points, numPoints);
}
