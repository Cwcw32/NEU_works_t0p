#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamescene1.h"
#include "bangzhu.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//游戏界面
void MainWindow::on_pushButton_clicked()
{
    gamescene1 *gamescen1=new gamescene1(this);
    //显示游戏界面
    gamescen1->show();
    //隐藏本界面
    this->hide();
}
//帮助界面
void MainWindow::on_pushButton_2_clicked()
{
    bangzhu *b=new bangzhu(this);
    //显示帮助节目
    b->show();
    //隐藏本界面
    this->hide();
}
//退出
void MainWindow::on_pushButton_4_clicked()
{
    QApplication::exit(0);
}
