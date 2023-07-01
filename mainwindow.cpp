#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->addWidget(&processWnd);
    ui->stackedWidget->addWidget(&cpuWnd);
    ui->stackedWidget->addWidget(&memoryWnd);
    ui->stackedWidget->addWidget(&networkWnd);
    ui->stackedWidget->addWidget(&fileWnd);
    ui->stackedWidget->addWidget(&envWnd);
    ui->stackedWidget->addWidget(&sysinfoWnd);

//    btnGroup.setExclusive(false);
    btnGroup.addButton(ui->btnProcess, 0);
    btnGroup.addButton(ui->btnCpu, 1);
    btnGroup.addButton(ui->btnMemory, 2);
    btnGroup.addButton(ui->btnNetwork,3);
    btnGroup.addButton(ui->btnFile,4);
    btnGroup.addButton(ui->btnEnv,5);
    btnGroup.addButton(ui->btnSysInfo,6);
    // connect(&btnGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // 设置默认选中的页面
    btnGroup.button(0)->setChecked(true);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
