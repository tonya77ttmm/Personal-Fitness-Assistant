#include "infortable.h"
#include "ui_infortable.h"
#include<QDebug>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlError>
#include<QLineEdit>
QString ix;
infortable::infortable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infortable)
{
    ui->setupUi(this);
 //  dia=new Dialog;
    //connect(dia,SIGNAL(senddata(QString)),this,SLOT(receivedata(QString)));
    this->setAutoFillBackground(true);
    this->setStyleSheet("QWidget{background-color:rgb(255,255,224);}");
    setWindowOpacity(1);//设置透明度
    setFixedSize(869,496);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint); // 设置成无边框对话框|
    menuButton = new QPushButton(this);
    menuButton->setGeometry(10,0,130,84);
    //menuButton2->setGeometry(34,0,0,34);
    menuButton->setText("显示个人信息");
    menuButton->setStyleSheet("QPushButton{border:none; color:rgb(139,69,19); font-size:18px; font-family: Comic Sans MS; }");
    connect(menuButton,&QPushButton::clicked,[=](){qDebug()<<"xixixi";});
    menu = new QMenu;
    openAction = menu->addAction("关闭");
    menu->setStyleSheet(" QMenu{border:none } "
                        "QMenu::item{border:none; font-size:13px;  padding-left:20px; background-color:white; height:25px; width:50px; }"
                         "QMenu::item:selected{ background-color:rgb(139,69,19)}");

    connect(openAction, SIGNAL(triggered(bool)), this,  SLOT(closemy_infor()));
     menuButton->setMenu(menu);
     menuButton2=new QPushButton(this);
     menuButton2->setGeometry(600,10,130,84);
     menuButton2->setText("刷新");
     connect(menuButton2,&QPushButton::clicked,[=](){fresh();});
     //建表
    // query.exec("drop table infor");
     bool res=query.exec("create table infor(account varchar(20) primary key,name varchar(20),height int,weight int,sex varchar(5))");
     qDebug()<<"infor create"<<res;

     model=new QSqlTableModel;
     x1=new QSqlTableModel;



}

/*void selfinformation::receivedata(QString str)
{
    i1=str;
    model->setTable(str);//制定使用哪个表
    //把model放在view
    ui->tableView->setModel(model);
    model->setHeaderData(0,Qt::Horizontal,"日期");
    model->setHeaderData(1,Qt::Horizontal,"打卡情况");
    model->select();
}*/
void infortable::receivedata(QString str)
{
    i1=str;
     qDebug()<<"i1"<<i1;
    QString cmd("create table sfvgd");//数据表开头不能是数字
    cmd+=i1;
    QString s("(account varchar(20) primary key,name varchar(20),height int,weight int,sex varchar(5))");//不能使用QString类型
    cmd+=s;
    qDebug()<<"cmd"<<cmd;
  //  bool res= query.exec("drop table sccc");
    //qDebug()<<"7 drop"<<res;
  // bool  res= query.exec("drop table ccc");
      // qDebug()<<"7 drop"<<res;
    bool res=query.exec(cmd);
    qDebug()<<cmd<<res;
    QString cmd2(" insert into sfvgd");
    //qDebug()<<"i7"<<i7;
    cmd2+=i1;
    QString i2(" values('%1','妮妮',165,77,'女')");
     cmd2+=i2;
     qDebug()<<"cmd"<<cmd;
     QString i6=QString(cmd2).arg(i1);
     qDebug()<<"i6"<<i6;
      res= query.exec(i6);
     qDebug()<<"i6 insert"<<res;
   // QString i6=QString("insert into infor values('%1','妮妮',165,77,'女')").arg(i1);
    //bool res=query.exec(i6);
    if(res) {qDebug()<<"infor insert"<<res;}else{qDebug()<<"i1chushihuacharu"<<i1;}
    QString i3("sfvgd");
    i3+=i1;ix=i3;
    model->setTable(i3);//制定使用哪个表
    //把model放在view
    ui->tableView->setModel(model);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,"账户");
    model->setHeaderData(1,Qt::Horizontal,"昵称");
    model->setHeaderData(2,Qt::Horizontal,"身高");
    model->setHeaderData(3,Qt::Horizontal,"体重");
    model->setHeaderData(4,Qt::Horizontal,"性别");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    readonlydelegate *re=new readonlydelegate;
    ui->tableView->setItemDelegateForColumn(0,re);
}
void infortable::fresh()
{
    qDebug()<<"lalallalalalala";


        model->setTable(ix);//制定使用哪个表
        //把model放在view
        ui->tableView->setModel(model);
        model->select();
        model->setHeaderData(0,Qt::Horizontal,"账户");
        model->setHeaderData(1,Qt::Horizontal,"昵称");
        model->setHeaderData(2,Qt::Horizontal,"身高");
       model->setHeaderData(3,Qt::Horizontal,"体重");
        model->setHeaderData(4,Qt::Horizontal,"性别");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        readonlydelegate *re=new readonlydelegate;
        ui->tableView->setItemDelegateForColumn(0,re);
}


void infortable::closemy_infor()
{
    qDebug()<<"close";
    emit sendsignal();
    this->close();
}

infortable::~infortable()
{
    delete ui;
}



void infortable::on_pushButton_clicked()
{
    qDebug()<<"保存";
    model->submitAll();
}

void infortable::on_pushButton_2_clicked()
{
    qDebug()<<"取消操作";
    model->revertAll();
    model->submitAll();
}
