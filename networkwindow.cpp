#include "networkwindow.h"
#include "ui_networkwindow.h"

NetworkWindow::NetworkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetworkWindow)
{
    ui->setupUi(this);
    startTimer(2000);

}

NetworkWindow::~NetworkWindow()
{
    delete ui;
}

void NetworkWindow::updateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    std::vector<Net> data(get_net());
    int rowPosition=0;
    for (int i=0;i<data.size();i++) {
        rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);
        ui->tableWidget->setItem(rowPosition,0,new QTableWidgetItem(QString::fromStdString(data[i].ifname)));
        ui->tableWidget->setItem(rowPosition,1,new QTableWidgetItem(QString::fromStdString(data[i].iftype)));
        ui->tableWidget->setItem(rowPosition,2,new QTableWidgetItem(QString::fromStdString(data[i].mac)));
        ui->tableWidget->setItem(rowPosition,3,new QTableWidgetItem(QString::fromStdString(data[i].ip)));
        ui->tableWidget->setItem(rowPosition,4,new QTableWidgetItem(QString::fromStdString(data[i].mask)));
        ui->tableWidget->setItem(rowPosition,5,new QTableWidgetItem(QString::fromStdString(data[i].broadcast)));
        ui->tableWidget->setItem(rowPosition,6,new QTableWidgetItem(QString::fromStdString(data[i].gateway)));
        ui->tableWidget->setItem(rowPosition,7,new QTableWidgetItem(QString::fromStdString(data[i].upload_speed)));
        ui->tableWidget->setItem(rowPosition,8,new QTableWidgetItem(QString::fromStdString(data[i].download_speed)));
        ui->tableWidget->setItem(rowPosition,9,new QTableWidgetItem(QString::fromStdString(data[i].upload_bytes)));
        ui->tableWidget->setItem(rowPosition,10,new QTableWidgetItem(QString::fromStdString(data[i].download_bytes)));
    }

}

void NetworkWindow::timerEvent(QTimerEvent *event)
{
    updateTable();
}


