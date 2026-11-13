#include "Mage.h"

Mage::Mage(string name)
    : Player(name, 100, 40, "Mage") {
}

void Mage::attack() {
    cout << "\nMage casts a magic attack!" << endl;
    cout << "Damage: " << getAttackDamage() << endl;
}

void Mage::specialAbility() {
    Player::specialAbility();
}