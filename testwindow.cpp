#include "testwindow.h"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    led_0=0;
    led_1=0;
    led_2=0;
    led_3=0;

}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::on_btnLed0_clicked()
{
    //按下切换状态，即亮变暗，暗变亮
    int led_no=0;
    led_0 +=1;
    led_0=led_0%2;
    LedTest(led_no,led_0);
}

void TestWindow::on_btnLed1_clicked()
{
    int led_no=1;
    led_1 +=1;
    led_1=led_1%2;
    LedTest(led_no,led_1);
}

void TestWindow::on_btnLed2_clicked()
{
    int led_no=2;
    led_2 +=1;
    led_2=led_2%2;
    LedTest(led_no,led_2);
}

void TestWindow::on_btnLed3_clicked()
{
    int led_no=3;
    led_3 +=1;
    led_3=led_3%2;
    LedTest(led_no,led_3);
}

void TestWindow::on_btnBegin_clicked()
{
    set_buzzer_freq(0);
}

void TestWindow::on_btnEnd_clicked()
{
    close_buzzer();
}

void TestWindow::on_btnAdd_clicked()
{
    set_buzzer_freq(0);
}

void TestWindow::on_btnDet_clicked()
{
    set_buzzer_freq(1);
}

void TestWindow::on_toolButton_clicked()
{
    ui->textBrowser->append(QString::fromStdString(BeginButtonTest()));
}


