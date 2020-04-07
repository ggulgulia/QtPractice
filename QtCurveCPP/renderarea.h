#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    enum class ShapeType
    {
        Astroid_,
        Cycloid_,
        HuygensCycloid_,
        HypoCycloid_
    };

    void setBackgroundColor(QColor color){backgroundColor_ = color;}
    QColor getBackgroundColor()const{return backgroundColor_;}

    void setShapes(ShapeType shape);
    ShapeType getShapes()const{return shape_;}
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
    ShapeType shape_;

    QPointF computeAstroid(const float t);
    void onShapeChange();

public slots:
};

#endif // RENDERAREA_H
