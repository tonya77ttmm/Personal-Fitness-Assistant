#ifndef MY_REGISTER_H
#define MY_REGISTER_H
//#include<dialog.h>
#include <QDialog>
#include<QSqlQuery>//向数据库发命令
namespace Ui {
class my_register;
}
class Dialog;
class my_register : public QDialog
{
    Q_OBJECT

public:
    explicit my_register(QWidget *parent = 0);
    ~my_register();
      void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::my_register *ui;
     QSqlQuery query;
    Dialog *l;

};

#endif // MY_REGISTER_H
