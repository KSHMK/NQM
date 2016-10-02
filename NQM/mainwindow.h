#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "nettools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_StartDeAuth_clicked();

    void on_StopDeAuth_clicked();

    void on_FindAP_clicked();

    void on_FindVictim_clicked();

    void on_APTable_cellDoubleClicked(int row, int column);

    void on_VicTable_cellDoubleClicked(int row, int column);

    void on_StopVictim_clicked();

    void on_StopAP_clicked();

private:
    Ui::MainWindow *ui;
    NetTools *nt;

};

#endif // MAINWINDOW_H
