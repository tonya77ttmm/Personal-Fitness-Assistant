#ifndef DIALOG_H
#define DIALOG_H
#include"mainwidget.h"
#include"my_register.h"
#include <QDialog>
#include<QSqlQuery>//向数据库发命令
//class my_register;
class infortable;
class clock_in;
class selfinformation;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
     void paintEvent(QPaintEvent *);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
signals:
    void senddata(QString str);
    void motivatemusic();
private:
    Ui::Dialog *ui;
    mainwidget *mw;
    my_register *re;
    QSqlQuery query2;
    QString i3;
    infortable *inf;
    clock_in *ci;
    selfinformation *sf;
};

#endif // DIALOG_H
