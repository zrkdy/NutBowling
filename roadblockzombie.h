#ifndef ROADBLOCKZOMBIE_H
#define ROADBLOCKZOMBIE_H
#include "zombie.h"

class RoadBlockZombie : public Zombie
{
public:
    RoadBlockZombie();
    void advance(int phase) override;
};

#endif // ROADBLOCKZOMBIE_H
