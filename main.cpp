/****************************************************
*			****									*
*				RUFUS (try to get her)				*
*										****		*
*	Author: Aldis Vitolins							*
****************************************************/

/*


    cout << "  ______ _     _ _______ _     _ ______  " << endl;
    cout << " (_____ (_)   (_|_______|_)   (_) _____) " << endl;
    cout << "  _____) )     _ _____   _     ( (____   " << endl;
    cout << " |  __  / |   | |  ___) | |   | \____ \  " << endl;
    cout << " | |  \ \ |___| | |     | |___| |____) ) " << endl;
    cout << " |_|   |_\_____/|_|      \_____(______/  " << endl;

*/

#include <iostream>
#include <string>
#include <cstdlib>  // Include this for system function
#define NUM_OF_QUESTS = 10

using namespace std;

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls");  // Command for Windows
#else
    system("clear");  // Command for UNIX-based systems
#endif
}

// Function to sleep
void sleep(int milliseconds) {
#ifdef _WIN32
    system(("timeout /t " + to_string(milliseconds / 1000) + " > nul").c_str());
#else
    system(("sleep " + to_string(milliseconds / 1000)).c_str());
#endif
}

// ASCII art logo
void showASCIILogo() {
	cout << "\n\n\n";
    cout << "  ______ _     _ _______ _     _ ______  " << endl;
    cout << " (_____ (_)   (_|_______|_)   (_) _____) " << endl;
    cout << "  _____) )     _ _____   _     ( (____   " << endl;
    cout << " |  __  / |   | |  ___) | |   | \\____ \\  " << endl;
    cout << " | |  \\ \\ |___| | |     | |___| |____) ) " << endl;
    cout << " |_|   |_\\_____/|_|      \\_____(______/  " << endl;
	cout << "\n\n\n";
	cout << "Press Enter to start the game." << endl;
}

// Script class definition
class Script {
private:
   string intro;
   string outro;
   string scenario1_description;
   string scenario1_option1;
   string scenario1_option2;
   string scenario1_option3;
    // Add more text parts as needed

public:
    Script() {
        intro = "\tLong, long, and longer time ago in a far, far, very far land, there lived a beggar named Rufus.\nHe resided just outside the kingdom, in the woods, in a very poor wooden cabin.Despite his ragged clothes and humble life,\nRufus had a heart full of dreams.\n\n";
        scenario1_description = "\tOne day, as he wandered near the castle, he saw the beautiful Princess Isabella and fell head over heels in love.\nHis heart pounded, and his vision blurred. Rufus knew, without a doubt, that he would do anything to win her heart.\nEven if it meant giving his soul to the devil.\n";
        scenario1_option1 = "Rufus decides to visit the taverne in the town.";
        scenario1_option2 = "Rufus visits the witch in search of some magic.";
        scenario1_option3 = "Rufus goes to the devil himself.";
        outro = "\tGAME OVER!!!\nYou never gonna get her... ha ha ha...";
        // Initialize more text parts here
    }

   string getIntro() const { return intro; }
   string getOutro() const { return outro; }
   string getScenario1Option1() const { return scenario1_option1; }
   string getScenario1Option2() const { return scenario1_option2; }
   string getScenario1Option3() const { return scenario1_option3; }
    // Add more getters for other text parts

    // Method to handle quests
    void handleQuest(int scenario) const {
        int new_scenario = 0;


        return new_scenario;
    }
};

int main() {
    // Variables
    vector<int> quests_completed ={0};
    int quests_started = 0;
    bool exti_game = false;
    int scenario = 1;
    Script script;

    // Clear screen and show ASCII logo
    clearScreen();
    showASCIILogo();
    sleep(50000);  // Pause for x seconds

    // Clear screen again before starting intro
    clearScreen();

    while (true) {
        // displays intro at the beginning of the game
        if (quests_completed == 0  && quests_started = 0){
           cout << script.getIntro() <<endl;
            quests_started++;
            sleep(50000);
            clearScreen();
        }else if (quests_started > 0 && exti_game == false ){
            //main scenario1. should start here
            scenario = handleQuest(scenario);
        }

        


        // Exit game
        if (quests_completed == 0 && quests_started != 0) {
           cout << script.getOutro() <<endl; // script class needs to be created to organize quest texts.
            break;
        }

        // Handle quests
        script.handleQuest(quests_completed);
    }

    return 0;
}
