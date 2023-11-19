#include "schem1.h"
#include "ui_schem1.h"
#include<QLabel>
schem1::schem1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::schem1)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setStyleSheet("QWidget{background-color:rgb(255,240,245);}");
    setWindowOpacity(1);//设置透明度
    //setFixedSize(869,496);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint); // 设置成无边框对话框|
    menuButton = new QPushButton(this);
    menuButton->setGeometry(10,0,130,84);
    //menuButton2->setGeometry(34,0,0,34);
    menuButton->setText("定时闹钟");
    menuButton->setStyleSheet("QPushButton{border:none; color:rgb(139,69,19); font-size:18px; font-family: Comic Sans MS; }");
    connect(menuButton,&QPushButton::clicked,[=](){qDebug()<<"xixixi";});
    menu = new QMenu;
    openAction = menu->addAction("关闭");
    menu->setStyleSheet(" QMenu{border:none } "
                        "QMenu::item{border:none; font-size:13px;  padding-left:20px; background-color:white; height:25px; width:50px; }"
                         "QMenu::item:selected{ background-color:rgb(139,69,19)}");

    connect(openAction, SIGNAL(triggered(bool)), this,  SLOT(closemy_infor()));
      menuButton->setMenu(menu);
    player=new QMediaPlayer;
    timer=new QTimer;
    ui->label_2->setVisible(false);
    connect(timer,SIGNAL(timeout()),this,SLOT(TimerResponse()));
}
void schem1::TimerResponse()
{
    if(time.hour()==QTime::currentTime().hour()&&time.minute()==QTime::currentTime().minute())
    {
        this->show();//到时自动弹出
        ui->label_2->setVisible(true);
        QFont f;
        f.setPointSize(24);
        ui->label_2->setSizeIncrement(311,101);
        ui->label_2->setFont(f);
        player->setMedia(QMediaContent(QUrl::fromLocalFile("D:/QT/PRO/build-keep-Desktop_Qt_5_9_0_MinGW_32bit-Debug/debug/3.mp3")));
        player->play();
        timer->setSingleShot(true);//每次到点只响一次
    }
}
schem1::~schem1()
{
    delete ui;
}

void schem1::on_pushButton_clicked()
{
    timer->start(500);
    time=ui->timeEdit->time();
}

void schem1::on_pushButton_2_clicked()
{
    player->stop();
}
void schem1::closemy_infor()
{
    qDebug()<<"close";
    emit sendsignal();
    this->hide();
}
