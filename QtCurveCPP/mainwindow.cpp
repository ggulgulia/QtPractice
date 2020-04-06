#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    ui_{new Ui::MainWindow}
{
    ui_->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::on_btnAstroid_clicked()
{
    ui_->renderarea->setShapes(RenderArea::ShapeType::Astroid_);
    ui_->renderarea->setBackgroundColor(Qt::red);
    ui_->renderarea->repaint();
}

void MainWindow::on_btnCycloid_clicked()
{
     ui_->renderarea->setShapes(RenderArea::ShapeType::Cycloid_);
     ui_->renderarea->setBackgroundColor(Qt::green);
     ui_->renderarea->repaint();
}

void MainWindow::on_btnHuygensCycloid_clicked()
{
    ui_->renderarea->setShapes(RenderArea::ShapeType::HuygensCycloid_);
    ui_->renderarea->setBackgroundColor(Qt::yellow);
    ui_->renderarea->repaint();
}

void MainWindow::on_btnHypocycloid_clicked()
{
    ui_->renderarea->setShapes(RenderArea::ShapeType::HypoCycloid_);
    ui_->renderarea->setBackgroundColor(Qt::magenta);
    ui_->renderarea->repaint();
}
