#include "nutwall.h"
int mmp=0;
NutWall::NutWall()
{
    mmp++;
    movie=nullptr;
    speed=1.2*1.3*1.6*1.5*3*80.0 * 33 / 1000 / 4;
    y_speed=0;
    y_initial=y();
    setMovie(":/pvz图片/nutwall1.gif");
}

NutWall::~NutWall()
{
    delete movie;

}

QRectF NutWall::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void NutWall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image = movie->currentImage();
    painter->drawImage(QRectF(-70, -100, 90, 90), image);
}

bool NutWall::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qAbs(other->y()+30-y())<50 && qAbs(other->x() - x()) < 20;
}

void NutWall::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}

void NutWall::advance(int phase)
{
    if (!phase)
        return;
    update();
    int flag5=1;
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.empty())
    {
        //flag = true;
        foreach (QGraphicsItem *item, items)
        {

            Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
            for(int i=0;i<zombie->a.size();i++){
                if(zombie->a[i]==mmp-1){
                    flag5=0;
                }
            }
            if(flag5){
                zombie->a.push_back(mmp-1);
                zombie->hp--;
             }

        }
            if(flag5){
                if(y_speed>0){
                    y_speed=-4;
                }
                else if(y()!=190+98*4){
                    y_speed=4;
                }
                else{
                    y_speed=-4;
                }
            }



        /*if(y_speed>=0){
            y_speed=-2;
        }
        else if(y_speed<0){
            y_speed=2;
        }*/

    }

        if(y()>190+98*4){
            if(y_speed==4) y_speed=-4;
            else y_speed=4;
        }
        else if(y()<160){
            y_speed=4;
        }
        setY(y()+y_speed);
        setX(x() + speed);

    if (x() > 1100)
        delete this;
}
