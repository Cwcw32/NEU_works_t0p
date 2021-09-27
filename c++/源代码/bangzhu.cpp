#include "bangzhu.h"
#include "ui_bangzhu.h"

bangzhu::bangzhu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bangzhu)
{
    ui->setupUi(this);
    pages=1;
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setVisible(false);
    QPixmap A;
    A.load(":/new1/p6.png");
    A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    ui->label->setPixmap(A);

}

bangzhu::~bangzhu()
{
    delete ui;
}
//*******************************************************************返回菜单----选项框
void bangzhu::on_pushButton_3_clicked()
{
    //显示父窗口
    this->parentWidget()->show();
    //删除本窗口
    delete this;
}
//*******************************************************************下一页----选项框
void bangzhu::on_pushButton_clicked()
{
    //判断页数范围，从而进行选择框的显示的改变
    if(pages<5&&pages>=1)
        pages++;
    else {
        return;
    }
    //建立图片单位用于后续图片加载
    QPixmap A;
    switch (pages) {
    case 2:{
        //重新设置相关按钮的显示
        ui->pushButton->setVisible(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_2->setEnabled(true);
        //加载资源库中预先保留的提示图片
        A.load(":/new1/p5.png");
        //调整大小
        A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

        ui->label->setPixmap(A);
    }
        break;
    case 3:{
        //重新设置相关按钮的显示
        ui->pushButton->setVisible(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_2->setEnabled(true);
        //加载资源库中预先保留的提示图片
        A.load(":/new1/p4.png");
        A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->label->setPixmap(A);
    }
        break;
    case 4:{
        //重新设置相关按钮的显示
        ui->pushButton->setVisible(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_2->setEnabled(true);
        //加载资源库中预先保留的提示图片
        A.load(":/new1/p8.png");
        A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->label->setPixmap(A);
    }
        break;
    case 5:{
        //重新设置相关按钮的显示
        ui->pushButton->setVisible(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_2->setEnabled(true);
        //加载资源库中预先保留的提示图片
        A.load(":/new1/p7.png");
        A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->label->setPixmap(A);
    }
        break;
    }
}
//*******************************************************************上一页----选项框
void bangzhu::on_pushButton_2_clicked()
{
    //判断页数范围，从而进行选择框的显示的改变
    if(pages>1)
        pages--;
    else {
        return;
    }
    QPixmap A;
    switch (pages) {
    case 1:{
        //重新设置相关按钮的显示
        ui->pushButton->setVisible(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_2->setEnabled(false);
        //加载资源库中预先保留的提示图片
        A.load(":/new1/p6.png");
        A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->label->setPixmap(A);
    }
        break;
    case 2:{
        //重新设置相关按钮的显示
        ui->pushButton->setVisible(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_2->setEnabled(true);
        //加载资源库中预先保留的提示图片
        A.load(":/new1/p5.png");

        A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->label->setPixmap(A);
    }
        break;
    case 3:{
        //重新设置相关按钮的显示
        ui->pushButton->setVisible(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_2->setEnabled(true);
        //加载资源库中预先保留的提示图片
        A.load(":/new1/p4.png");
        A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->label->setPixmap(A);
    }
        break;
    case 4:{
        //重新设置相关按钮的显示
        ui->pushButton->setVisible(true);
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_2->setEnabled(true);
        //加载资源库中预先保留的提示图片
        A.load(":/new1/p8.png");
        A=A.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->label->setPixmap(A);
    }
        break;
    }
}
