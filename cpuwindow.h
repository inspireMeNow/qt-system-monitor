#ifndef CPUWINDOW_H
#define CPUWINDOW_H

#include <QWidget>

namespace Ui {
class CpuWindow;
}

class CpuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CpuWindow(QWidget *parent = NULL);
    ~CpuWindow();

private:
    Ui::CpuWindow *ui;
};

#endif // CPUWINDOW_H
