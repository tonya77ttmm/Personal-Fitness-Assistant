#ifndef INFORTABLE_H
#define INFORTABLE_H
#include<QPushButton>
#include <QWidget>
#include<QMenu>
#include<QAction>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QItemDelegate>
//class Dialog;
namespace Ui {
class infortable;
}

class infortable : public QWidget
{
    Q_OBJECT
private slots:
    void closemy_infor();
    void fresh();
    void receivedata(QString str);


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

public:
    explicit infortable(QWidget *parent = 0);
    ~infortable();
signals:
    void sendsignal();
private:
    Ui::infortable *ui;
    QSqlQuery query;
  QPushButton *menuButton,*menuButton2;
  QMenu *menu;
  QAction * openAction ;
  QSqlTableModel *model,*x1;
  //Dialog *dia;
  QString i1;
};
extern QString ix;
class readonlydelegate:public QItemDelegate
{
   public:
    readonlydelegate(QWidget *parent=NULL):QItemDelegate(parent){}
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override
{
    Q_UNUSED(parent);
     Q_UNUSED(option);
     Q_UNUSED(index);
        return NULL;

}

};

#endif // INFORTABLE_H
