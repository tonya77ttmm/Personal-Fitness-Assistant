#ifndef SELFINFORMATION_H
#define SELFINFORMATION_H
#include<QPushButton>
#include <QWidget>
#include<QMenu>
#include<QAction>
#include<QSqlTableModel>
#include<QSqlQuery>
namespace Ui {
class selfinformation;
}

class selfinformation : public QWidget
{
    Q_OBJECT

public:
    explicit selfinformation(QWidget *parent = 0);
    ~selfinformation();
private slots:
    void closemy_infor();
    void receivedata(QString str);



    //void on_pushButton_3_clicked();

    void on_pushButton_clicked();

signals:
    void sendsignal();


private:
      QSqlQuery query;
    Ui::selfinformation *ui;
    QPushButton *menuButton;
    QMenu *menu;
    QAction * openAction ;
    QSqlTableModel *model;

};
extern QString i1;

#endif // SELFINFORMATION_H
