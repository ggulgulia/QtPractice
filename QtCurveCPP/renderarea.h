#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <QPen>
#include <math.h>
#include "shape.h"
#include "astroid.h"


class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setBackgroundColor(QColor color)noexcept;
    QColor getBackgroundColor()const noexcept;
    void setShapeColor(QColor color)noexcept;
    QColor getShapeColor()const noexcept;
    void setPenThickness(const float thickness) noexcept;
    float getPenThickness()const noexcept;
    void setShape(Shape* shape);
    void setScale(const float scale);
    float getScale()const noexcept;
    Shape* getShapes()const{return shape_;}
    void setIntervalLength(const float interLen) noexcept;
    float getIntervalLength()const noexcept;
    void setStepCounts(const unsigned steps);
    unsigned getStepCounts()const noexcept;
protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

signals:
private:

    QColor backgroundColor_;
    QPen pen_;
    std::vector<QPointF> points_;
    Shape* shape_{nullptr} ;

    void transformPoints(const QPoint point);

public slots:
};

#endif // RENDERAREA_H
