
#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>
using namespace std;

class Enemy {
private:
    string name;
    int health;
    int maxHealth;
    int damage;
    int xpReward;
    int coinReward;
    bool boss;

public:
    // Default constructor
    Enemy();

    // Parameterized constructor
    Enemy(string n, int h, int d, int xp, int coins, bool isBoss = false);

    // Member functions
    void attack();
    void takeDamage(int amount);
    void displayStatus();
    bool isAlive();

    // Getter functions
    int getDamage();
    int getXPReward();
    int getCoinReward();
    string getName();
    bool isBossEnemy();
};

#endif