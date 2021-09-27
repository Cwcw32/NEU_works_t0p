#ifndef BANGZHU_H
#define BANGZHU_H

#include <QMainWindow>

namespace Ui {
class bangzhu;
}

class bangzhu : public QMainWindow
{
    Q_OBJECT

public:
    explicit bangzhu(QWidget *parent = nullptr);
    ~bangzhu();

private slots:
    void on_pushButton_3_clicked();//返回选择框

    void on_pushButton_clicked();//下一页

    void on_pushButton_2_clicked();//上一页

private:
    Ui::bangzhu *ui;
    int pages;//页数
};

#endif // BANGZHU_H
