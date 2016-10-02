/********************************************************************************
** Form generated from reading UI file 'deauth.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEAUTH_H
#define UI_DEAUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Deauth
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *textAP;
    QPushButton *buttonDeauth;
    QLineEdit *textVictim;
    QLineEdit *textiface;
    QLineEdit *textchannel;

    void setupUi(QDialog *Deauth)
    {
        if (Deauth->objectName().isEmpty())
            Deauth->setObjectName(QStringLiteral("Deauth"));
        Deauth->resize(314, 152);
        horizontalLayout = new QHBoxLayout(Deauth);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textAP = new QLineEdit(Deauth);
        textAP->setObjectName(QStringLiteral("textAP"));

        gridLayout->addWidget(textAP, 0, 0, 1, 1);

        buttonDeauth = new QPushButton(Deauth);
        buttonDeauth->setObjectName(QStringLiteral("buttonDeauth"));

        gridLayout->addWidget(buttonDeauth, 0, 1, 1, 1);

        textVictim = new QLineEdit(Deauth);
        textVictim->setObjectName(QStringLiteral("textVictim"));

        gridLayout->addWidget(textVictim, 1, 0, 1, 1);

        textiface = new QLineEdit(Deauth);
        textiface->setObjectName(QStringLiteral("textiface"));

        gridLayout->addWidget(textiface, 2, 0, 1, 1);

        textchannel = new QLineEdit(Deauth);
        textchannel->setObjectName(QStringLiteral("textchannel"));

        gridLayout->addWidget(textchannel, 3, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(Deauth);

        QMetaObject::connectSlotsByName(Deauth);
    } // setupUi

    void retranslateUi(QDialog *Deauth)
    {
        Deauth->setWindowTitle(QApplication::translate("Deauth", "Dialog", 0));
        textAP->setText(QApplication::translate("Deauth", "AP", 0));
        buttonDeauth->setText(QApplication::translate("Deauth", "DEAUTH", 0));
        textVictim->setText(QApplication::translate("Deauth", "Target", 0));
        textiface->setText(QApplication::translate("Deauth", "Interface", 0));
        textchannel->setText(QApplication::translate("Deauth", "Channel", 0));
    } // retranslateUi

};

namespace Ui {
    class Deauth: public Ui_Deauth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEAUTH_H
