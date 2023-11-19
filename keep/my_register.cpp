#include "my_register.h"
#include "ui_my_register.h"
#include<QPainter>
#include<QDebug>
#include<QMessageBox>
class Dialog;
my_register::my_register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::my_register)
{
    ui->setupUi(this);
    //dia=new Dialog;
    setFixedSize(820,430);//设置界面固定大小
    setWindowIcon(QIcon(":/pict/picture/1.png"));//设置窗口的小图标
    setWindowTitle("健身世界注册");//设置窗口文字
}

my_register::~my_register()
{
    delete ui;
    //delete dia;
}

void my_register::on_pushButton_clicked()
{
    //创建表
    //bool res=query.exec("drop table user");
    //qDebug()<<res<<"user drop";
   bool res=query.exec("create table userss(account varchar(20) primary key,password varchar(20))");
    qDebug()<<res<<"userss create";
    QString i1=ui->lineEdit->text();
    QString i2=ui->lineEdit_3->text();
    if(i1==""||i2=="")
    {
        QMessageBox::warning(this,"","账户或密码不能为空");
    }
    else
    {
    //获取注册 信息
           QString i3=QString("insert into userss values('%1','%2');").arg(i1).arg(i2);//成功
           QString i4=QString("select *from userss where account='%1'").arg(i1);//成功
           if(query.exec(i4)&&query.first())
            QMessageBox::warning(NULL,"Error","用户名重复");
            else if(query.exec(i3))
            {
             QMessageBox::information(NULL,"注册成功","注册成功！",QMessageBox::Yes);
             this->hide();
           }

            else
                QMessageBox::warning(NULL,"Error","注册失败，请重试！");
    }
}

  //dia->show();


void my_register:: paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/pict/picture/8.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


}
