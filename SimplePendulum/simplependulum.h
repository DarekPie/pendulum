#ifndef SIMPLEPENDULUM_H
#define SIMPLEPENDULUM_H

#include <QMainWindow>

namespace Ui {
class SimplePendulum;
}

class SimplePendulum : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimplePendulum(QWidget *parent = 0);
    ~SimplePendulum();
    void Initialdisplay(int l);
    void display1(int c);

private:
    Ui::SimplePendulum *ui;

protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
private slots:
    void on_actionStart_activated();
    void on_actionPause_activated();
    void on_actionResume_activated();
    void on_pushButton_OK_clicked();
    void display(int a);
    void on_pushButton_Reset_clicked();
    void on_actionStart_triggered();
    void on_actionPause_triggered();
    void on_actionStop_triggered();
    void on_actionResume_triggered();
};

#endif // SIMPLEPENDULUM_H
