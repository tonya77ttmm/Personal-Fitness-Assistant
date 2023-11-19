#include "selfinformation.h"
#include "ui_selfinformation.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlError>
#include<QLineEdit>

QString i1("skg");
selfinformation::selfinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::selfinformation)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setStyleSheet("QWidget{background-color:rgb(240,255,255);}");
    setWindowOpacity(1);//设置透明度
    setFixedSize(600,700);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint); // 设置成无边框对话框|
    menuButton = new QPushButton(this);
    menuButton->setGeometry(10,10,100,84);
    //menuButton2->setGeometry(34,0,0,34);
    menuButton->setText("统计信息");
    menuButton->setStyleSheet("QPushButton{border:none; color:rgb(139,69,19); font-size:21px; font-family: Comic Sans MS; }");
    connect(menuButton,&QPushButton::clicked,[=](){qDebug()<<"xixixi";});
    menu = new QMenu;
    openAction = menu->addAction("关闭");
    menu->setStyleSheet(" QMenu{border:none } "
                        "QMenu::item{border:none; font-size:13px;  padding-left:20px; background-color:white; height:25px; width:50px; }"
                         "QMenu::item:selected{ background-color:rgb(139,69,19)}");


    connect(openAction, SIGNAL(triggered(bool)), this,  SLOT(closemy_infor()));
     menuButton->setMenu(menu);

     //数据库

  /* query.exec("drop table infor");
     bool res=query.exec("create table infor(account varchar(20) primary key,name varchar(20),height int,weight int,sex varchar(5))");
     qDebug()<<"infor create"<<res;*/

   //  bool res=query.exec("select * from infor where account= ");//*是全部
     //qDebug()<<res;   设置外键关联数据表stu和infor
   //判断是否还有数据，返回bool
       /*while(query.next())
     {
         qDebug()<<query.value(0).toString()<<":"<<query.value(1).toString()<<":"<<query.value(2).toInt()<<":"<<query.value(3).toInt()<<":"<<query.value(4).toString();//取一行中的某个
       }
     ui->lineEdit->setPlaceholderText(tr(i1.toLatin1()));
     ui->lineEdit_2->setPlaceholderText(tr(i2.toLatin1()));
     ui->lineEdit_3->setPlaceholderText(tr(i3.toLatin1()));
     ui->lineEdit_4->setPlaceholderText(tr(i4.toLatin1()));
     ui->lineEdit_5->setPlaceholderText(tr(i5.toLatin1()));*/
     model=new QSqlTableModel;
     //x1=new QSqlTableModel;


     model->setHeaderData(0,Qt::Horizontal,"日期");
     model->setHeaderData(1,Qt::Horizontal,"打卡情况");
     /*model->setHeaderData(2,Qt::Horizontal,"身高");
     model->setHeaderData(3,Qt::Horizontal,"体重");
     model->setHeaderData(4,Qt::Horizontal,"性别");
     model->setEditStrategy(QSqlTableModel::OnManualSubmit);
     readonlydelegate *re=new readonlydelegate;
     ui->tableView->setItemDelegateForColumn(0,re);*/




}
void selfinformation::receivedata(QString str)
{
    i1+=str;
    model->setTable(i1);//制定使用哪个表
    //把model放在view
    ui->tableView->setModel(model);
    model->setHeaderData(0,Qt::Horizontal,"日期");
    model->setHeaderData(1,Qt::Horizontal,"打卡情况");
    model->select();
}
void selfinformation::closemy_infor()
{
    qDebug()<<"close";
    emit sendsignal();
    this->close();
}
selfinformation::~selfinformation()
{
    delete ui;
}


void selfinformation::on_pushButton_clicked()
{
    model->setTable(i1);//制定使用哪个表
    //把model放在view
    ui->tableView->setModel(model);
    model->setHeaderData(0,Qt::Horizontal,"日期");
    model->setHeaderData(1,Qt::Horizontal,"打卡情况");
    model->select();
    int i=model->rowCount();
    QString c=QString("%1").arg(i);
    ui->label_2->setText(c);
   // ui->tableView->
}
