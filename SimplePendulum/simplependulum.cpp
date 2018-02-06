#include "simplependulum.h"
#include "ui_simplependulum.h"
#include <QtGui>
#include <QPalette>
#include <QDebug>

static float time_period=0;
static int DEFAULT_X_OFFSET= 500;
static int DEFAULT_Y_OFFSET= 60;
static int DEFAULT_X_PENDULUM_OFFSET= 40;
static int DEFAULT_Y_PENDULUM_OFFSET= 55;
static int DEFAULT_X_INITIAL_PENDULUM_OFFSET= 480;
static int DEFAULT_Y_INITIAL_PENDULUM_OFFSET= 234;

const float pi =3.14;

SimplePendulum::SimplePendulum(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimplePendulum)
{
    ui->setupUi(this);
}

SimplePendulum::~SimplePendulum()
{
    delete ui;
}

void SimplePendulum::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SimplePendulum::paintEvent(QPaintEvent *pEvent)
{
    int X=DEFAULT_X_OFFSET;
    int Y=DEFAULT_Y_OFFSET;

    QWidget::paintEvent(pEvent);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::red);
    painter.setBrush(QBrush(Qt::green));

    X=DEFAULT_X_OFFSET;
    Y=DEFAULT_Y_OFFSET;
    int XE=DEFAULT_X_PENDULUM_OFFSET;
    int YE=DEFAULT_Y_PENDULUM_OFFSET;
    int XI=DEFAULT_X_INITIAL_PENDULUM_OFFSET;
    int YI=DEFAULT_Y_INITIAL_PENDULUM_OFFSET;

    painter.drawLine(490,60,510,60);
    painter.drawLine(500,60,X,Y+175);
    painter.drawEllipse(XI,YI,XE,YE);



}



void SimplePendulum::on_pushButton_OK_clicked()
{
    QString Data1= ui->textEdit_lenght->toPlainText();
    int iLength=atoi(Data1.toLatin1());
    Initialdisplay(iLength);
}

void SimplePendulum::Initialdisplay(int strLength)
{
    if(strLength)
    {
        DEFAULT_Y_OFFSET=strLength;
        int d=strLength-60;
        DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+d;
        this->repaint();
    }
    ui->pushButton_OK->close();
}

void SimplePendulum::on_pushButton_Reset_clicked()
{
    DEFAULT_X_OFFSET= 500;
       DEFAULT_Y_OFFSET= 60;
       DEFAULT_X_PENDULUM_OFFSET= 40;
       DEFAULT_Y_PENDULUM_OFFSET= 55;
       DEFAULT_X_INITIAL_PENDULUM_OFFSET= 480;
       DEFAULT_Y_INITIAL_PENDULUM_OFFSET= 234;
       this->repaint();
       ui->pushButton_OK->show();
}

void SimplePendulum::display1(int strL)
{

    time_period=2*pi*sqrt(strL/9.8);
    float iPeroid=time_period;
    QString period;
    period.sprintf("%f",iPeroid);
    ui->label_Period->setText(period);
    float Motion=time_period/4;
    float iMotion=Motion;
    QString motion;
    motion.sprintf("%f",iMotion);
    ui->label_Motion->setText(motion);
    for(int i=0;i<Motion;i++)
        {
            QEventLoop loop;
            QTimer::singleShot(300, &loop, SLOT(quit()));
            loop.exec();
            DEFAULT_X_OFFSET=DEFAULT_X_OFFSET+5;
            DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET-2;
            DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET+5;
            DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET-2;
            DEFAULT_X_PENDULUM_OFFSET=DEFAULT_X_PENDULUM_OFFSET;
            DEFAULT_Y_PENDULUM_OFFSET=DEFAULT_Y_PENDULUM_OFFSET;
            this->repaint();
        }
       for(int i=0;i<Motion;i++)
        {
           QEventLoop loop;
           QTimer::singleShot(300, &loop, SLOT(quit()));
           loop.exec();
           DEFAULT_X_OFFSET=DEFAULT_X_OFFSET-5;
           DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET+2;
           DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET-5;
           DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+2;
           this->repaint();

        }
       for(int i=0;i<Motion;i++)
        {
           QEventLoop loop;
           QTimer::singleShot(300, &loop, SLOT(quit()));
           loop.exec();
           DEFAULT_X_OFFSET=DEFAULT_X_OFFSET-5;
           DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET-2;
           DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET-5;
           DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET-2;
           this->repaint();

        }
       for(int i=0;i<Motion;i++)
        {
           QEventLoop loop;
           QTimer::singleShot(300, &loop, SLOT(quit()));
           loop.exec();
           DEFAULT_X_OFFSET=DEFAULT_X_OFFSET+5;
           DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET+2;
           DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET+5;
           DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+2;
           this->repaint();

        }
       for(int i=0;i<Motion-1;i++)
       {
           QEventLoop loop;
           QTimer::singleShot(300, &loop, SLOT(quit()));
           loop.exec();
           DEFAULT_X_OFFSET=DEFAULT_X_OFFSET+5;
           DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET-2;
           DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET+5;
           DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET-2;
           this->repaint();
       }
       for(int i=0;i<Motion-1;i++)
        {
           QEventLoop loop;
           QTimer::singleShot(300, &loop, SLOT(quit()));
           loop.exec();
           DEFAULT_X_OFFSET=DEFAULT_X_OFFSET-5;
           DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET+2;
           DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET-5;
           DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+2;
           this->repaint();

        }
       for(int i=0;i<Motion-1;i++)
        {
           QEventLoop loop;
           QTimer::singleShot(300, &loop, SLOT(quit()));
           loop.exec();
           DEFAULT_X_OFFSET=DEFAULT_X_OFFSET-5;
           DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET-2;
           DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET-5;
           DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET-2;
           this->repaint();

        }
       for(int i=0;i<Motion-1;i++)
        {
           QEventLoop loop;
           QTimer::singleShot(300, &loop, SLOT(quit()));
           loop.exec();
           DEFAULT_X_OFFSET=DEFAULT_X_OFFSET+5;
           DEFAULT_Y_OFFSET=DEFAULT_Y_OFFSET+2;
           DEFAULT_X_INITIAL_PENDULUM_OFFSET=DEFAULT_X_INITIAL_PENDULUM_OFFSET+5;
           DEFAULT_Y_INITIAL_PENDULUM_OFFSET=DEFAULT_Y_INITIAL_PENDULUM_OFFSET+2;
           this->repaint();

        }

    }



void SimplePendulum::on_actionStart_triggered()
{
    display1(DEFAULT_Y_OFFSET);
     //multithread->abort();
     //thread->wait();
     //multithread->requestThread();
     //display();
}

void SimplePendulum::on_actionPause_triggered()
{
    //multithread->abort();
    //thread->wait(
}

void SimplePendulum::on_actionStop_triggered()
{

}

void SimplePendulum::on_actionResume_triggered()
{
    //multithread->abort();
     //multithread->resume();
     //thread->wait();

}
