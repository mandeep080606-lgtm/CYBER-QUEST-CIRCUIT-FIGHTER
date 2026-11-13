#include "Warrior.h"

Warrior::Warrior(string name)
    : Player(name, 150, 30, "Warrior") {
}

void Warrior::attack() {
    cout << "\nWarrior attacks with a sword!" << endl;
    cout << "Damage: " << getAttackDamage() << endl;
}

void Warrior::specialAbility() {
    Player::specialAbility();
}