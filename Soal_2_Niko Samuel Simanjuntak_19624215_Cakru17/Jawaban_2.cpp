#include <bits/stdc++.h>
using namespace std;

// Class Robot
class Robot {
public:
    string name;
    int health, attack_power;

    Robot(string n, int h, int ap) : name(n), health(h), attack_power(ap) {}

    // Metode untuk menyerang robot lawan
    void attack(Robot &opponent) {
        int damage = rand() % attack_power + 1;
        opponent.health -= damage;
        cout << endl;
        cout << name << " attacks " << opponent.name << " for " << damage << " damage!" << endl;
        cout << opponent.name << "'s Health: " << opponent.health << endl;
    }

    // Metode untuk memeriksa apakah robot sudah dikalahkan
    bool isDefeated() {
        return health <= 0;
    }
};

// Class Battle
class Battle {
private:
    Robot &robot1;
    Robot &robot2;

public:
    Battle(Robot &r1, Robot &r2) : robot1(r1), robot2(r2) {}

    // Metode untuk memulai pertarungan antara dua robot
    void start_fight() {
        cout << "Battle Start!" << endl;
        while (robot1.health > 0 && robot2.health > 0) {
            // Robot 1 menyerang Robot 2
            if (!robot1.isDefeated()) {
                robot1.attack(robot2);
            }
            if (robot2.isDefeated()) {
                cout << endl;
                cout << robot2.name << " is defeated!" << endl;
                cout << robot1.name << " wins!" << endl;
                break;
            }

            // Robot 2 menyerang Robot 1
            if (!robot2.isDefeated()) {
                robot2.attack(robot1);
            }
            if (robot1.isDefeated()) {
                cout << endl;
                cout << robot1.name << " is defeated!" << endl;
                cout << robot2.name << " wins!" << endl;
                break;
            }
        }
    }
};

// Class Game
class Game {
private:
    vector<Robot> robots;

public:
    // Metode untuk menambahkan robot ke dalam game
    void add_robot(Robot robot) {
        robots.push_back(robot);
    }

    // Metode untuk memulai game dan memilih robot untuk bertarung
    void start_game() {
        if (robots.size() < 2) {
            cout << "Not enough robots for a battle. Add more robots! (At least need 2 robots)" << endl;
            return;
        }

        cout << "Choose robots for the battle:" << endl;
        for (int i = 0; i < robots.size(); i++) {
            cout << i + 1 << ". " << robots[i].name << endl;
            cout << "   (Health: " << robots[i].health << ") (Max Attack Power: " << robots[i].attack_power << ")" << endl;
        }
        cout << endl;

        int robot1Index, robot2Index;
        cout << "Select the first robot: ";
        cin >> robot1Index;
        cout << "Select the second robot: ";
        cin >> robot2Index;
        cout << endl;

        // Konversi input pengguna ke indeks (0-based)
        Robot &robot1 = robots[robot1Index - 1];
        Robot &robot2 = robots[robot2Index - 1];

        Battle battle(robot1, robot2);
        battle.start_fight();
    }
};

// Main function
int main() {
    // Seed untuk menghasilkan angka acak
    // akan digunakan untuk menentukan besar serangan yang diberikan setiap robot
    srand(time(0));

    // Membuat instance game
    Game game;

    // Menambahkan robot ke dalam game
    game.add_robot(Robot("RoboOne", 100, 90));
    game.add_robot(Robot("RoboTwo", 200, 45));
    game.add_robot(Robot("RoboThree", 300, 30));

    // Memulai game
    game.start_game();

    return 0;
}
