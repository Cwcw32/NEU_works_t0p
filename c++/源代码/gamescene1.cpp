#include "gamescene1.h"
#include "ui_gamescene1.h"
#include <QMouseEvent>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QRect>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QEvent>
#include <QLCDNumber>
#include <QFileDialog>
#include <QFileInfo>
#include <QPixmap>
#include "fupan.h"
/*
#include <fstream>
#include <iostream>
using namespace std;
*/
gamescene1::gamescene1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gamescene1)
{
    ui->setupUi(this);    

    //设置计时器时间
    dnum=70;
    //fstream a("C:\\Users\\Administrator\\Documents\\Tencent Files\\1914048254\\FileRecv\\test\\test\\man.txt");

    //建立两个计时器单位
    id1=new QTimer(this);
    id2=new QTimer(this);
    //将超时信号与超时槽进行绑定
    connect(id1,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    connect(id2,SIGNAL(timeout()),this,SLOT(timerUpdate()));


    //设置玩家颜色
    player1.color=bl;
    player2.color=wh;
    //打开鼠标追踪
    setMouseTracking(true);
    //qDebug()<<hasMouseTracking()<<endl;

    //设置当前玩家颜色
    rc=bl;
    //初始化棋盘
    initialpan();
    /*
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
    {
        a>>board[j][i];
        if(i==14&&j==14)
            break;
        qp.push_back(QPoint(i,j));
    }

    a.close();
    */
    repaint();
}

gamescene1::~gamescene1()
{
    delete ui;
}
//时间函数--------董修良
void gamescene1::timerUpdate()
{
    if(rc==player1.color)
    {
       // QString tS=QString::number(wtimer);
        timer_1--;
        ui->lcdNumber->display(timer_1);
       // qDebug()<<wtimer<<endl;
        ui->lcdNumber->update();
        if(timer_1==0)
        {
            QMessageBox::information(this,"胜利","player2胜利",QMessageBox::Ok);
            initialpan();
        }
    }
    else {
        timer_2--;
//        QString tS=QString::number(btimer);
        ui->lcdNumber_2->display(timer_2);
        ui->lcdNumber_2->update();
        if(timer_2==0)
        {
            QMessageBox::information(this,"胜利","player1胜利",QMessageBox::Ok);
            initialpan();
        }
    }
}
//初始化相关操作-------------胥卜凡
void gamescene1::initialpan()
{
           /*初始化棋盘*/
        for(int i = 0; i<15; ++i)
        {
            for(int j = 0; j<15; ++j)
            {
                board[i][j]=0;
            }
        }
        //保存上一次的棋谱
        lqp=qp;
        //清空本次的棋谱
        qp.clear();;
        //重置计时器的数字
        timer_1=timer_2=dnum;
        ui->lcdNumber->display(timer_1);
        ui->lcdNumber_2->display(timer_2);
        ui->lcdNumber->update();
        ui->lcdNumber_2->update();
        //根据玩家的颜色执行图片的分配
        rc=bl;
        rx=ry=bx=by=0;
        ui->label_6->setVisible(false);
        ui->label_5->setVisible(true);   if(player1.color==bl)
        {
            ui->label_5->setStyleSheet(QStringLiteral("border-image: url(:/new1/b.png);"));
            ui->label_6->setStyleSheet(QStringLiteral("border-image: url(:/new1/w.png);"));
        }
        else {
            ui->label_6->setStyleSheet(QStringLiteral("border-image: url(:/new1/b.png);"));
            ui->label_5->setStyleSheet(QStringLiteral("border-image: url(:/new1/w.png);"));
        }
        //停止计时
        id1->stop();
        id2->stop();
        //重新计时
        repaint();
}
//按压操作----------------------------董修良
void gamescene1::mousePressEvent(QMouseEvent *event)
{
  // qDebug()<<event->x()<<"   "<<event->y()<<endl;

    //通过这个数学函数来获得相应的棋盘位置
    int m=event->x()*2/100;
    int n=event->y()*2/100;

      qDebug()<<m<<"  "<<n<<endl;

      qDebug()<<"press"<<bx<<' '<<by<<endl;

    if(m<0||m>14||n<0||n>14)
        return;
    //判断此处是否已经落子
    if(board[m][n]==0)
    {
        //根据当前玩家的颜色进行操作
        if(rc==player1.color)
        {
            //再次通过数学函数获得实际位置
            bx=50+m*100;
            by=50+n*100;
            bx/=2;
            by/=2;
            //停止本玩家的计时，开始另一个玩家的计时
            id2->start(1000);
            id1->stop();
            //棋谱中保存棋子顺序
            qp.push_back(QPoint(m,n));
            //显示下一个行动方
            ui->label_5->setVisible(false);
            ui->label_6->setVisible(true);

            timer_1=dnum;
            ui->lcdNumber->display(timer_1);
            ui->lcdNumber->update();
            board[m][n]=rc;
            rc=player2.color;
        }
        else
        {
            bx=50+m*100;
            by=50+n*100;
            bx/=2;
            by/=2;
            id1->start(1000);
            id2->stop();
            qp.push_back(QPoint(m,n));
            ui->label_6->setVisible(false);
            ui->label_5->setVisible(true);

            timer_2=dnum;
            ui->lcdNumber_2->display(timer_2);
            ui->lcdNumber_2->update();
            board[m][n]=rc;
            rc=player1.color;
        }
     }
    repaint();
    win(m,n);
}
//移动操作----------------胥卜凡
void gamescene1::mouseMoveEvent(QMouseEvent *event)
{
    //通过数学函数获得当前位置
    rx=event->x()*2/100;
    ry=event->y()*2/100;
    //qDebug()<<rx<<' '<<ry<<endl;
    //绘制红色外框
    repaint();
}
//绘画操作-------------王有为（棋盘),董修良（棋子），胥卜凡（红框+红十字)
void gamescene1::paintEvent(QPaintEvent *event)
{
    //建立一个Painter类用于绘画操作
    QPainter painter(this);
    //设置反锯齿
    painter.setRenderHint(QPainter::Antialiasing,true);
    //设置pen类进行轮廓设计
    QPen pen=painter.pen();
    //调色
    pen.setColor(Qt::yellow);
    //调整宽度
    pen.setWidth(7);

    //设置用于填充的brush
    QBrush brush;
    //调色
    brush.setColor(QColor("#FFD700"));
    //固态填充模式
    brush.setStyle(Qt::SolidPattern);
    //装入brush
    painter.setBrush(brush);
    //绘制棋盘主轮廓
    painter.drawRect(0,0,750,750);
    //改颜色
    pen.setColor(Qt::black);
    //绘制新宽度
    pen.setWidth(1);
    //装入Pen
    painter.setPen(pen);
    //棋盘线的绘制
    for(int i=0;i<15;i++)
    {
        painter.drawLine((50+i*100)/2,25,(50+i*100)/2,1450/2);
        painter.drawLine(25,(50+i*100)/2,725,(50+i*100)/2);
    }
    //棋子的绘制
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
        {
            if(board[i][j]==wh)
            {
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(QPoint(((50+i*100)/2),(50+j*100)/2),25,25);
            }
            else if(board[i][j]==bl){
                    brush.setColor(Qt::black);
                    painter.setBrush(brush);
                    painter.drawEllipse(QPoint(((50+i*100)/2),(50+j*100)/2),25,25);
            }
    }
    /****************/
    //红框的绘制

    pen.setColor(Qt::red);
    pen.setWidth(1);
    painter.setPen(pen);
    int ch=3;//用于调整实际红框大小
    //西北
    if(rx<15&&rx>=0&&ry>=0&&ry<15)
    {
    painter.drawLine(QPoint((ch+rx*100)/2,(ch+ry*100)/2),QPoint((ch+20+rx*100)/2,(ch+ry*100)/2));
    painter.drawLine(QPoint((ch+rx*100)/2,(ch+ry*100)/2),QPoint((ch+rx*100)/2,(ch+20+ry*100)/2));
    //东北
    painter.drawLine(QPoint(((rx+1)*100-ch)/2,(ry*100+ch)/2),QPoint(((rx+1)*100-20-ch)/2,(ry*100+ch)/2));
    painter.drawLine(QPoint(((rx+1)*100-ch)/2,(ry*100+ch)/2),QPoint(((rx+1)*100-ch)/2,(ry*100+20+ch)/2));
    //东南
    painter.drawLine(QPoint(((rx+1)*100-ch)/2,((ry+1)*100-ch)/2),QPoint(((rx+1)*100-20-ch)/2,((ry+1)*100-ch)/2));
    painter.drawLine(QPoint(((rx+1)*100-ch)/2,((ry+1)*100-ch)/2),QPoint(((rx+1)*100-ch)/2,((ry+1)*100-20-ch)/2));
    //西南
    painter.drawLine(QPoint((rx*100+ch)/2,((ry+1)*100-ch)/2),QPoint((rx*100+20+ch)/2,((ry+1)*100-ch)/2));
    painter.drawLine(QPoint((rx*100+ch)/2,((ry+1)*100-ch)/2),QPoint((rx*100+ch)/2,((ry+1)*100-20-ch)/2));
    }
    //***************
    //红十字
    if(bx<=750&&bx>=0)
    {
        painter.drawLine(QPoint(bx,by),QPoint(bx+10,by));
        painter.drawLine(QPoint(bx,by),QPoint(bx,by+10));
        painter.drawLine(QPoint(bx,by),QPoint(bx-10,by));
        painter.drawLine(QPoint(bx,by),QPoint(bx,by-10));
    }
    //**********************
}
//判断输赢------------胥卜凡
void gamescene1::win(int i,int j)
{
    //用于接收提示框
    int okButton=0;
    //遍历判断是否有输赢
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
    {
       //判断此处是否落子
       if(board[i][j]!=0)
       {
            //根据胜负策略进行该点的胜负判断
            int t=solution1(i,j);
            //没有5连
            if(t==0)
                continue;
            //有5连
            else if(t==1)
            {
                int color=board[i][j];
                 id1->stop();
                 id2->stop();
                 if(color==player1.color)
                    okButton= QMessageBox::information(this, "win", "player1胜利!", QMessageBox::Ok);
                 else
                 {
                     okButton=QMessageBox::information(this,"win","player2胜利",QMessageBox::Ok);
                 }
            }
            else if(t==2)
            {
                int color=board[i][j];
                id1->stop();
                id2->stop();
                if(color==player1.color)
                   okButton= QMessageBox::information(this, "win", "player1胜利!", QMessageBox::Ok);
                else
                {
                    okButton=QMessageBox::information(this,"win","player2胜利",QMessageBox::Ok);
                }
            }
            //有5连就初始化了
            if(okButton == QMessageBox::Ok)
            {
                initialpan();
            }
       }
    }
    //判断棋子填满棋盘的情况
    if(qp.size()==225)
    {
        id1->stop();
        id2->stop();
        okButton=QMessageBox::information(this,"ping","平局！",QMessageBox::Ok);

        if(okButton==QMessageBox::Ok)
        {
            initialpan();
        }
    }

}
//判断输赢的方法-------胥卜凡
int gamescene1::solution1(int i,int j)
{
    if(i<11)//东
    {
        if(	board[i][j] == 4
            &&board[i+1][j] == 4
            &&board[i+2][j] == 4
            &&board[i+3][j] == 4
            &&board[i+4][j] == 4)
            return 1;
        if(	board[i][j] == 5
                &&board[i+1][j] == 5
                &&board[i+2][j] == 5
                &&board[i+3][j] == 5
                &&board[i+4][j] == 5)
            return 2;
    }
    //西
    if(i>=4)
    {
        if(	board[i][j] == 4
            &&board[i-1][j] == 4
            &&board[i-2][j] == 4
            &&board[i-3][j] == 4
            &&board[i-4][j] == 4)
            return 1;
        if(	board[i][j] == 5
            &&board[i-1][j] == 5
            &&board[i-2][j] == 5
            &&board[i-3][j] == 5
            &&board[i-4][j] == 5)
            return 2;
    }
    //北
    if(j>=4)
    {
        if(	board[i][j] == 4
            &&board[i][j-1] == 4
            &&board[i][j-2] == 4
            &&board[i][j-3] == 4
            &&board[i][j-4] == 4)
            return 1;
        if(	board[i][j] == 5
            &&board[i][j-1] == 5
            &&board[i][j-2] == 5
            &&board[i][j-3] == 5
            &&board[i][j-4] == 5)
            return 2;
    }
    //南
    if(j<11)
    {
        if(	board[i][j] == 4
            &&board[i][j+1] == 4
            &&board[i][j+2] == 4
            &&board[i][j+3] == 4
            &&board[i][j+4] == 4)
            return 1;
        if(	board[i][j] == 5
            &&board[i][j+1] == 5
            &&board[i][j+2] == 5
            &&board[i][j+3] == 5
            &&board[i][j+4] == 5)
            return 2;
    }
    //西南
    if(i>=4&&j<11)
    {
        if(	board[i][j] == 4
            &&board[i-1][j+1] == 4
            &&board[i-2][j+2] == 4
            &&board[i-3][j+3] == 4
            &&board[i-4][j+4] == 4)
            return 1;
        if(	board[i][j] == 5
            &&board[i-1][j+1] == 5
            &&board[i-2][j+2] == 5
            &&board[i-3][j+3] == 5
            &&board[i-4][j+4] == 5)
            return 2;
    }
    //东南
    if(i<11&&j<11)
    {
        if(	board[i][j] == 4
            &&board[i+1][j+1] == 4
            &&board[i+2][j+2] == 4
            &&board[i+3][j+3] == 4
            &&board[i+4][j+4] == 4)
            return 1;
        if(	board[i][j] == 5
            &&board[i+1][j+1] == 5
            &&board[i+2][j+2] == 5
            &&board[i+3][j+3] == 5
            &&board[i+4][j+4] == 5)
            return 2;
    }
    //西北
    if(i>=4&&j>=4)
    {
        if(	board[i][j] == 4
            &&board[i-1][j-1] == 4
            &&board[i-2][j-2] == 4
            &&board[i-3][j-3] == 4
            &&board[i-4][j-4] == 4)
            return 1;
        if(	board[i][j] == 5
            &&board[i-1][j-1] == 5
            &&board[i-2][j-2] == 5
            &&board[i-3][j-3] == 5
            &&board[i-4][j-4] == 5)
            return 2;
    }
    //东北
    if(i<11&&j>=4)
    {
        if(	board[i][j] == 4
            &&board[i+1][j-1] == 4
            &&board[i+2][j-2] == 4
            &&board[i+3][j-3] == 4
            &&board[i+4][j-4] == 4)
            return 1;
        if(	board[i][j] == 5
            &&board[i+1][j-1] == 5
            &&board[i+2][j-2] == 5
            &&board[i+3][j-3] == 5
            &&board[i+4][j-4] == 5)
            return 2;
    }
    return 0;
}
//返回功能--------------王有为
void gamescene1::on_pushButton_clicked()
{
    //显示主菜单
    this->parentWidget()->show();
    //删除本菜单
    delete this;
}
//更改头像框功能---------------董修良
void gamescene1::on_pushButton_5_clicked()
{
    //用于接收图片文件路径
    QString OPenFile;
    //OPennFilePath;
    //设置大小
    QPixmap A(350,400);
    //限制图片类型
    OPenFile = QFileDialog::getOpenFileName(this,
                                              "选择图片",
                                              "",
                                              "Image Files(*.jpg *.png);;All(*.*)");
    //检测是否有选择到
    if(OPenFile!=""){

        A.load(OPenFile);
        //设置大小
        A=A.scaled(ui->pushButton_5->width(),ui->pushButton_5->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->pushButton_5->setIcon(A);
        //设置大小
        ui->pushButton_5->setIconSize(QSize(350,400));
    }
    ui->pushButton_5->show();
}

void gamescene1::on_pushButton_6_clicked()
{
    QString OPenFile;
    //OPennFilePath;
    QPixmap A(300,400);
    OPenFile = QFileDialog::getOpenFileName(this,
                                              "选择图片",
                                              "",
                                              "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
    if(OPenFile!=""){
     //   ui->pushButton_5->setStyleSheet();
        A.load(OPenFile);
        A=A.scaled(ui->pushButton_6->width(),ui->pushButton_6->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
        ui->pushButton_6->setIcon(A);
        ui->pushButton_6->setIconSize(QSize(350,400));
    }
    ui->pushButton_6->show();
}


//认输功能----------------------胥卜凡
void gamescene1::on_pushButton_2_clicked()
{
    //接收信息框
    int okbutton=0;
    //选择是否认输
    okbutton= QMessageBox::information(this, "认输", "是否认输？", QMessageBox::Ok|QMessageBox::No);
    //认输后进行胜负判断和初始化
    if(okbutton==QMessageBox::Ok)
    {
        //接收第一个判断
        int OK=0;
        //判断是否棋盘上根本没有棋子
        if(qp.empty())
        {
          OK=QMessageBox::information(this,"错误","还没有开始下子呢",QMessageBox::Ok);
        }
        //没有就退出
        if(OK==QMessageBox::Ok)
        {
            return;
        }
       if(rc==player1.color)
           okbutton=QMessageBox::information(this, "win", "player2胜利!", QMessageBox::Ok);
       else
       {
           okbutton=QMessageBox::information(this,"win","player1胜利",QMessageBox::Ok);
       }
       ui->label_6->setVisible(false);
       ui->label_5->setVisible(true);
       if(okbutton==QMessageBox::Ok)
            initialpan();
    }
}

//悔棋功能----------------------胥卜凡
void gamescene1::on_pushButton_4_clicked()
{
    //接收信息框
    int okbutton=0;
    okbutton= QMessageBox::information(this, "悔棋", "是否悔棋？", QMessageBox::Ok|QMessageBox::No);
    //悔棋后执行操作
    if(okbutton==QMessageBox::Ok)
    {
        //接收第一个判断
        int OK=0;
        //判断是否棋盘上根本没有棋子
        if(qp.empty())
      {
          OK=QMessageBox::information(this,"错误","棋盘上没有棋子了",QMessageBox::Ok);
      }
        //没有就退出
      if(OK==QMessageBox::Ok)
      {
          return;
      }
      //通过棋谱来取得上一个棋子和上上个棋子
      QPoint t1=*(qp.end()-1),t2=*(qp.end()-2);
      int x1=t1.x(),y1=t1.y();
      bx=t2.x()*50+25;
      by=t2.y()*50+25;
      //删掉棋谱中的上一个棋子
      qp.pop_back();
      //对上一个棋子位置删除棋子
      board[x1][y1]=0;
      //判断当前玩家颜色，从而将当前玩家更改为上一玩家
      if(rc==player1.color)
      {
          id2->start(1000);
          id1->stop();
          ui->label_5->setVisible(false);
          ui->label_6->setVisible(true);

          timer_1=dnum;
          ui->lcdNumber->display(timer_1);
          ui->lcdNumber->update();
          rc=player2.color;
      }
      else
      {
        id1->start(1000);
        id2->stop();
        ui->label_6->setVisible(false);
        ui->label_5->setVisible(true);

        timer_2=dnum;
        ui->lcdNumber_2->display(timer_2);
        ui->lcdNumber_2->update();
        rc=player1.color;
     }
      //重新绘制
    repaint();
    //break;
    }
}

//复盘功能-----------------------胥卜凡
void gamescene1::on_pushButton_7_clicked()
{
    //接收信息框
    int okbutton=0;
    okbutton= QMessageBox::information(this,"复盘","是否复盘？",QMessageBox::Ok|QMessageBox::No);
    //如果选择了是
    if(okbutton==QMessageBox::Ok)
    {
        //建立复盘界面
        fupan *fp=new fupan(this);
        //绑定、发送棋谱
        connect(this,&gamescene1::sendFupan,fp,&fupan::lalala);
        emit sendFupan(lqp);
        //显示复盘界面
        fp->show();
        //隐藏该界面
        this->hide();
    }
}
