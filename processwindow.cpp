#include "processwindow.h"
#include "ui_processwindow.h"

ProcessWindow::ProcessWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessWindow)
{
    ui->setupUi(this);
    startTimer(5000);
}

ProcessWindow::~ProcessWindow()
{
    delete ui;
}

void ProcessWindow::updateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    std::vector<process> data((get_progess()));
    int rowPosition=0;
    for (int i=0;i<data.size();i++) {
        rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);
        ui->tableWidget->setItem(rowPosition,0,new QTableWidgetItem(QString::fromStdString(data[i].user)));
        ui->tableWidget->setItem(rowPosition,1,new QTableWidgetItem(QString::fromStdString(data[i].pid)));
        ui->tableWidget->setItem(rowPosition,2,new QTableWidgetItem(QString::fromStdString(data[i].command)));
        ui->tableWidget->setItem(rowPosition,3,new QTableWidgetItem(QString::fromStdString(data[i].processperc)));
        ui->tableWidget->setItem(rowPosition,4,new QTableWidgetItem(QString::fromStdString(data[i].memperc)));
        ui->tableWidget->setItem(rowPosition,5,new QTableWidgetItem(QString::fromStdString(data[i].start)));
        ui->tableWidget->setItem(rowPosition,6,new QTableWidgetItem(QString::fromStdString(data[i].time)));
    }
}

void ProcessWindow::timerEvent(QTimerEvent *event)
{
    updateTable();
}
