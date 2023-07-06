#ifndef PROCESSWINDOW_H
#define PROCESSWINDOW_H

#include <QWidget>
#include "processinfo.h"

namespace Ui {
class ProcessWindow;
}

class ProcessWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessWindow(QWidget *parent = NULL);
    ~ProcessWindow();
    void updateTable();
    void timerEvent(QTimerEvent *event);

private:
    Ui::ProcessWindow *ui;
};

#endif // ProcessWINDOW_H
