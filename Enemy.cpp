#include "Enemy.h"

Enemy::Enemy() {

    name = "Unknown";
    health = 0;
    maxHealth = 0;
    damage = 0;
    xpReward = 0;
    coinReward = 0;
    boss = false;
}
Enemy::Enemy(string n, int h, int d, int xp, int coins, bool isBoss) {

    name = n;
    health = h;
    maxHealth = h;
    damage = d;
    xpReward = xp;
    coinReward = coins;
    boss = isBoss;
}

void Enemy::attack() {

    cout << name << " attacks!" << endl;

    cout << "Damage: "
         << damage << endl;
}

void Enemy::takeDamage(int amount) {

    health -= amount;

    if (health < 0) {
        health = 0;
    }
}

void Enemy::displayStatus() {

    cout << name
         << " HP: "
         << health
         << "/"
         << maxHealth;

    if (boss) {
        cout << " [BOSS]";
    }

    cout << endl;
}

bool Enemy::isAlive() {

    return health > 0;
}

int Enemy::getDamage() {

    return damage;
}

int Enemy::getXPReward() {

    return xpReward;
}

int Enemy::getCoinReward() {

    return coinReward;
}

string Enemy::getName() {

    return name;
}

bool Enemy::isBossEnemy() {

    return boss;
}