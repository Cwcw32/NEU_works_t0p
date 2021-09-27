#ifndef GAMESCENE1_H
#define GAMESCENE1_H

#include <QMainWindow>
#include<QTimer>
#include<QTimeLine>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QVector>
#include"player.h"
namespace Ui {
class gamescene1;
}
class gamescene1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit gamescene1(QWidget *parent = nullptr);
    ~gamescene1();
    void mousePressEvent(QMouseEvent*event);//鼠标按压事件，实现落子
    void mouseMoveEvent(QMouseEvent*event);//鼠标移动实践，实现红框的绘制
    void paintEvent(QPaintEvent*event);//绘画
    void win(int i,int j);//判断输赢
    int solution1(int i,int j);//判断输赢的规则
    void initialpan();//初始化各种数据
    //方便设置黑白颜色，防止混乱
    enum
    {
        bl=4,wh=5
    };
signals:
        void sendFupan(QVector<QPoint>);//向复盘界面发送棋谱的信号
private slots:
//返回
    void on_pushButton_clicked();
//更改头像
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
//超时
    void timerUpdate();
//认输
    void on_pushButton_2_clicked();
//悔棋
    void on_pushButton_4_clicked();
//复盘
    void on_pushButton_7_clicked();

private:
    Ui::gamescene1 *ui;
    int rx,ry;//当前鼠标所在的棋盘位置
    int bx,by;//当前所在的实际位置
    int board[15][15];//棋盘
    int rc;//当前玩家的颜色

    QVector<QPoint> qp;//本次游戏的棋谱
    QVector<QPoint> lqp;//上次游戏的棋谱

    player player1,player2;//两个玩家
    QTimer *id1,*id2;//两个计时器
    int timer_1,timer_2;//两个用于配置计时器数目的单位
    int dnum;//用于初始化计时器
};

#endif // GAMESCENE1_H
