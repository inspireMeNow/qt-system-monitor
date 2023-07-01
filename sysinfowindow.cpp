#include "sysinfowindow.h"
#include "ui_sysinfowindow.h"

SysInfoWindow::SysInfoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SysInfoWindow)
{
    ui->setupUi(this);
}

SysInfoWindow::~SysInfoWindow()
{
    delete ui;
}
