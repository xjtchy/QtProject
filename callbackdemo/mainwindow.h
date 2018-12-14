#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static void myCallback(int *num);
private slots:
    void onExecClicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
