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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QButtonGroup btnGroup;
    ProcessWindow processWnd;
    CpuWindow cpuWnd;
    MemoryWindow memoryWnd;
    EnvWindow envWnd;
    FileWindow fileWnd;
    NetworkWindow networkWnd;
    SysInfoWindow sysinfoWnd;
};
#endif // MAINWINDOW_H
