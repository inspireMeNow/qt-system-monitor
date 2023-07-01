#include "networkwindow.h"
#include "ui_networkwindow.h"

NetworkWindow::NetworkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetworkWindow)
{
    ui->setupUi(this);
}

NetworkWindow::~NetworkWindow()
{
    delete ui;
}
