#ifndef MEMORYWINDOW_H
#define MEMORYWINDOW_H

#include <QWidget>

namespace Ui {
class MemoryWindow;
}

class MemoryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryWindow(QWidget *parent = NULL);
    ~MemoryWindow();

private:
    Ui::MemoryWindow *ui;
};

#endif // MEMORYWINDOW_H
