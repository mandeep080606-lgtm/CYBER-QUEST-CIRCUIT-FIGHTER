#include "Character.h"

Character::Character(string n, int h) {
    name = n;
    health = h;
    maxHealth = h;
}

void Character::displayStatus() {
    cout << "Name: " << name << endl;
    cout << "Health: " << health
         << "/" << maxHealth << endl;
}

void Character::takeDamage(int damage) {
    health -= damage;

    if (health < 0) {
        health = 0;
    }
}

bool Character::isAlive() {
    return health > 0;
}

int Character::getHealth() {
    return health;
}

int Character::getMaxHealth() {
    return maxHealth;
}

string Character::getName() {
    return name;
}

void Character::heal(int amount) {
    health += amount;

    if (health > maxHealth) {
        health = maxHealth;
    }
}