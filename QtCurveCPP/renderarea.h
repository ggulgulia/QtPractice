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
protected:
    void paintEvent(QPaintEvent* event) Q_DECL_OVERRIDE;

signals:
private:
    QColor backgroundColor_;
    QColor shapeColor_;

public slots:
};

#endif // RENDERAREA_H
