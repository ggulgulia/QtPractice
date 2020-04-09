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
    ui_->renderarea->setShape(new Astroid());
    ui_->renderarea->repaint();
    ui_->spinScale->setValue(ui_->renderarea->getScale());
}

void MainWindow::on_btnCycloid_clicked()
{
     ui_->renderarea->setShape(new Cycloid());
     ui_->renderarea->repaint();
     ui_->spinScale->setValue(ui_->renderarea->getScale());
}

void MainWindow::on_btnHuygensCycloid_clicked()
{
    ui_->renderarea->setShape(new HuygensCycloid());
    ui_->renderarea->repaint();
    ui_->spinScale->setValue(ui_->renderarea->getScale());
}

void MainWindow::on_btnHypocycloid_clicked()
{
    ui_->renderarea->setShape(new HypoCycloid());
    ui_->renderarea->repaint();
}

void MainWindow::on_btnLine_clicked()
{
    ui_->renderarea->setShape(new Line());
    ui_->renderarea->repaint();
    ui_->spinScale->setValue(ui_->renderarea->getScale());
}

void MainWindow::on_spinScale_valueChanged(double value)
{
    ui_->renderarea->setScale(static_cast<float>(value));
    ui_->renderarea->repaint();
}
