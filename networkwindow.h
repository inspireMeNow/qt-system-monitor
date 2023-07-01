#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QWidget>

namespace Ui {
class NetworkWindow;
}

class NetworkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkWindow(QWidget *parent = NULL);
    ~NetworkWindow();

private:
    Ui::NetworkWindow *ui;
};

#endif // NETWORKWINDOW_H
