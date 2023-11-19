#include "my_video.h"
#include "ui_my_video.h"
#include<QAudioFormat>
#include<QAudioDeviceInfo>
#include<QAudioInput>
#include<QAudioOutput>
#include<QTimer>
#include<QDebug>
#include<QRect>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QSqlError>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QFileDialog>
#include<QDir>
#include<clock_in.h>
//#include<my_pushbotton.h>


my_video::my_video(QWidget *parent) : windowIniWidth((QApplication::desktop()->availableGeometry().width())*29/48),
    playingIndex(-1), windowIniHeight((QApplication::desktop()->availableGeometry().height())*20/27),
    QWidget(parent),
    ui(new Ui::my_video)
{
    ui->setupUi(this);
    player=new QMediaPlayer;
    ci=new clock_in;
    connect(this,SIGNAL(sendsignal2()),ci,SLOT(pbpaly()));
    connect(this,SIGNAL(sendsignal3()),ci,SLOT(pbstop()));
    this->setAutoFillBackground(true);
    this->setStyleSheet("QWidget{background-color:rgb(60,65,68);}");
    setWindowOpacity(1);//设置透明度
    this->setMinimumHeight(700);
    this->setMinimumWidth(920);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint); // 设置成无边框对话框|
    this->setMouseTracking(true);
    this->setFocusPolicy(Qt::ClickFocus);
//按钮样式

    menuButton2 = new QPushButton(this);
    menuButton2->setGeometry(44,8,70,34);
    //menuButton2->setGeometry(34,0,70,34);
    menuButton2->setText("QPlay");
    menuButton2->setStyleSheet("QPushButton{border:none; color:rgb(224,224,224); font-size:21px; font-family: Comic Sans MS; }");
    connect(menuButton2,&QPushButton::clicked,[=](){qDebug()<<"xixixi";});
    ui->pushButton_3->setStyleSheet("QPushButton{border:none; color:rgb(224,224,224); font-size:21px; font-family: Comic Sans MS; }");
    ui->pushButton_3->setText("Play");
    ui->pushButton_2->setStyleSheet("QPushButton{border:none; color:rgb(224,224,224); font-size:21px; font-family: Comic Sans MS; }");
    ui->pushButton_2->setText("Pause");
    //上一曲按钮,出了bug没有用，应该是append函数和那几个index的事暂时不处理
    lastVideoButton =  new QPushButton(this);
    lastVideoButton->setGeometry(858,540, 60, 60);
    lastVideoButton->setText("QLast");
    lastVideoButton->setStyleSheet("QPushButton{border:none; color:rgb(224,224,224); font-size:21px; font-family: Comic Sans MS; }");
    connect(lastVideoButton, SIGNAL(clicked(bool)), this, SLOT(slotLastVideo()));

   //文件名字  未知原因暂未显示
    titleLabel = new QLabel(this);
    titleLabel->setGeometry(130,10,500,30);
    titleLabel->setStyleSheet("QLabel{color:rgb(200,200,200); background-color:rgb(60, 65, 68)}");
    //菜单
    menu = new QMenu;
    openAction = menu->addAction("打开");
    menu->setStyleSheet(" QMenu{border:none } "
                        "QMenu::item{border:none; font-size:13px;  padding-left:20px; background-color:white; height:25px; width:50px; }"
                         "QMenu::item:selected{ background-color:rgb(140,140,240)}");


    connect(openAction, SIGNAL(triggered(bool)), this, SLOT(slotOpenFile()));
//添加第二个子菜单 同一个Qmenu，不同的QAction
    openAction2 = menu->addAction("关闭");
    menu->setStyleSheet(" QMenu{border:none } "
                        "QMenu::item{border:none; font-size:13px;  padding-left:20px; background-color:white; height:25px; width:50px; }"
                         "QMenu::item:selected{ background-color:rgb(140,140,240)}");


    connect(openAction2, SIGNAL(triggered(bool)), this, SLOT(closemy_video()));
    menuButton2->setMenu(menu);
   //---------子菜单设置完成---------//
   groupBox = new QWidget(this);
    groupBox->setGeometry(0,50,normalRect.width()-200, normalRect.height()-49);
    groupBox->setStyleSheet("QWidget{ border-top-left-radius:0px;  border-top-right-radius:0px;  background-color:red}");
    groupBox->setMouseTracking(true);
//暂停窗口
   /* mainLabel = new QLabel(groupBox);
    mainLabel->setStyleSheet("background-color:rgb(0,0,0)");
    mainLabel->setGeometry(2,0,groupBox->size().width(), groupBox->size().height());
    mainLabel->hide();*/
    //播放列表!!1
    listWidget = new QListWidget(this);
    listWidget->installEventFilter(this);
    listWidget->setGeometry(normalRect.width()-201, 50, 200, normalRect.height()-49);

    //播放窗口
   videoWidget0 = new VideoWidget(this);
   videoWidget0->setGeometry(50,50,800,600);
   //播放按钮
    playButton = new QPushButton(this);
    playButton->setGeometry(870, 680, 50, 50);
    playButton->setText("Stop");
    playButton->setStyleSheet("QPushButton{ border-radius:25px; background-color: rgb(40,40,40)");
    connect(playButton, SIGNAL(clicked()), this, SLOT(STOP()));
//播放器
    mediaPlayer0 = new QMediaPlayer;
    mediaPlayer0->setVideoOutput(videoWidget0);
   mediaPlayer0->setMedia(QMediaContent(QUrl::fromLocalFile("D:/QT/PRO/build-keep-Desktop_Qt_5_9_0_MinGW_32bit-Debug/debug/5.mp4")));
   //f(!res) {qDebug()<<"加载视频失败";} //mediaPlayer0->play();
}
void my_video::slotLastVideo()
{
    if(!vector.isEmpty())
    {
        //int currentIndex=playList->currentIndex();
        if(--playingIndex <= -1)
            playingIndex=vector.size()-1;
      //  playList->setCurrentIndex(currentIndex);
        // void setIndex(int n){indexInPlayList = n;}
        //listWidget->setIndex(playingIndex);
        mediaPlayer0 ->setMedia(QUrl::fromLocalFile(vector.at(playingIndex).first.second));
        mediaPlayer0->play();
        listWidget->setCurrentRow(playingIndex);
    }
}



//使用数据库的数据初始化
void my_video::iniDatabase()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("media.db");
    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),db.lastError().text());
    }
    else
    {
        QSqlQuery query;
        if(!query.exec("CREATE TABLE mediatable(ind VARCHAR(777), name VARCHAR(777), fileName VARCHAR(777), nameAppend VARCHAR(777))"))
        {
            qDebug()<<query.lastError().text();
        }
        /*if(!query.exec("CREATE TABLE setting(volume VARCHAR(777), playMode VARCHAR(777))"))
        {
            qDebug()<<query.lastError().text();
        }*/

        QSqlTableModel settingModel;
        settingModel.setTable("setting");
        settingModel.select();
        QSqlRecord record=settingModel.record(0);

       // volumeSlider->setValue(record.value(0).toInt());
        //playModeListWidget->setCurrentRow(record.value(1).toInt());

        QSqlTableModel mediaTableModel;
        mediaTableModel.setTable("mediatable");
        mediaTableModel.select();
        int ret = mediaTableModel.rowCount();
        for(int i=0; i<ret;i++)
        {
            QSqlRecord record=mediaTableModel.record(i);
            QString name=record.value(1).toString();
            QString fileName = record.value(2).toString();
            QString nameAppend = record.value(3).toString();
            QPair<QString, QString> pair1(name, fileName);
            QPair<QPair<QString, QString>, QString>pair(pair1,nameAppend);
            vector.push_back(pair);
            //playList->addMedia(QUrl::fromLocalFile(fileName));
            //listWidget->addItem(removeIndexFromAppend(nameAppend));

            if(vector.isEmpty())
                playButton->setEnabled(false);
            else
                playButton->setEnabled(true);
        }
        //qDebug()<<"inidatabase finished";
    }

}

//从路径中得到文件名字
QString my_video::getNameFromPath(const QString &fileName)
{
    QString name;
    QChar c;
    QString s = fileName.toUtf8().data();
    foreach(c, s)
    {
        if(c =='/')
        {
            name.clear();
            continue;
        }
        name.append(c);
    }
    //name = name.toUtf8().data();     //解决name中文乱码问题
    return name;
}
void my_video::addFile(const QString fileName)
{
    if(!fileName.isEmpty())
    {
        QString name = getNameFromPath(fileName);   //从路径中获取文件名字
        //titleLabel->setText(name);
        int i;
        for(i=0;i<vector.size();i++)
        {
            if(vector.at(i).first.second == fileName)   //该文件已经存在
            {
                playingIndex=i;
                mediaPlayer0 ->setMedia(QUrl::fromLocalFile(fileName));//添加播放文件
                mediaPlayer0->play();
                listWidget->setCurrentRow(i);
                //listWidget->setIndex(i);
                //titleLabel->setText(removeIndexFromAppend(vector.at(i).second));//？有问题
                break;
            }
        }
            //说明没有和name一样的，则直接插入，一下播放列表功能没实现

                QPair<QString, QString>pairFirst(name, fileName);
                QString nameAppend = name+"(0)";
                QPair<QPair<QString, QString>, QString> pair(pairFirst, nameAppend);
                vector.push_back(pair);

                QSqlTableModel mediaTableModel;
                mediaTableModel.setTable("mediatable");
                mediaTableModel.select();

                QSqlRecord record = mediaTableModel.record();
                QString index=QString::number(vector.size()-1);
                 record.setValue(0,index);
                 record.setValue(1,name);
                 record.setValue(2, fileName);
                 record.setValue(3, nameAppend);
                 mediaTableModel.insertRecord(-1,record);
                 mediaTableModel.submitAll();

                QListWidgetItem * item = new QListWidgetItem(name);

                titleLabel->setText(name);
                listWidget->addItem(item);

            if(!playButton->isEnabled())
            {
                playButton->setEnabled(true);
            }
            mediaPlayer0 ->setMedia(QUrl::fromLocalFile(fileName));
            mediaPlayer0->play();
            playingIndex = vector.size()-1;
            //volumeSlider->setValue(mediaPlayer0->volume()); //修改声音滑动条
            listWidget->setCurrentRow(playingIndex);//？？？
            //listWidget->setIndex(playingIndex);//？？？
}

}
void my_video::slotOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "open file", QDir::currentPath());
    //QString fileName = QFileDialog::getOpenFileName(this, "open file", QString("D:\迅雷下载"));
    addFile(fileName);
 }
void my_video::STOP()
{
    mediaPlayer0->stop();
     emit sendsignal3();
}
//关闭页面
void my_video::closemy_video()
{
    emit sendsignal();
    this->hide();
}
my_video::~my_video()
{
    delete ui;
    //delete mw;
}

/*void my_video::on_pushButton_clicked()
{

     emit sendsignal();
     this->close();

}*/

void my_video::on_pushButton_3_clicked()
{
     mediaPlayer0->play();
      emit sendsignal2();
}

void my_video::on_pushButton_2_clicked()
{
    mediaPlayer0->pause();
      emit sendsignal3();
}



