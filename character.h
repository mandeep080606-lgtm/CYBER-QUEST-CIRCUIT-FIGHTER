
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    string name;
    int health;
    int maxHealth;

public:
    Character(string n, int h);

    virtual void attack() = 0;

    void displayStatus();
    void takeDamage(int damage);
    bool isAlive();

    int getHealth();
    int getMaxHealth();
    string getName();

    void heal(int amount);

    virtual ~Character() = default;
};

#endif