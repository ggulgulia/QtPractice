#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

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

private:
    Ui::MainWindow *ui_;
};

#endif // MAINWINDOW_H
