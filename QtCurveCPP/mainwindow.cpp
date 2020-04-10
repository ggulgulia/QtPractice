#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    ui_{new Ui::MainWindow}
{
    ui_->setupUi(this);
    update();
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::on_btnAstroid_clicked()
{
    ui_->renderarea->setShape(new Astroid());
    update();
}

void MainWindow::on_btnCycloid_clicked()
{
     ui_->renderarea->setShape(new Cycloid());
     update();
}

void MainWindow::on_btnHuygensCycloid_clicked()
{
    ui_->renderarea->setShape(new HuygensCycloid());
    update();
}

void MainWindow::on_btnHypocycloid_clicked()
{
    ui_->renderarea->setShape(new HypoCycloid());
    update();
}

void MainWindow::on_btnCircle_clicked()
{
 ui_->renderarea->setShape(new Circle());
 update();
}

void MainWindow::on_btnHeart_clicked()
{
 ui_->renderarea->setShape(new Heart());
}


void MainWindow::on_btnEllipse_clicked()
{
    ui_->renderarea->setShape(new Ellipse());
}

void MainWindow::on_btnLine_clicked()
{
    ui_->renderarea->setShape(new Line());
    update();

}

void MainWindow::on_spinScale_valueChanged(double value)
{
    ui_->renderarea->setScale(static_cast<float>(value));
    ui_->renderarea->repaint();
}

void MainWindow::on_spinInterval_valueChanged(double value)
{
    ui_->renderarea->setIntervalLength(static_cast<float>(value));
     ui_->renderarea->repaint();

}

void MainWindow::on_spinSteps_valueChanged(int numSteps)
{
    ui_->renderarea->setStepCounts(static_cast<unsigned>(numSteps));
    ui_->renderarea->repaint();
}


void MainWindow::update()
{
     ui_->spinScale->setValue(ui_->renderarea->getScale());
     ui_->spinInterval->setValue(ui_->renderarea->getIntervalLength());
     ui_->spinSteps->setValue(ui_->renderarea->getStepCounts());
}

void MainWindow::on_btnBackground_clicked()
{
    QColor color = QColorDialog::getColor(ui_->renderarea->getBackgroundColor(), this, "change background color");
    ui_->renderarea->setBackgroundColor(color);
}

void MainWindow::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(ui_->renderarea->getShapeColor(), this, "select line color");
    ui_->renderarea->setShapeColor(color);
}

void MainWindow::on_spinBrushSize_valueChanged(double brushSize)
{
    ui_->renderarea->setPenThickness(static_cast<float>(brushSize));
}
