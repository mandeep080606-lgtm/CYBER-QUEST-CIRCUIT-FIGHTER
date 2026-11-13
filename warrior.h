#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"

class Warrior : public Player {
public:
    Warrior(string name);

    void attack() override;
    void specialAbility() override;
};

#endif