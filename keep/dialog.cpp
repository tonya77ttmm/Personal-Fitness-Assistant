#include "dialog.h"
#include "ui_dialog.h"
#include<QPainter>
#include<my_register.h>
#include<QDebug>
#include<QMessageBox>
#include<infortable.h>
#include<clock_in.h>
#include<selfinformation.h>
#include<calculate.h>
//int x11,prog11;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setFixedSize(820,430);//设置界面固定大小
    inf=new infortable;
    ci=new clock_in;
    sf=new selfinformation;
    setWindowIcon(QIcon(":/pict/picture/1.png"));//设置窗口的小图标
    setWindowTitle("健身世界登录");//设置窗口文字
    mw=new mainwidget;
    re=new my_register;
    connect(this,SIGNAL(senddata(QString)),inf,SLOT(receivedata(QString)));
     connect(this,SIGNAL(senddata(QString)),ci,SLOT(receivedata(QString)));
      connect(this,SIGNAL(senddata(QString)),sf,SLOT(receivedata(QString)));
      connect(this,SIGNAL(motivatemusic()),mw,SLOT(inspiremusic()));

}

Dialog::~Dialog()
{
    delete ui;
     delete mw;
    delete re;
}
void Dialog:: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pict/picture/8.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

void Dialog::on_pushButton_clicked()
{
    //查找
   // bool res=query2.exec("select * from users");//*是全部
    //qDebug()<<res;
   QString  i1=ui->lineEdit->text();i3=i1;
    QString i2=ui->lineEdit_2->text();
    if(i1==""||i2=="")
    {
        QMessageBox::warning(this,"","账户或密码不能为空");
    }
    else
    {
        QString cmd("select * from userss where account=");//select name invalid
        cmd+="'"+i1+"'";
        qDebug()<<cmd;
        //cmd+=';
       bool res=query2.exec(cmd);//*是全部
       qDebug()<<res;
       query2.next();
       qDebug()<<query2.value(1).toString()<<"hahahahah"<<i2;
      if(res&&(query2.value(1).toString()==i2))
       {
          prog11=0;
          qDebug()<<"i3"<<i3;
          emit senddata(i3);
          QMessageBox::information(NULL,"登录成功","登录成功！",QMessageBox::Yes);

              connect(mw,SIGNAL(sendsignal()),this,SLOT(show()));
           emit motivatemusic();
              mw->show();
              this->hide();

         //  this->hide();
          // mw->show();
        }
    //获取登录信息
          // QString i3=QString("insert into users values('%1','%2');").arg(i1).arg(i2);//成功
          /* QString i3=QString("select *from users where account='%1' and password='%2'").arg(i1).arg(i2);//成功
           qDebug()<<i3;
            if(query2.exec(i3))//密码错误也能登录
            {
             QMessageBox::information(NULL,"登录成功","登录成功！",QMessageBox::Yes);
             this->hide();
             mw->show();

            }*/
          else
                QMessageBox::warning(NULL,"Error","用户名或密码错误");
    }
}

void Dialog::on_pushButton_2_clicked()
{
    re->exec();
   //this->hide();
}
