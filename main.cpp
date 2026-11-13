
#include "Player.h"
#include "Enemy.h"

#include <iostream>
#include <string>

#include "Warrior.h"
#include "Mage.h"

using namespace std;

// ========================================
// CREATE ENEMY FOR EACH LEVEL
// ========================================

Enemy createEnemy(int level) {

    switch (level) {

        case 1:
            return Enemy("Shadow Goblin", 80, 15, 75, 50, false);

        case 2:
            return Enemy("Cyber Wolf", 110, 20, 100, 75, false);

        case 3:
            return Enemy("Dark Knight", 140, 25, 150, 100, false);

        case 4:
            return Enemy("Cyber Assassin", 180, 30, 200, 150, false);

        case 5:
            return Enemy("CYBER LORD", 350, 40, 500, 500, true);
    }

    return Enemy("Unknown Enemy", 50, 10, 0, 0);
}

// ========================================
// DISPLAY LEVEL INFORMATION
// ========================================

void displayLevel(int level) {

    cout << "\n================================\n";
    cout << "           LEVEL " << level << "\n";
    cout << "================================\n";

    if (level == 5) {
        cout << "FINAL BOSS: CYBER LORD\n";
    }
    else {
        cout << "Mission: Defeat the enemy!\n";
    }
}

// ========================================
// MAIN FUNCTION
// ========================================

int main() {

    int choice;
    string playerName;

    cout << "================================\n";
    cout << "          CYBER QUEST\n";
    cout << "================================\n";

    cout << "Enter your character name: ";
    cin >> playerName;

    cout << "\nSelect your character:\n";
    cout << "1. Warrior\n";
    cout << "2. Mage\n";
    cout << "Enter choice: ";
    cin >> choice;

   Player* player = nullptr;

if (choice == 1) {
    player = new Warrior(playerName);
    cout << "\nYou selected Warrior!" << endl;
}
else if (choice == 2) {
    player = new Mage(playerName);
    cout << "\nYou selected Mage!" << endl;
}
else {
    cout << "Invalid choice!" << endl;
    return 0;
}

    // ========================================
    // LEVEL PROGRESSION LOOP
    // ========================================

    const int finalLevel = 5;
    bool escaped = false;

    for (int level = 1; level <= finalLevel; level++) {

        displayLevel(level);

        // Create a new enemy for this level
        Enemy enemy = createEnemy(level);

        cout << "\nEnemy appeared!\n";
        enemy.displayStatus();

        // ====================================
        // BATTLE LOOP
        // ====================================

        while (player->isAlive() && enemy.isAlive()) {

            cout << "\n----------------------------\n";
            cout << "PLAYER STATUS\n";
            player->displayPlayerStatus();

            cout << "\nENEMY STATUS\n";
            enemy.displayStatus();

            cout << "\n1. Attack\n";
            cout << "2. Defend\n";
            cout << "3. Use Health Potion\n";
            cout << "4. View Inventory\n";
            cout << "5. Run Away\n";
            cout << "6. Special Ability\n";

            cout << "\nChoose your action: ";
            cin >> choice;

            bool defending = false;
            bool actionCompleted = false;

            // PLAYER ATTACK
            if (choice == 1) {

                player->attack();

                int damage = player->getAttackDamage();

                enemy.takeDamage(damage);

                cout << "\nYou dealt "
                     << damage << " damage!\n";

                actionCompleted = true;
            }

            // DEFEND
            else if (choice == 2) {

                cout << "\nYou are defending!\n";

                defending = true;
                actionCompleted = true;
            }

            // USE POTION
            else if (choice == 3) {

                actionCompleted = player->usePotion();
            }

            // INVENTORY
            else if (choice == 4) {

                player->displayInventory();

                // Viewing inventory does not use a turn
            }

            // RUN AWAY
            else if (choice == 5) {

                cout << "\nYou escaped from the mission!\n";

                escaped = true;
                break;
            }

            // SPECIAL ABILITY
            else if (choice == 6) {

                if (player->getSpecialCooldown() > 0) {
                    player->specialAbility();
                }
                else {
                    player->specialAbility();
                    int damage = player->getSpecialDamage();
                    enemy.takeDamage(damage);

                    cout << "\nSpecial attack dealt "
                         << damage << " damage!\n";

                    actionCompleted = true;
                }
            }

            else {

                cout << "\nInvalid choice!\n";
            }

            // CHECK IF ENEMY IS DEFEATED
            if (!enemy.isAlive()) {

                cout << "\n============================\n";
                cout << "       ENEMY DEFEATED!\n";
                cout << "============================\n";

                break;
            }

            // ENEMY TURN
            if (actionCompleted && enemy.isAlive()) {

                cout << "\n--- ENEMY TURN ---\n";

                enemy.attack();

                int damage = enemy.getDamage();

                if (defending) {
                    damage /= 2;
                    cout << "Defense reduced the damage!\n";
                }

                player->takeDamage(damage);

                player->reduceCooldown();

                cout << "\nEnemy dealt "
                     << damage << " damage!\n";

                cout << "Your HP: "
                     << player->getHealth()
                     << "/" << player->getMaxHealth()
                     << "\n";

                if (!player->isAlive()) {

                    cout << "\n========== GAME OVER ==========\n";
                    break;
                }
            }
        }

        // ====================================
        // CHECK GAME STATUS
        // ====================================

        if (escaped || !player->isAlive()) {
            break;
        }

        // ====================================
        // REWARDS AFTER VICTORY
        // ====================================

        player->gainExperience(enemy.getXPReward());
        player->addCoins(enemy.getCoinReward());

        // ====================================
        // FINAL BOSS DEFEATED
        // ====================================

        if (level == finalLevel) {

            cout << "\n================================\n";
            cout << "     CYBER QUEST COMPLETED!\n";
            cout << "================================\n";

            cout << "Congratulations, "
                 << player->getName() << "!\n";

            cout << "You defeated the Cyber Lord!\n";

            break;
        }

        // ====================================
        // UNLOCK NEXT LEVEL
        // ====================================

        cout << "\n********************************\n";
        cout << "      LEVEL " << level + 1
             << " UNLOCKED!\n";
        cout << "********************************\n";

        cout << "Preparing the next battle...\n";
    }

    // ========================================
    // FINAL PLAYER STATUS
    // ========================================

    cout << "\n================================\n";
    cout << "          FINAL STATUS\n";
    cout << "================================\n";

    player->displayPlayerStatus();

    delete player;

    return 0;
}