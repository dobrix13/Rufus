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

    void addItem(const string &item) {
        items.insert(item);
    }

    bool hasItem(const string &item) const {
        for (const auto& it : items) {
            if (it == item) {
                return true;
            }
        }
        return false;
    }
};

// Scenario class
class Scenario {
public:
    string description;
    int id;
    vector<string> choices;
    vector<int> nextScenarios;
    bool isEndScenario;
    int taskDuration;
    string pathway;
    int travelDuration;

    Scenario()
        : description(""), id(0), choices({}), nextScenarios({}), isEndScenario(false), taskDuration(0), pathway("") {}

    Scenario(string desc, int id, vector<string> opts, vector<int> next, bool end, int duration, string path, int travel)
        : description(desc), id(id), choices(opts), nextScenarios(next), isEndScenario(end), taskDuration(duration), pathway(path), travelDuration(travel) {}
};

// Game class
class Game {
private:
    string gameOverMessage = "GAME OVER. You never going to get her! Ha, ha, haaa, Rufus!";
    unordered_map<int, Scenario> scenarios;
    int currentScenario;
    bool gameOver;
    int age;
    Inventory inventory;

public:
    Game()
        : currentScenario(1), gameOver(false), age(18) { // Rufus starts at age 18
        // Initialize all scenarios (for simplicity, only the intro scenario is added here)
        scenarios[1] = Scenario(
            "One day, as he wandered near the castle, he saw the beautiful Princess Isabella and fell head over heels in love. His heart pounded, and his vision blurred. Rufus knew, without a doubt, that he would do anything to win her heart. Even if it meant giving his soul to the devil.",
            1,
            {"Visit the Taverne in the Town", "Visit the Witch in Search of Some Magic", "Go to the Devil Himself"},
            {2, 3, 4},
            false,
            1,
            "Intro", 3);

        scenarios[2] = Scenario(
            "Rufus stepped into the taverne, expecting a lively and welcoming place. To his shock, he found himself in a dark and sinister den, and immediately, a chill runs down his spine. The place is dark and eerily quiet, with shadows dancing across the walls from the flickering candlelight. The air is thick with the stench of stale ale and something else—perhaps despair. In the far corner, hidden in the darkest shadow, sits a lone, drunken customer, muttering incoherently to himself.\n\nThe barkeeper, a burly man with a perpetual scowl, stands behind the counter wiping down an already spotless mug. His eyes are as cold and unfriendly as the rest of the establishment.\n\nRufus knows he must proceed carefully in this unsettling place.",
            2,
            {"Order a drink and try to blend in", "Approach the barkeeper and ask about the Princess", "Leave the taverne immediately"},
            {5, 6, 7},
            false,
            3,
            "Taverne", 2);

        scenarios[3] = Scenario(
            "Rufus decided to visit the witch in search of some magic. However, as he asked the villagers about the exact location of the witch, he found out that nobody knew where she lived. The villagers only spoke of her in hushed tones, mentioning that she could be found across seven seas, seven mountains, or seven woods. Rufus had to make a choice on where to begin his search.",
            3,
            {"Search across seven seas", "Search across seven mountains", "Search across seven woods"},
            {8, 9, 10},
            false,
            5,
            "Witch Pathway", 3);
    }

    void start() {
        showASCIILogo();
        //std::cout << "Press any key to continue..." << std::endl;
        sleep(50000); // Wait for a key press
    
        showIntro();
        //std::cout << "Press any key to continue..." << std::endl;
        sleep(50000); // Wait for another key press
    
        clearScreen();
        while (!gameOver) {
            playScenario(currentScenario);
        }
    }


    void playScenario(int scenarioId) {
        clearScreen();
        Scenario scenario = scenarios[scenarioId];
        // cout << "Rufus's Age: " << age << endl;
        cout << scenario.description << endl;
        for (int i = 0; i < scenario.choices.size(); ++i) {
            cout << (i + 1) << ". " << scenario.choices[i] << endl;
        }
        int choice;
        cin >> choice;
        if (choice > 0 && choice <= scenario.choices.size()) {
            currentScenario = scenario.nextScenarios[choice - 1];
            age += scenario.taskDuration + scenario.travelDuration; // Add the task duration and travel duration
            // Check if it's a game-over scenario
            if (scenarios[currentScenario].isEndScenario) {
                gameOver = true;
                clearScreen();
                cout << gameOverMessage << endl;
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
