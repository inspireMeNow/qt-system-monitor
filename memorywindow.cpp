#include "memorywindow.h"
#include "ui_memorywindow.h"

MemoryWindow::MemoryWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryWindow)
{
    ui->setupUi(this);
}

MemoryWindow::~MemoryWindow()
{
    delete ui;
}
