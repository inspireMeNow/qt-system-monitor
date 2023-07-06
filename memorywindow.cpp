#include "memorywindow.h"
#include "ui_memorywindow.h"


MemoryWindow::MemoryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryWindow)
{
    ui->setupUi(this);
    startTimer(5000);
}

MemoryWindow::~MemoryWindow()
{
    delete ui;
}

void MemoryWindow::updateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    std::vector<Memory> data(getMemoryInfo());
    int rowPosition=0;
    for (int i=0;i<data.size();i++) {
        rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);
        ui->tableWidget->setItem(rowPosition,0,new QTableWidgetItem(QString::fromStdString(data[i].id)));
        ui->tableWidget->setItem(rowPosition,1,new QTableWidgetItem(QString::fromStdString(data[i].total)));
        ui->tableWidget->setItem(rowPosition,2,new QTableWidgetItem(QString::fromStdString(data[i].used)));
        ui->tableWidget->setItem(rowPosition,3,new QTableWidgetItem(QString::fromStdString(data[i].free)));
        ui->tableWidget->setItem(rowPosition,4,new QTableWidgetItem(QString::fromStdString(data[i].shared)));
        ui->tableWidget->setItem(rowPosition,5,new QTableWidgetItem(QString::fromStdString(data[i].cache)));
    }
}

void MemoryWindow::timerEvent(QTimerEvent *event)
{
    updateTable();
}
