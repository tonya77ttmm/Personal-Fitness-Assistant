#include "clock_in.h"
#include "ui_clock_in.h"
#include<QDebug>
#include<QTime>
#include<QMessageBox>
#include<QString>
#include<calculate.h>
//int x11,prog11;
QString i7;

clock_in::clock_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clock_in)
{
    ui->setupUi(this);
    timer=new QTimer;
    this->setAutoFillBackground(true);
    this->setStyleSheet("QWidget{background-color:rgb(255,228,181);}");
    setWindowOpacity(1);//设置透明度
    //setFixedSize(869,496);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint); // 设置成无边框对话框|
    menuButton = new QPushButton(this);
    menuButton->setGeometry(10,0,130,84);
    //menuButton2->setGeometry(34,0,0,34);
    menuButton->setText("每日打卡");
    menuButton->setStyleSheet("QPushButton{border:none; color:rgb(139,69,19); font-size:18px; font-family: Comic Sans MS; }");
    connect(menuButton,&QPushButton::clicked,[=](){qDebug()<<"xixixi";});
    menu = new QMenu;
    openAction = menu->addAction("关闭");
    menu->setStyleSheet(" QMenu{border:none } "
                        "QMenu::item{border:none; font-size:13px;  padding-left:20px; background-color:white; height:25px; width:50px; }"
                         "QMenu::item:selected{ background-color:rgb(139,69,19)}");

    connect(openAction, SIGNAL(triggered(bool)), this,  SLOT(closemy_infor()));
    menuButton->setMenu(menu);
    ui->progressBar->setValue(0);

    connect(timer,SIGNAL(timeout()),this,SLOT(process()));


}
void clock_in::receivedata(QString str)
{
    qDebug()<<"str"<<str;
    i1=str; i7=i1;
    qDebug()<<"clock_ini1:"<<i1;
    QString cmd("create table skg");//数据表开头不能是数字
    cmd+=i1;
    QString s("(my_date varchar(30) primary key,dingdong varchar(20))");//不能使用QString类型
    cmd+=s;
    qDebug()<<"cmd"<<cmd;
  //  bool res= query.exec("drop table sccc");
    //qDebug()<<"7 drop"<<res;
  // bool  res= query.exec("drop table ccc");
      // qDebug()<<"7 drop"<<res;
    bool res=query.exec(cmd);
    qDebug()<<"7 create"<<res;
   // prog=0;

}
void clock_in::process()
{
    if(prog11==0)
    {prog=0;}
     qDebug()<<"进度条加载";
    prog++;
    prog=prog>100?100:prog;
    qDebug()<<"prog:"<<prog;
    prog11=prog;
    ui->progressBar->setValue(prog);
}
void clock_in::closemy_infor()
{
    emit sendsignal();
    this->hide();
}
clock_in::~clock_in()
{
    delete ui;
}
int clock_in::calculate(int i)
{
    x=(i*60)*10;
    qDebug()<<"x:"<<x;//timer->start(x);
      //返回一个int
    x11=x;
   return x11;
}
void clock_in::on_pushButton_clicked()
{
  i= ui->lineEdit->text().toInt();
  calculate(i);
  /*x=(i*60)*10;
  qDebug()<<"x:"<<x;//timer->start(x);
  //返回一个int
  return x;*/
}
void clock_in::pbpaly()
{

    qDebug()<<"x11"<<x11;
    timer->start(x11);

}
void clock_in::pbstop()
{
    timer->stop();
}

void clock_in::on_pushButton_2_clicked()
{
    qDebug()<<"progshuaxin:"<<prog11;
     qDebug()<<"prog11:"<<prog11;
    ui->progressBar->setValue(prog11);
}

void clock_in::on_pushButton_3_clicked()
{
    qDebug()<<"打卡";
    QDateTime local(QDateTime:: currentDateTime());
    QString localtime=local.toString("yyyy-MM-dd");
    qDebug()<<localtime;


    if(prog11==100)
       {
             QString cmd("insert into skg");
             qDebug()<<"i7"<<i7;
             cmd+=i7;
              QString i2(" values('%1','已打卡')");
              cmd+=i2;
              qDebug()<<"cmd"<<cmd;
              QString i6=QString(cmd).arg(localtime);
              qDebug()<<"i6"<<i6;
              bool res= query.exec(i6);
              qDebug()<<"i6 insert"<<res;
         if(res)
        { QMessageBox::information(NULL,"打卡成功","今日已成功打卡！",QMessageBox::Yes);}
         else
         {
             QMessageBox::information(NULL,"已打卡","今日已打卡，明天再来打卡吧！",QMessageBox::Yes);
         }
        //messagebox..dakachenggg*/
        //插入数据表
    }
    else
    {
       QMessageBox::information(NULL,"打卡失败","完成任务再来打吧！",QMessageBox::Yes);
    }

}
