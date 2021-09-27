#ifndef FUPAN_H
#define FUPAN_H

#include <QMainWindow>
#include<QTimer>
#include<QTimeLine>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QVector>
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

namespace Ui {
class fupan;
}

class fupan : public QMainWindow
{
    Q_OBJECT

public:
    explicit fupan(QWidget *parent = nullptr);
    ~fupan();
public slots:
    //接收父窗口信号传来的棋谱信息
    void lalala(QVector<QPoint>);
public:
    //画图功能
    void paintEvent(QPaintEvent*event);
    //初始化功能
    void initialpan();
    //落子功能
    void luozi(int x,int y,int seq);
    //区别黑色和白色
    enum
    {
        bl=4,wh=5
    };
private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);
private:
    Ui::fupan *ui;
    QVector<QPoint> qp;
    QVector<QLabel *>a;
    int board[15][15];
    int rx,ry;
    int to;
    int rt;
};

#endif // FUPAN_H
