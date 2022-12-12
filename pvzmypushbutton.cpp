#include "pvzmypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
pvzMyPushButton::pvzMyPushButton(QString normalImg)
{
    this->normalImgPath=normalImg;
    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret){
        qDebug()<<"Failed";
        return;
    }
    this->setFixedSize(160,35);
    this->setIcon(pix);
    this->setIconSize(QSize(210,130));
}
 void pvzMyPushButton:: pop1(){
     QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
     animation->setDuration(200);
     animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
     animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
     animation->setEasingCurve(QEasingCurve::OutBounce);
     animation->start();
 }
 void pvzMyPushButton:: pop2(){
     QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
     animation->setDuration(200);
     animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
     animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
     animation->setEasingCurve(QEasingCurve::OutBounce);
     animation->start();
}
