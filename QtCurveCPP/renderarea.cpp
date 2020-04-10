#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent):
    QWidget(parent),
    backgroundColor_{0, 0, 255},
    shape_{new Astroid()}{
    pen_.setWidth(2);
    pen_.setColor(Qt::white);
}

RenderArea::~RenderArea(){
            /* call delete only if they
            * point to a memory location */
            if(shape_) delete shape_;
}

QSize RenderArea::minimumSizeHint() const{
    return QSize{400, 400};
}

QSize RenderArea::sizeHint() const {
    return QSize{400, 400};
}

void RenderArea::setBackgroundColor(QColor color) noexcept
{
    backgroundColor_ = color;
    repaint();
}
QColor RenderArea::getBackgroundColor()const noexcept
{
    return backgroundColor_;
}

void RenderArea::setShapeColor(QColor color) noexcept
{
    pen_.setColor(color);
    repaint();
}

QColor RenderArea::getShapeColor() const noexcept
{
    return pen_.color();
}

void RenderArea::setPenThickness(const float thickness) noexcept
{
    pen_.setWidth(thickness);
    repaint();
}

float RenderArea::getPenThickness() const noexcept
{
    return pen_.width();
}

void RenderArea::setShape(Shape* shape){
    if(shape == nullptr){
            throw std::invalid_argument("negative scale value not permitted\n");
    }
    if(shape_){ delete shape_;}
    shape_ = shape;
    repaint();
}

void RenderArea::setScale(const float scale){
    if(scale < 0.0){
        throw std::invalid_argument("negative scale value not permitted\n");
    }
    if(shape_){
        shape_->setScale(scale);
    }
}

float RenderArea::getScale() const noexcept
{
    return shape_->getScale();
}

void RenderArea::setIntervalLength(const float interLen) noexcept
{
    if(shape_){
        shape_->setIntervalLength(interLen);
    }

}

float RenderArea::getIntervalLength() const noexcept
{
    return shape_->getIntervalLength();
}

void RenderArea::setStepCounts(const unsigned steps)
{
    if(shape_){
        shape_->setStepCounts(steps);
    }
}

unsigned RenderArea::getStepCounts() const noexcept
{
    return shape_->getStepCounts();
}

void RenderArea::transformPoints(const QPoint point){
    QPointF pointf = static_cast<QPointF>(point);
    for(unsigned i=0; i<points_.size(); ++i){
        points_[i]+= pointf;
    }
}

void RenderArea::paintEvent(QPaintEvent* event){
    Q_UNUSED(event);
  QPainter painter(this);

    painter.setBrush(backgroundColor_);
    painter.setPen(pen_);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.drawRect(this->rect());
    QPoint center{rect().center()};

     const unsigned numPoints{shape_->getNumPoints()};
     points_.clear();
     shape_->computePoints(points_);
     transformPoints(center);
     for(unsigned i=1; i<numPoints; ++i){
         painter.drawLine(points_[i], points_[i-1]);
     }
}
