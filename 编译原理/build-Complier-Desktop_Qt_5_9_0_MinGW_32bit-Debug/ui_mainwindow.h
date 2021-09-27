/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_6;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_2;
    QLabel *label_2;
    QTextBrowser *textBrowser_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QLabel *label_3;
    QTextBrowser *textBrowser_7;
    QLabel *label_8;
    QTextBrowser *textBrowser_4;
    QLabel *label_9;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2000, 1500);
        MainWindow->setMinimumSize(QSize(2000, 1500));
        MainWindow->setMaximumSize(QSize(2000, 1500));
        MainWindow->setSizeIncrement(QSize(2000, 1500));
        MainWindow->setBaseSize(QSize(2000, 1500));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 500, 441, 231));
        QFont font;
        font.setFamily(QStringLiteral("Academy Engraved LET"));
        font.setPointSize(28);
        label->setFont(font);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(80, 180, 491, 341));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(140, 20, 371, 151));
        label_6->setFont(font);
        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(80, 1140, 491, 331));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(70, 680, 491, 321));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 1000, 361, 201));
        label_2->setFont(font);
        textBrowser_5 = new QTextBrowser(centralWidget);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(720, 850, 441, 321));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(649, 140, 371, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(820, 720, 371, 181));
        label_3->setFont(font);
        textBrowser_7 = new QTextBrowser(centralWidget);
        textBrowser_7->setObjectName(QStringLiteral("textBrowser_7"));
        textBrowser_7->setGeometry(QRect(1280, 840, 451, 331));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1350, 710, 581, 191));
        label_8->setFont(font);
        textBrowser_4 = new QTextBrowser(centralWidget);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(1280, 470, 451, 291));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(1330, 320, 581, 191));
        label_9->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\350\257\215\346\263\225\345\210\206\346\236\220", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\346\272\220\346\226\207\344\273\266", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\350\257\255\346\263\225\345\210\206\346\236\220", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\257\215\346\263\225\345\210\206\346\236\220", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\350\257\255\346\263\225\345\210\206\346\236\220", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220\345\233\233\345\205\203\345\274\217", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "\344\274\230\345\214\226+\347\233\256\346\240\207\344\273\243\347\240\201\347\224\237\346\210\220", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\233\233\345\205\203\345\274\217", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\344\273\243\347\240\201\347\224\237\346\210\220", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\345\233\233\345\205\203\345\274\217\344\274\230\345\214\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
