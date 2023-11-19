#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include<QVideoWidget>

class VideoWidget :  public QVideoWidget
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    const int windowIniWidth;
    const int windowIniHeight;
};

#endif // VIDEOWIDGET_H
