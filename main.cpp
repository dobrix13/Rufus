#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set> // Include this for unordered_set
#include "rufus.hpp"

using namespace std;


// Inventory class
class Inventory {
public:
    unordered_set<string> items;

    void addItem(string item) {
        items.insert(item);
    }

    void displayInventory() {
        cout << "Inventory: ";
        if (items.empty()) {
            cout << "None";
        } else {
            for (const auto& item : items) {
                cout << item << " ";
            }
        }
        cout << endl;
    }
};

// Scenario class
class Scenario {
public:
    string description;
    vector<string> choices;
    vector<int> nextScenarios;
    bool isEndScenario;
    int taskDuration;
    int id;
    string pathway;

    Scenario() : description(""), id(0), choices({}), nextScenarios({}), isEndScenario(false), taskDuration(0), pathway("") {}

    Scenario(string desc, vector<string> opts, vector<int> next, bool end, int duration, string path)
        : description(desc), choices(opts), nextScenarios(next), isEndScenario(end), taskDuration(duration), pathway(path) {}
};

// Game class
class Game {
private:
    unordered_map<int, Scenario> scenarios;
    int currentScenario;
    bool gameOver;
    int age;
    Inventory inventory;

public:
    Game() : currentScenario(1), gameOver(false), age(18) { // Rufus starts at age 18
        // Initialize all scenarios (for simplicity, only the intro scenario is added here)
        scenarios[1] = Scenario(
            "Long, long, and longer time ago in a far, far, very far land, there lived a beggar named Rufus...",

            {"Visit the Taverne in the Town", "Visit the Witch in Search of Some Magic", "Go to the Devil Himself"},
            {2, 3, 4},
            false, 3, "Intro"
        );
        // Add more scenarios here
    }

    void start() {
        clearScreen();
        showASCIILogo();
        cin.ignore();  // Wait for Enter key press
        clearScreen();
        showIntro();
        cin.ignore();  // Wait for Enter key press
        clearScreen();
        while (!gameOver) {
            playScenario(currentScenario);
        }
    }

    void playScenario(int scenarioId) {
        clearScreen();
        Scenario scenario = scenarios[scenarioId];
        cout << "Rufus's Age: " << age << endl;
        inventory.displayInventory();
        cout << scenario.description << endl;
        for (int i = 0; i < scenario.choices.size(); ++i) {
            cout << (i + 1) << ". " << scenario.choices[i] << endl;
        }

        int choice;
        cin >> choice;
        if (choice > 0 && choice <= scenario.choices.size()) {
            currentScenario = scenario.nextScenarios[choice - 1];
            age += scenario.taskDuration + 3; // Add the task duration and 3 years for traveling
            // Check if it's a game-over scenario
            if (scenarios[currentScenario].isEndScenario) {
                gameOver = true;
                clearScreen();
                cout << scenarios[currentScenario].description << endl;
                cout << "GAME OVER. Rufus, you are never going to get her! Ha ha ha...." << endl;
            }
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}
