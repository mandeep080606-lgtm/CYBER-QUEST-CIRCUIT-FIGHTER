#include "Player.h"

// Constructor
Player::Player(string n, int h, int damage, string className)
    : Character(n, h) {

    level = 1;
    experience = 0;
    experienceToNextLevel = 100;
    potions = 3;
    coins = 0;
    attackDamage = damage;
    specialCooldown = 0;
    characterClass = className;
}


// Normal Attack
void Player::attack() {

    cout << "\n" << name << " attacks!" << endl;

    cout << "Damage: "
         << attackDamage
         << endl;
}


// Special Ability
void Player::specialAbility() {

    if (specialCooldown > 0) {

        cout << "\nSpecial ability is on cooldown!" << endl;

        cout << "Cooldown: "
             << specialCooldown
             << " turn(s)"
             << endl;

        return;
    }


    cout << "\n============================" << endl;
    cout << "       SPECIAL ABILITY" << endl;
    cout << "============================" << endl;


    if (characterClass == "Warrior") {

        cout << name
             << " uses POWER STRIKE!"
             << endl;

        cout << "Special Damage: "
             << attackDamage * 2
             << endl;
    }

    else if (characterClass == "Mage") {

        cout << name
             << " casts FIREBALL!"
             << endl;

        cout << "Special Damage: "
             << attackDamage * 2 + 10
             << endl;
    }

    else {

        cout << name
             << " uses a special ability!"
             << endl;

        cout << "Special Damage: "
             << attackDamage * 2
             << endl;
    }


    // Set cooldown
    specialCooldown = 3;
}


// Reduce Special Ability Cooldown
void Player::reduceCooldown() {

    if (specialCooldown > 0) {

        specialCooldown--;
    }
}


// Use Health Potion
bool Player::usePotion() {

    if (potions <= 0) {

        cout << "\nYou don't have any health potions!"
             << endl;

           return false;
    }


    if (health == maxHealth) {

        cout << "\nYour health is already full!"
             << endl;

           return false;
    }


    int healAmount = 40;

    health += healAmount;


    // Prevent health from going above maximum
    if (health > maxHealth) {

        health = maxHealth;
    }


    potions--;


    cout << "\nYou used a health potion!"
         << endl;

    cout << "Recovered health: "
         << healAmount
         << endl;

    cout << "Current HP: "
         << health
         << "/"
         << maxHealth
         << endl;

    return true;
}


// Add Potions
void Player::addPotion(int amount) {

    potions += amount;

    cout << "\nYou received "
         << amount
         << " health potion(s)!"
         << endl;
}


// Add Coins
void Player::addCoins(int amount) {

    coins += amount;

    cout << "\nYou received "
         << amount
         << " coins!"
         << endl;
}
void Player::gainExperience(int amount) {

    experience += amount;

    cout << "\nYou gained "
         << amount
         << " XP!"
         << endl;

    while (experience >= experienceToNextLevel) {

        experience -= experienceToNextLevel;

        levelUp();
    }
}


// Get Special Damage
int Player::getSpecialDamage() {

    if (characterClass == "Warrior") {

        return attackDamage * 2;
    }

    else if (characterClass == "Mage") {

        return attackDamage * 2 + 10;
    }

    else {

        return attackDamage * 2;
    }
}


// Reset Special Cooldown
void Player::resetSpecialCooldown() {

    specialCooldown = 0;
}


// Level Up
void Player::levelUp() {

    level++;

    experienceToNextLevel += 50;

    maxHealth += 20;

    health = maxHealth;

    attackDamage += 5;


    cout << "\n============================" << endl;
    cout << "          LEVEL UP!" << endl;
    cout << "============================" << endl;


    cout << "You reached Level "
         << level
         << "!"
         << endl;


    cout << "Max Health increased!"
         << endl;

    cout << "Attack Damage increased!"
         << endl;


    cout << "New Max HP: "
         << maxHealth
         << endl;

    cout << "New Attack Damage: "
         << attackDamage
         << endl;
}


// Display Player Status
void Player::displayPlayerStatus() {

    cout << "\n============================" << endl;
    cout << "       PLAYER STATUS" << endl;
    cout << "============================" << endl;


    cout << "Name: "
         << name
         << endl;


    cout << "Class: "
         << characterClass
         << endl;


    cout << "Level: "
         << level
         << endl;


    cout << "HP: "
         << health
         << "/"
         << maxHealth
         << endl;


    cout << "XP: "
         << experience
         << "/"
         << experienceToNextLevel
         << endl;


    cout << "Attack Damage: "
         << attackDamage
         << endl;


    cout << "Special Cooldown: "
         << specialCooldown
         << endl;


    cout << "Coins: "
         << coins
         << endl;


    cout << "Potions: "
         << potions
         << endl;
}


// Display Inventory
void Player::displayInventory() {

    cout << "\n============================" << endl;
    cout << "          INVENTORY" << endl;
    cout << "============================" << endl;


    cout << "Health Potions: "
         << potions
         << endl;


    cout << "Coins: "
         << coins
         << endl;
}


// Get Attack Damage
int Player::getAttackDamage() {

    return attackDamage;
}


// Get Level
int Player::getLevel() {

    return level;
}


// Get XP
int Player::getXP() {

    return experience;
}


// Get Potions
int Player::getPotions() {

    return potions;
}


// Get Coins
int Player::getCoins() {

    return coins;
}


// Get Special Cooldown
int Player::getSpecialCooldown() {

    return specialCooldown;
}


// Get Character Class
string Player::getCharacterClass() {

    return characterClass;
}