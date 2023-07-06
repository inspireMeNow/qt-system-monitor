#ifndef CPUWINDOW_H
#define CPUWINDOW_H

#include <QWidget>
#include "cpuinfo.h"
namespace Ui {
class CpuWindow;
}

class CpuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CpuWindow(QWidget *parent = NULL);
    ~CpuWindow();
    void updateTable();

private:
    Ui::CpuWindow *ui;
};

#endif // CPUWINDOW_H
