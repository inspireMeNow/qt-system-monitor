#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QWidget>
#include "LedTest.h"
#include "ButtonTest.h"
#include "PWMTest.h"

namespace Ui {
class TestWindow;
}

class TestWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = NULL);
    ~TestWindow();

private slots:
    void on_btnLed0_clicked();

    void on_btnLed1_clicked();

    void on_btnLed2_clicked();

    void on_btnLed3_clicked();

    void on_btnBegin_clicked();

    void on_btnEnd_clicked();

    void on_btnAdd_clicked();

    void on_btnDet_clicked();

    void on_toolButton_clicked();

    // void on_toolButton_2_clicked();

private:
    Ui::TestWindow *ui;
    int led_0;
    int led_1;
    int led_2;
    int led_3;
};

#endif // TESTWINDOW_H
