#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nt = new NetTools();
    this->setWindowTitle(QString("Network Quality Manager"));
    this->setFixedSize(700,490);
    ui->statusBar->showMessage(QString("Made By KSHMK"));
    ui->StopVictim->setVisible(false);
    ui->StopVictim->setEnabled(false);
    ui->StopAP->setVisible(false);
    ui->StopAP->setEnabled(false);
    ui->StopDeAuth->setVisible(false);
    ui->StopDeAuth->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_StartDeAuth_clicked()
{
    QString AP;
    string channel;

    channel = ui->textchannel->text().toUtf8().constData();
    if(!nt->StartKill(ui->textVictim->text().toUtf8().constData(),
               ui->textAP->text().toUtf8().constData(),
               ui->textiface->text().toUtf8().constData(),
               atoi(channel.c_str())))
    {
        QMessageBox::information(this,"Error","Operation not permitted");
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage(QString("Failed start DeAuth"));
        return;
    }
    ui->StartDeAuth->setEnabled(false);
    ui->StartDeAuth->setVisible(false);
    ui->FindAP->setEnabled(false);
    ui->FindVictim->setEnabled(false);
    ui->textAP->setEnabled(false);
    ui->textVictim->setEnabled(false);
    ui->textiface->setEnabled(false);
    ui->textchannel->setEnabled(false);
    ui->StopDeAuth->setEnabled(true);
    ui->StopDeAuth->setVisible(true);
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(QString("Start DeAuth"));
}

void MainWindow::on_StopDeAuth_clicked()
{
    nt->StopKill();
    ui->StartDeAuth->setEnabled(true);
    ui->StartDeAuth->setVisible(true);
    ui->FindAP->setEnabled(true);
    ui->FindVictim->setEnabled(true);
    ui->textAP->setEnabled(true);
    ui->textVictim->setEnabled(true);
    ui->textiface->setEnabled(true);
    ui->textchannel->setEnabled(true);
    ui->StopDeAuth->setEnabled(false);
    ui->StopDeAuth->setVisible(false);
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(QString("Stop DeAuth"));
}

void MainWindow::on_FindAP_clicked()
{
    string channel;

    ui->FindAP->setEnabled(false);
    ui->FindAP->setVisible(false);
    ui->StartDeAuth->setEnabled(false);
    ui->FindVictim->setEnabled(false);
    ui->textAP->setEnabled(false);
    ui->textVictim->setEnabled(false);
    ui->textiface->setEnabled(false);
    ui->textchannel->setEnabled(false);
    ui->StopAP->setEnabled(true);
    ui->StopAP->setVisible(true);
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(QString("Start Find AP"));

    channel = ui->textchannel->text().toUtf8().constData();
    if(!nt->StartFindAP(ui->textiface->text().toUtf8().constData(),
                        atoi(channel.c_str())))
    {
        QMessageBox::information(this,"Error","Operation not permitted");
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage(QString("Failed Find AP"));
        ui->FindAP->setEnabled(true);
        ui->FindAP->setVisible(true);
        ui->StartDeAuth->setEnabled(true);
        ui->FindVictim->setEnabled(true);
        ui->textAP->setEnabled(true);
        ui->textVictim->setEnabled(true);
        ui->textiface->setEnabled(true);
        ui->textchannel->setEnabled(true);
        ui->StopAP->setEnabled(false);
        ui->StopAP->setVisible(false);
    }
    return;
}

void MainWindow::on_FindVictim_clicked()
{
    string channel;

    ui->FindVictim->setEnabled(false);
    ui->FindVictim->setVisible(false);
    ui->StartDeAuth->setEnabled(false);
    ui->FindAP->setEnabled(false);
    ui->textAP->setEnabled(false);
    ui->textVictim->setEnabled(false);
    ui->textiface->setEnabled(false);
    ui->textchannel->setEnabled(false);
    ui->StopVictim->setEnabled(true);
    ui->StopVictim->setVisible(true);
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(QString("Start Find Target"));

    channel = ui->textchannel->text().toUtf8().constData();
    if(!nt->StartFindVic(ui->textAP->text().toUtf8().constData(),
                        ui->textiface->text().toUtf8().constData(),
                        atoi(channel.c_str())))
    {
        QMessageBox::information(this,"Error","Operation not permitted");
        ui->statusBar->clearMessage();
        ui->statusBar->showMessage(QString("Failed Find Target"));
        ui->FindVictim->setEnabled(true);
        ui->FindVictim->setVisible(true);
        ui->StartDeAuth->setEnabled(true);
        ui->FindAP->setEnabled(true);
        ui->textAP->setEnabled(true);
        ui->textVictim->setEnabled(true);
        ui->textiface->setEnabled(true);
        ui->textchannel->setEnabled(true);
        ui->StopVictim->setEnabled(false);
        ui->StopVictim->setVisible(false);
    }
    return;
}

void MainWindow::on_APTable_cellDoubleClicked(int row, int column)
{
    if(column == 1)
        ui->textAP->setText(ui->APTable->item(row,column)->text());
}

void MainWindow::on_VicTable_cellDoubleClicked(int row, int column)
{
    if(column == 0)
        ui->textVictim->setText(ui->VicTable->item(row,column)->text());
}

void MainWindow::on_StopVictim_clicked()
{
    QTableWidgetItem *item;
    int i;

    nt->StopFindVic();
    ui->VicTable->clear();
    ui->VicTable->setColumnCount(2);
    ui->VicTable->setColumnWidth(0,240);
    ui->VicTable->setColumnWidth(1,130);
    ui->VicTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->VicTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->VicTable->setRowCount(nt->mapVic.size());
    QStringList APName(QStringList() << tr("MAC") << tr("USAGE"));
    ui->VicTable->setHorizontalHeaderLabels(APName);
    i=0;
    for(auto iter = nt->mapVic.begin();iter != nt->mapVic.end(); iter++, i++)
    {
        item = new QTableWidgetItem(QString(iter->first.to_string().c_str()));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->VicTable->setItem(i,0,item);
        item = new QTableWidgetItem(QString(to_string(iter->second).c_str()));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->VicTable->setItem(i,1,item);
    }
    ui->FindVictim->setEnabled(true);
    ui->FindVictim->setVisible(true);
    ui->StartDeAuth->setEnabled(true);
    ui->FindAP->setEnabled(true);
    ui->textAP->setEnabled(true);
    ui->textVictim->setEnabled(true);
    ui->textiface->setEnabled(true);
    ui->textchannel->setEnabled(true);
    ui->StopVictim->setEnabled(false);
    ui->StopVictim->setVisible(false);
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(QString("Finish Find Target"));
}

void MainWindow::on_StopAP_clicked()
{
    QTableWidgetItem *item;
    string channel;
    int i;

    nt->StopFindAP();
    ui->APTable->clear();
    ui->APTable->setColumnCount(2);
    ui->APTable->setColumnWidth(0,130);
    ui->APTable->setColumnWidth(1,240);
    ui->APTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->APTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->APTable->setRowCount(nt->mapAP.size());
    QStringList APName(QStringList() << tr("SSID") << tr("MAC"));
    ui->APTable->setHorizontalHeaderLabels(APName);
    i=0;
    for(auto iter = nt->mapAP.begin();iter != nt->mapAP.end(); iter++, i++)
    {
        item = new QTableWidgetItem(QString(iter->first.c_str()));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->APTable->setItem(i,0,item);
        item = new QTableWidgetItem(QString(iter->second.to_string().c_str()));
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);
        ui->APTable->setItem(i,1,item);
    }
    ui->FindAP->setEnabled(true);
    ui->FindAP->setVisible(true);
    ui->StartDeAuth->setEnabled(true);
    ui->FindVictim->setEnabled(true);
    ui->textAP->setEnabled(true);
    ui->textVictim->setEnabled(true);
    ui->textiface->setEnabled(true);
    ui->textchannel->setEnabled(true);
    ui->StopAP->setEnabled(false);
    ui->StopAP->setVisible(false);
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(QString("Stop Find AP"));
}
