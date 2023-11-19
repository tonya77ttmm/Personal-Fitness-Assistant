#include "videowidget.h"

VideoWidget::VideoWidget(QWidget *parent) : QVideoWidget(parent),windowIniHeight(600), windowIniWidth(800)/* PADDING(2), buttonHeight(20),buttonWidth(20), */
{
    this->setMouseTracking(true);
    this->setCursor(QCursor(Qt::ArrowCursor));
    this->setAutoFillBackground(true);
    this->setStyleSheet("QVideoWidget{background-color:rgb(0,0,0);}");
    //setWindowOpacity(1);//设置透明度
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint); // 设置成无边框对话框
    this->setMouseTracking(true);
    this->setFocusPolicy(Qt::ClickFocus);
    this->setAcceptDrops(true);    //设置可以接受拖拽
}
