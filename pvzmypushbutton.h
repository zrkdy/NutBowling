#ifndef PVZMYPUSHBUTTON_H
#define PVZMYPUSHBUTTON_H

#include <QPushButton>
class pvzMyPushButton:public QPushButton
{
    Q_OBJECT
public:
    pvzMyPushButton(QString normalImg);
    QString normalImgPath;
    //弹跳特效
    void pop1(); //向下跳
    void pop2(); //向上跳
signals:

public slots:
};

#endif // PVZMYPUSHBUTTON_H
