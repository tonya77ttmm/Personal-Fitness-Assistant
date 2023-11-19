#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QWidget>
#include<QMediaPlayer>
#include<QMenu>
#include<QAction>
#include<QPushButton>
class my_video;
class selfinformation ;
class infortable ;
class schem1;
class clock_in;
namespace Ui {
class mainwidget;
}

class mainwidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainwidget(QWidget *parent = 0);
    ~mainwidget();
    //重写paintevent函数，画背景图
    void paintEvent(QPaintEvent *);
signals:
    void sendsignal();
private slots:
    void inspiremusic();
    void closemy_infor();

    void on_pushButton_4_clicked();

   // void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::mainwidget *ui;
    my_video *mv;
    selfinformation *selfi;
    QMediaPlayer *player;
    infortable *it;
    schem1 *sc1;
    clock_in *ci;
    QPushButton *menuButton,*menuButton2;
    QMenu *menu;
    QAction * openAction ;
};

#endif // MAINWIDGET_H
