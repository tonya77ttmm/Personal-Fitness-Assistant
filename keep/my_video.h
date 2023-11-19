#ifndef MY_VIDEO_H
#define MY_VIDEO_H
#include <QWidget>
#include<mainwidget.h>
#include<QPushButton>
#include<QMediaPlayer>
#include<QRect>
#include<QDesktopWidget>
#include<QLabel>
#include<QAction>
#include<QMenu>
#include<QVideoWidget>
#include<videowidget.h>
#include<QListWidget>
class clock_in;
namespace Ui {
class my_video;
}

class my_video : public QWidget
{
    Q_OBJECT

public:
    explicit my_video(QWidget *parent = 0);
    ~my_video();
    void setButton();
    QString getNameFromPath(const QString &fileName);   //从路径中获取文件名!!!
   // QString removeIndexFromAppend( QString name);        //移除append序号
    void iniDatabase();                              //从数据库读数据到窗体!!!
    void updateToDataBase();                  //根据vector更新数据库!!!
    void addFile(const QString fileName);   //根据路径名添加文件!!1

private slots:



    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void closemy_video();
    void STOP();
    void slotOpenFile();
    void slotLastVideo();



signals:
    void sendsignal();
     void sendsignal2();
      void sendsignal3();


private:
    clock_in *ci;
   QPushButton* lastVideoButton;
    Ui::my_video *ui;
    QMediaPlayer *player;
    QPushButton *  menuButton2;

    const int windowIniWidth;    //窗口初始化的宽度
    const int windowIniHeight;   //窗口初始化的高度
    int playingIndex;           //当前正在播放视频的序号(从0开始)!!1
    QLabel *titleLabel;
    QMenu *menu;
     QMenu *menu2;
    QAction * openAction ;
    QAction * openAction2 ;
    QRect normalRect;
    QWidget *groupBox;//wigetvideo在此上面
    QLabel * mainLabel ;//暂定窗口
   //播放器控件
     VideoWidget *videoWidget0;
     QMediaPlayer  *  mediaPlayer0;     //播放者
      QPushButton * playButton;

      QListWidget * listWidget;

      //显示列表控件!!11
      //用来保存文件目录 文件名
      QVector<QPair<QPair<QString, QString>, QString > > vector;   //name  fileName  nameAppendIndex！

};
#endif // MY_VIDEO_H


