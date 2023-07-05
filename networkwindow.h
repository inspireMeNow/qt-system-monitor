#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QWidget>
#include "networkinfo.h"

namespace Ui {
class NetworkWindow;
}

class NetworkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = NULL);
    ~NetworkWindow();
    void updateTable();
    void timerEvent(QTimerEvent *event);

private:
    Ui::NetworkWindow *ui;
};

#endif // NETWORKWINDOW_H
