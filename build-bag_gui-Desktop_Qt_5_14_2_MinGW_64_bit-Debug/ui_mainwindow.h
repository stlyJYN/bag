/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *editT;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *editW;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *editV;
    QPushButton *btnLoad;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnExact;
    QPushButton *btnBest;
    QTextEdit *textOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 249);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        editT = new QLineEdit(centralwidget);
        editT->setObjectName(QString::fromUtf8("editT"));

        horizontalLayout->addWidget(editT);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        editW = new QLineEdit(centralwidget);
        editW->setObjectName(QString::fromUtf8("editW"));

        horizontalLayout_2->addWidget(editW);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        editV = new QLineEdit(centralwidget);
        editV->setObjectName(QString::fromUtf8("editV"));

        horizontalLayout_5->addWidget(editV);


        verticalLayout->addLayout(horizontalLayout_5);

        btnLoad = new QPushButton(centralwidget);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));

        verticalLayout->addWidget(btnLoad);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnExact = new QPushButton(centralwidget);
        btnExact->setObjectName(QString::fromUtf8("btnExact"));

        horizontalLayout_3->addWidget(btnExact);

        btnBest = new QPushButton(centralwidget);
        btnBest->setObjectName(QString::fromUtf8("btnBest"));

        horizontalLayout_3->addWidget(btnBest);


        verticalLayout->addLayout(horizontalLayout_3);

        textOutput = new QTextEdit(centralwidget);
        textOutput->setObjectName(QString::fromUtf8("textOutput"));

        verticalLayout->addWidget(textOutput);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\203\214\345\214\205\345\256\271\351\207\217T", nullptr));
        editT->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\220\204\347\211\251\345\223\201\344\275\223\347\247\257(\347\251\272\346\240\274\345\210\206\351\232\224)", nullptr));
        editW->setText(QCoreApplication::translate("MainWindow", "1 8 4 3 5 2", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\220\204\347\211\251\345\223\201\344\273\267\345\200\274(\347\251\272\346\240\274\345\210\206\351\232\224)", nullptr));
        editV->setText(QCoreApplication::translate("MainWindow", "3 10 5 4 6 2", nullptr));
        btnLoad->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\350\257\273\345\217\226", nullptr));
        btnExact->setText(QCoreApplication::translate("MainWindow", "\346\261\202\346\225\262\345\245\275\350\243\205\346\273\241\347\232\204\345\205\250\351\203\250\350\247\243", nullptr));
        btnBest->setText(QCoreApplication::translate("MainWindow", "\346\261\202\346\234\200\345\244\247\344\273\267\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
