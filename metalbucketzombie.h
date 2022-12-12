#ifndef METALBUCKETZOMBIE_H
#define METALBUCKETZOMBIE_H

#include "zombie.h"

class MetalBucketZombie : public Zombie
{
public:
    MetalBucketZombie();
    void advance(int phase) override;
};

#endif // METALBUCKETZOMBIE_H
