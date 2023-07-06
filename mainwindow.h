#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>

#include "memorywindow.h"
#include "processwindow.h"
#include "cpuwindow.h"
#include "envwindow.h"
#include "filewindow.h"
#include "networkwindow.h"
#include "sysinfowindow.h"
#include "testwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();

private slots:
    void on_btnProcess_clicked();

    void on_btnCpu_clicked();

    void on_btnMemory_clicked();

    void on_btnNetwork_clicked();

    void on_btnFile_clicked();

    void on_btnEnv_clicked();

    void on_btnSysInfo_clicked();

    void on_btnTest_clicked();

private:
    Ui::MainWindow *ui;

    //QButtonGroup btnGroup;
    ProcessWindow processWnd;
    CpuWindow cpuWnd;
    MemoryWindow memoryWnd;
    EnvWindow envWnd;
    FileWindow fileWnd;
    NetworkWindow networkWnd;
    SysInfoWindow sysinfoWnd;
    TestWindow testWnd;
};
#endif // MAINWINDOW_H
