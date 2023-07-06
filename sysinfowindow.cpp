#include "sysinfowindow.h"
#include "ui_sysinfowindow.h"

SysInfoWindow::SysInfoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysInfoWindow)
{
    ui->setupUi(this);
    updateTable();

}

SysInfoWindow::~SysInfoWindow()
{
    delete ui;
}

void SysInfoWindow::updateTable()
{
    System data=getSystemInfo();
    ui->labelDist->setText(QString::fromStdString(data.distributor));
    ui->labelDesc->setText(QString::fromStdString(data.description));
    ui->labelRel->setText(QString::fromStdString(data.release));
    ui->labelCode->setText(QString::fromStdString(data.codename));
}
