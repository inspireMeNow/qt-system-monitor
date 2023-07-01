#include "cpuwindow.h"
#include "ui_cpuwindow.h"

CpuWindow::CpuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CpuWindow)
{
    ui->setupUi(this);
}

CpuWindow::~CpuWindow()
{
    delete ui;
}
