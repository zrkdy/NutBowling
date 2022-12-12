#include "footballzombie.h"

FootballZombie::FootballZombie()
{
    hp = 3;
    atk = 100 * 33 / 1000;
    speed = 1.3*80.0 * 33 / 1000 / 2.5;
    setMovie("://pvz图片/FootballZombieWalk.gif");
}

void FootballZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie("://pvz图片/FootballZombieDie.gif");
            setHead("://pvz图片/ZombieHead.gif");

        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }

    if (state)
    {
        state = 0;
        setMovie("://pvz图片/FootballZombieWalk.gif");
    }
    setX(x() - speed);
}
