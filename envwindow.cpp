#include "envwindow.h"
#include "ui_envwindow.h"

EnvWindow::EnvWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnvWindow)
{
    ui->setupUi(this);
    updateTable();
}

EnvWindow::~EnvWindow()
{
    delete ui;
}

void EnvWindow::updateTable()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    std::vector<Software> data(getSoftwareInfo());
    int rowPosition=0;
    for (int i=0;i<data.size();i++) {
        rowPosition = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowPosition);
        ui->tableWidget->setItem(rowPosition,0,new QTableWidgetItem(QString::fromStdString(data[i].name)));
    }
}
