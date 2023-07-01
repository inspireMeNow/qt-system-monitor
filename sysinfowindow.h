#ifndef SYSINFOWINDOW_H
#define SYSINFOWINDOW_H

#include <QWidget>

namespace Ui {
class SysInfoWindow;
}

class SysInfoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SysInfoWindow(QWidget *parent = NULL);
    ~SysInfoWindow();

private:
    Ui::SysInfoWindow *ui;
};

#endif // SYSINFOWINDOW_H
