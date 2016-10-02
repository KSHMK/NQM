/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *FindAP;
    QPushButton *StopDeAuth;
    QPushButton *FindVictim;
    QLineEdit *textVictim;
    QLineEdit *textchannel;
    QLineEdit *textAP;
    QLineEdit *textiface;
    QPushButton *StartDeAuth;
    QTabWidget *tabWidget;
    QWidget *APtab;
    QTableWidget *APTable;
    QWidget *Victimtab;
    QTableWidget *VicTable;
    QPushButton *StopVictim;
    QPushButton *StopAP;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 490);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FindAP = new QPushButton(centralWidget);
        FindAP->setObjectName(QStringLiteral("FindAP"));
        FindAP->setGeometry(QRect(270, 400, 131, 41));
        StopDeAuth = new QPushButton(centralWidget);
        StopDeAuth->setObjectName(QStringLiteral("StopDeAuth"));
        StopDeAuth->setGeometry(QRect(550, 400, 131, 41));
        FindVictim = new QPushButton(centralWidget);
        FindVictim->setObjectName(QStringLiteral("FindVictim"));
        FindVictim->setGeometry(QRect(410, 400, 131, 41));
        textVictim = new QLineEdit(centralWidget);
        textVictim->setObjectName(QStringLiteral("textVictim"));
        textVictim->setGeometry(QRect(450, 250, 231, 41));
        textchannel = new QLineEdit(centralWidget);
        textchannel->setObjectName(QStringLiteral("textchannel"));
        textchannel->setGeometry(QRect(450, 130, 231, 41));
        textAP = new QLineEdit(centralWidget);
        textAP->setObjectName(QStringLiteral("textAP"));
        textAP->setGeometry(QRect(450, 190, 231, 41));
        textiface = new QLineEdit(centralWidget);
        textiface->setObjectName(QStringLiteral("textiface"));
        textiface->setGeometry(QRect(450, 70, 231, 41));
        StartDeAuth = new QPushButton(centralWidget);
        StartDeAuth->setObjectName(QStringLiteral("StartDeAuth"));
        StartDeAuth->setGeometry(QRect(550, 400, 131, 41));
        StartDeAuth->setCheckable(false);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 411, 371));
        APtab = new QWidget();
        APtab->setObjectName(QStringLiteral("APtab"));
        APTable = new QTableWidget(APtab);
        APTable->setObjectName(QStringLiteral("APTable"));
        APTable->setGeometry(QRect(10, 10, 390, 321));
        tabWidget->addTab(APtab, QString());
        Victimtab = new QWidget();
        Victimtab->setObjectName(QStringLiteral("Victimtab"));
        VicTable = new QTableWidget(Victimtab);
        VicTable->setObjectName(QStringLiteral("VicTable"));
        VicTable->setGeometry(QRect(10, 10, 390, 321));
        tabWidget->addTab(Victimtab, QString());
        StopVictim = new QPushButton(centralWidget);
        StopVictim->setObjectName(QStringLiteral("StopVictim"));
        StopVictim->setGeometry(QRect(410, 400, 131, 41));
        StopAP = new QPushButton(centralWidget);
        StopAP->setObjectName(QStringLiteral("StopAP"));
        StopAP->setGeometry(QRect(270, 400, 131, 41));
        MainWindow->setCentralWidget(centralWidget);
        FindAP->raise();
        FindVictim->raise();
        StopVictim->raise();
        StopDeAuth->raise();
        textVictim->raise();
        textchannel->raise();
        textAP->raise();
        textiface->raise();
        StartDeAuth->raise();
        tabWidget->raise();
        StopAP->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget, APTable);
        QWidget::setTabOrder(APTable, VicTable);
        QWidget::setTabOrder(VicTable, textiface);
        QWidget::setTabOrder(textiface, textchannel);
        QWidget::setTabOrder(textchannel, textAP);
        QWidget::setTabOrder(textAP, textVictim);
        QWidget::setTabOrder(textVictim, FindAP);
        QWidget::setTabOrder(FindAP, FindVictim);
        QWidget::setTabOrder(FindVictim, StartDeAuth);
        QWidget::setTabOrder(StartDeAuth, StopDeAuth);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        FindAP->setText(QApplication::translate("MainWindow", "Start Find AP", 0));
        StopDeAuth->setText(QApplication::translate("MainWindow", "Stop DeAuth", 0));
        FindVictim->setText(QApplication::translate("MainWindow", "Start Find Target", 0));
        textVictim->setText(QApplication::translate("MainWindow", "Target", 0));
        textchannel->setText(QApplication::translate("MainWindow", "Channel", 0));
        textAP->setText(QApplication::translate("MainWindow", "AP", 0));
        textiface->setText(QApplication::translate("MainWindow", "Interface", 0));
        StartDeAuth->setText(QApplication::translate("MainWindow", "Start DeAuth", 0));
        tabWidget->setTabText(tabWidget->indexOf(APtab), QApplication::translate("MainWindow", "AP", 0));
        tabWidget->setTabText(tabWidget->indexOf(Victimtab), QApplication::translate("MainWindow", "Target", 0));
        StopVictim->setText(QApplication::translate("MainWindow", "Stop Find Target", 0));
        StopAP->setText(QApplication::translate("MainWindow", "Stop Find AP", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
