/****************************************************
*			****									*
*				RUFUS (try to get her)				*
*										****		*
*	Author: Aldis Vitolins							*
****************************************************/



#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "rufus.hpp"
#define NUM_OF_QUESTS = 10

using namespace std;

// Script class definition
class Script {
private:
   string intro;
   string outro;
   string question;
   string scenario1_description;
   string scenario1_1_description;
   string scenario1_option1;
   string scenario1_1_option1;
   string scenario1_option2;
   string scenario1_1_option2;
   string scenario1_option3;
   string scenario1_1_option3;
    // Add more text parts as needed

public:
    Script() {
        intro = "\tLong, long, and longer time ago in a far, far, very far land, there lived a beggar named Rufus.\nHe resided just outside the kingdom, in the woods, in a very poor wooden cabin.Despite his ragged clothes and humble life,\nRufus had a heart full of dreams.\n\n";
        //scenarios
        scenario1_description = "\tOne day, as he wandered near the castle, he saw the beautiful Princess Isabella and fell head over heels in love.\nHis heart pounded, and his vision blurred. Rufus knew, without a doubt, that he would do anything to win her heart.\nEven if it meant giving his soul to the devil.\n\n";
        scenario1_option1 = "1. Visit the taverne in the town: \nPerhaps the rowdy crowd and a hearty ale will provide some useful advice or a way to get closer to the princess.\n";
        scenario1_option2 = "2. Visit the witch in search of some magic: \nA sprinkle of magic might just be what Rufus needs to stand a chance. Surely the local witch would have some potion or spell to aid his cause.\n";
        scenario1_option3 = "3. Go to the devil himself: \nDesperate times call for desperate measures. Will Rufus risk everything to make a deal with the devil?.\n";
        //taverne 1.1
        scenario1_1_description = "Rufus stepped into the taverne, expecting a lively and welcoming place. To his shock, he found himself in a dark and sinister den, and immediately, a chill runs down his spine. The place is dark and eerily quiet, with shadows dancing across the walls from the flickering candlelight. The air is thick with the stench of stale ale and something else—perhaps despair. In the far corner, hidden in the darkest shadow, sits a lone, drunken customer, muttering incoherently to himself.\n\n";
        scenario1_1_option1 = "Speak with the Barkeeper";
        scenario1_1_option2 = "Speak with the Drunk Stranger";
        scenario1_1_option3 = "Leave the Taverne";
        //outro
        outro = "\tGAME OVER!!!\nYou never gonna get her... ha ha ha...";
        question = "What would Rufus choose next?:\n";
        // Initialize more text parts here
    }

   string getIntro() const { return intro; }
   string getOutro() const { return outro; }
   string getQuestion() const { return question; }
   string getScenario1_description() const { return scenario1_description; }
   string getScenario1_1_description() const { return scenario1_1_description; }
   string getScenario1Option1() const { return scenario1_option1; }
   string getScenario1_1Option1() const { return scenario1_1_option1; }
   string getScenario1Option2() const { return scenario1_option2; }
   string getScenario1_1Option2() const { return scenario1_1_option2; }
   string getScenario1Option3() const { return scenario1_option3; }
   string getScenario1_1Option3() const { return scenario1_1_option3; }
    // Add more getters for other text parts

};

int main() {
    // Variables
    vector<int> quests_completed = {1, 0};
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
        if (quests_completed[1] == 0  && quests_started == 0){
           cout << script.getIntro() <<endl;
            quests_started++;
            sleep(50000);
            clearScreen();
        }else if (quests_started > 0 && exti_game == false ){
            //main scenario1. should start here
            cout << script.getScenario1_description() <<endl;
            cout << script.getQuestion() <<endl;
            cout << script.getScenario1Option1() <<endl;
            cout << script.getScenario1Option2() <<endl;
            cout << script.getScenario1Option3() <<endl;
            
            cin >> scenario;
            clearScreen();

            if(scenario == 1){
            cout << script.getScenario1_1_description() <<endl;
            cout << script.getQuestion() <<endl;
            cout << script.getScenario1_1Option1() <<endl;
            cout << script.getScenario1_1Option2() <<endl;
            cout << script.getScenario1_1Option3() <<endl;
            
            cin >> scenario;
            clearScreen();

        }else if (scenario == 2){
            cout << "Witch pathway coming soon..." << endl;
            break;
        }else if (scenario == 3){
            cout << "Devil pathway coming soon..." << endl;
            break;
        }else {
            cout << "Wrong choice" << endl;
            break;
        }

    }

        


        // Exit game
        if (quests_completed[0] == 0 && quests_started != 0) {
           cout << script.getOutro() <<endl; // script class needs to be created to organize quest texts.
            break;
        }

    }

    return 0;
}
