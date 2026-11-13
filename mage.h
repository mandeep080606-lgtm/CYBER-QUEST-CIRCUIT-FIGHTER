#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

class Mage : public Player {
public:
    Mage(string name);

    void attack() override;
    void specialAbility() override;
};

#endif