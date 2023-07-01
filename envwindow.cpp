#include "envwindow.h"
#include "ui_envwindow.h"

EnvWindow::EnvWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvWindow)
{
    ui->setupUi(this);
}

EnvWindow::~EnvWindow()
{
    delete ui;
}
