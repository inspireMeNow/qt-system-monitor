#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QWidget>

namespace Ui {
class FileWindow;
}

class FileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FileWindow(QWidget *parent = NULL);
    ~FileWindow();

private:
    Ui::FileWindow *ui;
};

#endif // FILEWINDOW_H
