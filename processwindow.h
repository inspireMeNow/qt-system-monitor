#ifndef PROCESSWINDOW_H
#define PROCESSWINDOW_H

#include <QWidget>

namespace Ui {
class ProcessWindow;
}

class ProcessWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessWindow(QWidget *parent = NULL);
    ~ProcessWindow();

private:
    Ui::ProcessWindow *ui;
};

#endif // ProcessWINDOW_H
