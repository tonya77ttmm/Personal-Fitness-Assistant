#include "dialog.h"
#include <QApplication>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db2=QSqlDatabase::addDatabase("QSQLITE");
    db2.setDatabaseName("mydbv.db");
    if(!db2.open())
    {
        qDebug()<<"数据库打开失败";
    }
    else
    {
        qDebug()<<"数据库打开成功";
    }
   //QSqlQuery query;
   //query.exec("select count(1) from sqlite_master where type='table'");


    Dialog w;
    w.show();


    return a.exec();
}
