#include "filewindow.h"
#include "ui_filewindow.h"

FileWindow::FileWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileWindow)
{
    ui->setupUi(this);
    updateTable();
}

FileWindow::~FileWindow()
{
    delete ui;
}

void FileWindow::updateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    std::vector<File> data(getFileInfo());
    int rowPosition=0;
    for (int i=0;i<data.size();i++) {
        rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);
        ui->tableWidget->setItem(rowPosition,0,new QTableWidgetItem(QString::fromStdString(data[i].filesys)));
        ui->tableWidget->setItem(rowPosition,1,new QTableWidgetItem(QString::fromStdString(data[i].size)));
        ui->tableWidget->setItem(rowPosition,2,new QTableWidgetItem(QString::fromStdString(data[i].used)));
        ui->tableWidget->setItem(rowPosition,3,new QTableWidgetItem(QString::fromStdString(data[i].avail)));
        ui->tableWidget->setItem(rowPosition,4,new QTableWidgetItem(QString::fromStdString(data[i].userdperc)));
        ui->tableWidget->setItem(rowPosition,5,new QTableWidgetItem(QString::fromStdString(data[i].mounted)));
    }
}

