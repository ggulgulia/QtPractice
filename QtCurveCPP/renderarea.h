#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include <math.h>
#include "shape.h"
#include "astroid.h"


class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea(){
        delete shape_;
    }
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    void setBackgroundColor(QColor color);
    QColor getBackgroundColor()const;
    void setShape(Shape* shape);
    Shape* getShapes()const{return shape_;}
protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

signals:
private:
    float intervalLength_;
    float stepSize_;
    unsigned stepCount_;
    unsigned scale_;

    QColor backgroundColor_;
    QColor shapeColor_;
    Shape* shape_{nullptr} ;

    void transformPoints(QPointF* points, const QPoint point,
                                     const unsigned numPoints);

public slots:
};

#endif // RENDERAREA_H
