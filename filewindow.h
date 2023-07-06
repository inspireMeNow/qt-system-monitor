#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QWidget>
#include "fileinfo.h"

namespace Ui {
class FileWindow;
}

class FileWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FileWindow(QWidget *parent = NULL);
    ~FileWindow();
    void updateTable();

private:
    Ui::FileWindow *ui;
};

#endif // FILEWINDOW_H
