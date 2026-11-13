
#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
private:
    int level;
    int experience;
    int experienceToNextLevel;

    int potions;
    int coins;

    int attackDamage;
    int specialCooldown;

    string characterClass;

public:
    Player(string n, int h, int damage, string className);

    void attack() override;

    bool usePotion();

    // Special ability (declared only once)
    virtual void specialAbility();

    void reduceCooldown();

    void addPotion(int amount);
    void addCoins(int amount);
    void gainExperience(int amount);

    void displayPlayerStatus();
    void displayInventory();

    int getAttackDamage();
    int getLevel();
    int getXP();
    int getPotions();
    int getCoins();
    int getSpecialCooldown();
    int getSpecialDamage();
    void resetSpecialCooldown();
    string getCharacterClass();

private:
    void levelUp();
};

#endif