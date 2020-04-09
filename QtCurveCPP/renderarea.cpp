#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent):
    QWidget(parent),
    backgroundColor_{0, 0, 255},
    shapeColor_{255,255,255},
    shape_{new Astroid()}{      }

RenderArea::~RenderArea(){
            /* call delete only if they
            * point to a memory location */
            if(shape_) delete shape_;
            if(points_) delete[] points_;
}

QSize RenderArea::minimumSizeHint() const{
    return QSize{200, 200};
}

QSize RenderArea::sizeHint() const {
    return QSize{400, 400};
}


void RenderArea::setShape(Shape* shape){
    //free memory
    if(shape_){ delete shape_;}
    shape_ = shape;
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

    //if(points_){delete[] points_;}
     const unsigned numPoints{shape_->getNumPoints()};
     points_ = new QPointF[numPoints];
     shape_->computePoints(points_);
     transformPoints(points_, center, numPoints);
     painter.drawPoints(points_, numPoints);
}
