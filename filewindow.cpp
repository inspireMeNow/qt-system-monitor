#include "filewindow.h"
#include "ui_filewindow.h"

FileWindow::FileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileWindow)
{
    ui->setupUi(this);
}

FileWindow::~FileWindow()
{
    delete ui;
}
