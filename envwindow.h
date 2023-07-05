#ifndef ENVWINDOW_H
#define ENVWINDOW_H

#include <QWidget>
#include "envinfo.h"

namespace Ui {
class EnvWindow;
}

class EnvWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EnvWindow(QWidget *parent = NULL);
    ~EnvWindow();
    void updateTable();

private:
    Ui::EnvWindow *ui;
};

#endif // ENVWINDOW_H
