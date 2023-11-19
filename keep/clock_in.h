#ifndef CLOCK_IN_H
#define CLOCK_IN_H

#include <QWidget>
#include<QPushButton>
#include<QMenu>
#include<QTimer>
#include<QSqlQuery>
namespace Ui {
class clock_in;
}

class clock_in : public QWidget
{
    Q_OBJECT
signals:
    void sendsignal();
public:

    explicit clock_in(QWidget *parent = 0);
    ~clock_in();
    int calculate(int i);
private slots:
    void closemy_infor();
    void process();
   void on_pushButton_clicked();
    void pbpaly();
    void pbstop();
    void receivedata(QString str);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::clock_in *ui;
  int prog=0,x;
    QTimer *timer;
    QPushButton *menuButton,*menuButton2;
    QMenu *menu;
    QAction * openAction ;
      int i;

     QString i1;
    QSqlQuery query;
};
 extern QString i7;

#endif // CLOCK_IN_H
