#ifndef MEMORYWINDOW_H
#define MEMORYWINDOW_H

#include <QWidget>
#include "memoryinfo.h"

namespace Ui {
class MemoryWindow;
}

class MemoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryWindow(QWidget *parent = NULL);
    ~MemoryWindow();
    void updateTable();
    void timerEvent(QTimerEvent *event);

private:
    Ui::MemoryWindow *ui;
};

#endif // MEMORYWINDOW_H
