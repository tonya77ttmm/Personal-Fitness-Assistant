#include "mainwidget.h"
#include "ui_mainwidget.h"
#include<QDebug>
#include<QBitmap>
#include<QPainter>
#include<my_video.h>
#include<selfinformation.h>
#include<infortable.h>
#include<schem1.h>
#include<clock_in.h>
int x11=0,prog11=0;
mainwidget::mainwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwidget)
{
    ui->setupUi(this);
    selfi=new selfinformation;
    player=new QMediaPlayer;
    mv=new my_video;
    it=new infortable;
    sc1=new schem1;
    ci=new clock_in;
    setFixedSize(1018,668);//设置界面固定大小
    setWindowIcon(QIcon(":/pict/picture/1.png"));//设置窗口的小图标
    setWindowTitle("健身世界");//设置窗口文字
   /* menuButton = new QPushButton(this);
    menuButton->setGeometry(10,0,130,84);
    //menuButton2->setGeometry(34,0,0,34);
    menuButton->setText("个人信息");
    menuButton->setStyleSheet("QPushButton{border:none; color:rgb(139,69,19); font-size:18px; font-family: Comic Sans MS; }");
    connect(menuButton,&QPushButton::clicked,[=](){qDebug()<<"xixixi";});*/
    //ui->pushButton->resize(85,85);
    menuButton = new QPushButton(this);
    menuButton->setGeometry(900,0,130,84);
    //menuButton2->setGeometry(34,0,0,34);
    menuButton->setText("主界面");
    menuButton->setStyleSheet("QPushButton{ border:none; color:rgb(0,0,0); font-size:18px; font-family: Comic Sans MS; }");
    connect(menuButton,&QPushButton::clicked,[=](){qDebug()<<"xixixi";});
    menu = new QMenu;
    openAction = menu->addAction("关闭");
    menu->setStyleSheet(" QMenu{border:none } "
                        "QMenu::item{border:none; font-size:13px;  padding-left:20px; background-color:white; height:25px; width:50px; }"
                         "QMenu::item:selected{ background-color:rgb(139,69,19)}");

    connect(openAction, SIGNAL(triggered(bool)), this,  SLOT(closemy_infor()));
    menuButton->setMenu(menu);
    ui->pushButton->resize(90,90);
    ui->pushButton->setStyleSheet("QPushButton{ background:rgb(225,255,255);color:rgb(0,0,0); font-size:18px; font-family: Comic Sans MS;border-radius:40px} ");
    ui->pushButton_6->resize(90,90);
    ui->pushButton_6->setStyleSheet("QPushButton{ background:rgb(210,180,140);color:rgb(0,0,0); font-size:18px; font-family: Comic Sans MS;border-radius:40px }");
    ui->pushButton_3->resize(90,90);
    ui->pushButton_3->setStyleSheet("QPushButton{ background:rgb(255,228,225);color:rgb(0,0,0); font-size:18px; font-family: Comic Sans MS;border-radius:40px }");
    ui->pushButton_4->resize(100,100);
    ui->pushButton_4->setStyleSheet("QPushButton{ background:rgb(100,149,237);color:rgb(0,0,0); font-size:18px; font-family: Comic Sans MS;border-radius:40px }");
    ui->pushButton_5->resize(90,90);
    ui->pushButton_5->setStyleSheet("QPushButton{ background:rgb(255,255,224);color:rgb(0,0,0); font-size:18px; font-family: Comic Sans MS;border-radius:40px }");
    //ui->pushButton_8->resize(90,90);
    //ui->pushButton_8->setStyleSheet("QPushButton{ background:rgb(255,228,225);color:rgb(0,0,0); font-size:18px; font-family: Comic Sans MS;border-radius:40px} ");
    //ui->pushButton_2->setStyleSheet("QPushButton{ color:rgb(75,0,130); font-size:18px; font-family: Comic Sans MS; }");
    ui->pushButton_7->setStyleSheet("QPushButton{ color:rgb(75,0,130); font-size:18px; font-family: Comic Sans MS; }");
   // my_pushbotton * selfinformation=new my_pushbotton(":/pict/picture/6.png");
   //selfinformation->setParent(this);//加载到当前窗口
   //selfinformation->move(this->width()*0.1,this->height()*0.1);
  // selfinformation->resize(100,100);
   //selfinformation->setStyleSheet("border-radius:40px");


}
void mainwidget::closemy_infor()
{
    qDebug()<<"close";
    emit sendsignal();
    this->close();
}
void mainwidget:: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pict/picture/2.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

mainwidget::~mainwidget()
{
    delete ui;
    delete mv;
}


void mainwidget::on_pushButton_4_clicked()
{
    connect(mv,SIGNAL(sendsignal()),this,SLOT(show()));
    mv->show();
    this->hide();
}

void mainwidget::inspiremusic()
{
    player->setMedia(QMediaContent(QUrl::fromLocalFile("D:/QT/PRO/build-keep-Desktop_Qt_5_9_0_MinGW_32bit-Debug/debug/2.mp3")));
    player->setVolume(50);
     player->play();
}

void mainwidget::on_pushButton_7_clicked()
{
    player->stop();
}

void mainwidget::on_pushButton_clicked()
{
    connect(selfi,SIGNAL(sendsignal()),this,SLOT(show()));
    selfi->show();
    this->hide();
}

void mainwidget::on_pushButton_5_clicked()
{
    connect(it,SIGNAL(sendsignal()),this,SLOT(show()));
    it->show();
    this->hide();
}


void mainwidget::on_pushButton_3_clicked()
{
    connect(sc1,SIGNAL(sendsignal()),this,SLOT(show()));
    sc1->show();
    this->hide();
}

void mainwidget::on_pushButton_6_clicked()
{
    connect(ci,SIGNAL(sendsignal()),this,SLOT(show()));
    ci->show();
    this->hide();
}
