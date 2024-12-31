#include <iostream>
#include <conio.h> // for _getch()
#include "Game.hpp"
#include "Scenario.hpp"
#include "Inventory.hpp"
#include "rufus.hpp"

using namespace std;

void Game::start() {
    clearScreen();
    showASCIILogo();

    _getch(); // Wait for a key press
    clearScreen();
    showIntro();

    _getch(); // Wait for another key press

    while (!gameOver) {
        playScenario(currentScenario);
    }
}

void Game::playScenario(int scenarioId) {
    clearScreen();
    Scenario scenario = scenarios[scenarioId];
    cout << scenario.name << ":" << endl;
    cout << scenario.description << endl << endl;
    
    for (unsigned int i = 0; i < scenario.choices.size(); ++i) {
        cout << (i + 1) << ". " << scenario.choices[i] << endl;
    }
    cout << endl << "Enter your choice (or type 'age' to see Rufus's age): ";
    string input;
    cin >> input;

    if (input == "age") {
        cout << "Rufus's Age: " << age << endl;
        cout << "Press any key to continue..." << endl;
        _getch(); // Wait for a key press
    } else {
        try {
            unsigned int choice = stoi(input);
            if (choice > 0 && choice <= scenario.choices.size()) {
                currentScenario = scenario.nextScenarios[choice - 1];
                age += scenario.taskDuration + scenario.travelDuration; // Add the task duration and travel duration
                // Check if it's a game-over scenario
                if (scenarios[currentScenario].isEndScenario) {
                    gameOver = true;
                    clearScreen();
                    showGameOver();
                }
            } else {
                clearScreen();
                cout << "Invalid choice. Try again." << endl;
            }
        } catch (invalid_argument&) {
            clearScreen();
            cout << "Invalid input. Try again." << endl;
        }
    }
    clearScreen();
}

int main() {
    Game game;
    game.start();
    return 0;
}