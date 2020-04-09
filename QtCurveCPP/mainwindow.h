#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "shape.h"
#include "astroid.h"
#include "cycloid.h"
#include "huygenscycloid.h"
#include "hypocycloid.h"
#include "line.hpp"

/**
 * This is a different main
 * window class than the one that
 * already exists
 */
namespace Ui {
class MainWindow;
}

/**
 * @brief this is another main window class
 * that inherited from QMainWindow
 * This is different from the one abve
 */
class MainWindow : public QMainWindow
{
    /* Q_OBJECT is a protected member in QMainWindow
     * allows user to access all Qt core functionalities
     */
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnAstroid_clicked();

    void on_btnCycloid_clicked();

    void on_btnHuygensCycloid_clicked();

    void on_btnHypocycloid_clicked();

    void on_btnLine_clicked();

    void on_spinScale_valueChanged(double arg1);

private:
    Ui::MainWindow *ui_;
};

#endif // MAINWINDOW_H
