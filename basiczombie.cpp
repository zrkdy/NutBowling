#include "basiczombie.h"

BasicZombie::BasicZombie()
{
    hp = 1;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    if (qrand() % 2)
       setMovie("://pvz图片/ZombieWalk1.gif");
     //setMovie("://pvz图片/nutnut.gif");
    else
        setMovie("://pvz图片/ZombieWalk2.gif");
}

void BasicZombie::advance(int phase)
{
    if (!phase)
        return;
    update();

    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie("://pvz图片/ZombieDie.gif");
            setHead("://pvz图片/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }

    if (state)
    {
        state = 0;
        if (qrand() % 2)
            setMovie("://pvz图片/ZombieWalk1.gif");
        else
            setMovie("://pvz图片/ZombieWalk2.gif");
    }
    setX(x() - speed);
}
