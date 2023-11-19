#ifndef SCHEM1_H
#define SCHEM1_H
#include<QTimer>
#include<QMediaPlayer>
#include <QWidget>
#include<QTime>
#include<QPushButton>
#include<QMenu>
namespace Ui {
class schem1;
}

class schem1 : public QWidget
{
    Q_OBJECT

public:
    explicit schem1(QWidget *parent = 0);
    ~schem1();
private slots:
    void closemy_infor();
    void TimerResponse();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
signals:
    void sendsignal();
private:
    Ui::schem1 *ui;
    QTime time;//显示时间
    QMediaPlayer *player;
    QTimer *timer;//定时
    //QSqlQuery query;
    QPushButton *menuButton,*menuButton2;
    QMenu *menu;
    QAction * openAction ;

};

#endif // SCHEM1_H
