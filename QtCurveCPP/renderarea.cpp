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

void RenderArea::transformPoints(const QPoint point){
    QPointF pointf = static_cast<QPointF>(point);
    for(unsigned i=0; i<points_.size(); ++i){
        points_[i]+= pointf;
    }
}

void RenderArea::paintEvent(QPaintEvent* event){
  QPainter painter(this);

    painter.setBrush(backgroundColor_);
    painter.setPen(shapeColor_);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    QPoint center{rect().center()};

     const unsigned numPoints{shape_->getNumPoints()};
     points_.clear();
     shape_->computePoints(points_);
     transformPoints(center);
     for(unsigned i=0; i<numPoints; ++i){
         painter.drawPoint(points_[i]);
     }
}
