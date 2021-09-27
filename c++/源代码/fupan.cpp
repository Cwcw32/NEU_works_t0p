#include "fupan.h"
#include "ui_fupan.h"
#include "gamescene1.h"
#include "ui_gamescene1.h"
fupan::fupan(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fupan)
{
    ui->setupUi(this);
    //初始化相关单位,防止发生BUG
    rx=ry=rt=to=0;
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            board[i][j]=0;
    //绘制棋盘
    repaint();
}

fupan::~fupan()
{
    delete ui;
}


//接收父窗口传来的棋谱
void fupan::lalala(QVector<QPoint> a)
{
    //将棋谱复制到本窗口的棋谱
    qp=a;
    //计算总步骤数
    to=qp.end()-qp.begin();
    //默认具有全部步骤
    rt=to;
    //更改spinBox的值
    ui->spinBox->valueChanged(to);
    //设置spinBox的最大值
    ui->spinBox->setMaximum(to);
    //设置vertocalSlier的最大值
    ui->verticalSlider->setMaximum(to);
}
void fupan::paintEvent(QPaintEvent *event)
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
    //筛选，偶数次为白棋，计数次为黑棋
    for(int i=1;i<=to;i++)
    {
        int x=qp[i-1].x(),y=qp[i-1].y();
        if(i%2==1)
        {
            board[x][y]=4;
        }
        else {
            board[x][y]=5;
        }
    }
    //建立字体单位
    QFont ft=painter.font();
    //调为加粗
    ft.setBold(true);
    //设置大小
    ft.setPixelSize(25);
    //载入字体
    painter.setFont(ft);
    //根据spinbox传来的数值进行步骤数目显示的更改
    for(int i=1;i<=rt;i++)
    {
        //取出棋谱中的元素
        int x=qp[i-1].x(),y=qp[i-1].y();
        //由于字体位置摆放的问题，需要根据数字的宽度进行筛选执行
        if(i<10)
        {
            //根据奇偶分辨棋子的黑白色和步骤数字的黑白色
            if(i%2==0)
           {
            brush.setColor(Qt::white);
            painter.setBrush(brush);
            painter.drawEllipse(QPoint((50+x*100)/2,(50+y*100)/2),25,25);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawText(QPoint(19+x*50,32+y*50),QString::number(i));
            }
        else
            {
            brush.setColor(Qt::black);
            painter.setBrush(brush);
            painter.drawEllipse(QPoint((50+x*100)/2,(50+y*100)/2),25,25);
            pen.setColor(Qt::white);
            painter.setPen(pen);
            painter.drawText(QPoint(19+x*50,32+y*50),QString::number(i));
            }
        }
        else if(i<100)
        {
            if(i%2==0)
           {
            brush.setColor(Qt::white);
            painter.setBrush(brush);
            painter.drawEllipse(QPoint((50+x*100)/2,(50+y*100)/2),25,25);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawText(QPoint(13+x*50,32+y*50),QString::number(i));
            }
        else
            {
            brush.setColor(Qt::black);
            painter.setBrush(brush);
            painter.drawEllipse(QPoint((50+x*100)/2,(50+y*100)/2),25,25);
            pen.setColor(Qt::white);
            painter.setPen(pen);
            painter.drawText(QPoint(13+x*50,32+y*50),QString::number(i));
            }
        }
        else
        {
            if(i%2==0)
           {
            brush.setColor(Qt::white);
            painter.setBrush(brush);
            painter.drawEllipse(QPoint((50+x*100)/2,(50+y*100)/2),25,25);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawText(QPoint(9+x*50,32+y*50),QString::number(i));
            }
        else
            {
            brush.setColor(Qt::black);
            painter.setBrush(brush);
            painter.drawEllipse(QPoint((50+x*100)/2,(50+y*100)/2),25,25);
            pen.setColor(Qt::white);
            painter.setPen(pen);
            painter.drawText(QPoint(9+x*50,32+y*50),QString::number(i));
            }
        }
    }
}


void fupan::on_pushButton_clicked()
{
    //显示游戏窗口
    this->parentWidget()->show();
    //删除本窗口
    delete this;
}


void fupan::on_spinBox_valueChanged(int arg1)
{
    //让spinBox和棋盘的步骤显示单位绑定
    rt=arg1;
    //据此进行重新绘画
    repaint();
}
