#include "screenzombie.h"

ScreenZombie::ScreenZombie()
{
    hp = 999999;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setMovie("://pvz图片/ScreenZombieWalk.gif");
}

void ScreenZombie::advance(int phase)
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
        setMovie("://pvz图片/ScreenZombieWalk.gif");
    }
    setX(x() - speed);
}
