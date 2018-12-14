#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ctest.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->exec,SIGNAL(clicked(bool)),this,SLOT(onExecClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myCallback(int *num)
{
    qDebug()<<"回调函数已执行,data:"<<*num;
    int count =*num * 20;
    qDebug()<<"处理后的数据："<<count;
}

void MainWindow::onExecClicked()
{
    CTest *test = new CTest(myCallback);
    test->startExec();
}
