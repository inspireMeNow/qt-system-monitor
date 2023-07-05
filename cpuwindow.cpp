#include "cpuwindow.h"
#include "ui_cpuwindow.h"

CpuWindow::CpuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CpuWindow)
{
    ui->setupUi(this);
    updateTable();
}

CpuWindow::~CpuWindow()
{
    delete ui;
}

void CpuWindow::updateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    std::vector<CPU> data(getCpuInfo());
    int rowPosition=0;
    for (int i=0;i<data.size();i++) {
        rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);
        ui->tableWidget->setItem(rowPosition,0,new QTableWidgetItem(QString::fromStdString(data[i].Processor)));
        ui->tableWidget->setItem(rowPosition,1,new QTableWidgetItem(QString::fromStdString(data[i].BogoMIPS)));
        ui->tableWidget->setItem(rowPosition,2,new QTableWidgetItem(QString::fromStdString(data[i].Features)));
        ui->tableWidget->setItem(rowPosition,3,new QTableWidgetItem(QString::fromStdString(data[i].implementer)));
        ui->tableWidget->setItem(rowPosition,4,new QTableWidgetItem(QString::fromStdString(data[i].architecture)));
        ui->tableWidget->setItem(rowPosition,5,new QTableWidgetItem(QString::fromStdString(data[i].variant)));
        ui->tableWidget->setItem(rowPosition,6,new QTableWidgetItem(QString::fromStdString(data[i].part)));
        ui->tableWidget->setItem(rowPosition,7,new QTableWidgetItem(QString::fromStdString(data[i].revision)));
        ui->tableWidget->setItem(rowPosition,8,new QTableWidgetItem(QString::fromStdString(data[i].Hardware)));
    }
}
