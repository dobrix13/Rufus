#ifndef GAME_HPP
#define GAME_HPP

#include <unordered_map>
#include <string>
#include "Scenario.hpp"
#include "Inventory.hpp"

class Game {
private:
    std::string gameOverMessage = "GAME OVER. You never going to get her! Ha, ha, haaa, Rufus!";
    std::unordered_map<int, Scenario> scenarios;
    int currentScenario;
    bool gameOver;
    int age;
    Inventory inventory;

public:
    Game()
        : currentScenario(1), gameOver(false), age(18) { // Rufus starts at age 18
        // Initialize all scenarios 
        scenarios[1] = Scenario(
            "One day, as Rufus wandered near the castle, he saw the beautiful Princess Isabella and fell head over heels in love. " 
            "His heart pounded, and his vision blurred. Rufus knew, without a doubt, that he would do anything to win her heart. " 
            "Even if it meant giving his soul to the devil.\nThe journey begins...",
            1,
            {"Visit the Taverne in the Town.\nPerhaps the rowdy crowd and a hearty ale will provide some useful advice or a way to get closer to the princess.\n",
            "Visit the Witch in Search of Some Magic. \nA sprinkle of magic might just be what Rufus needs to stand a chance. Surely the local witch would have some potion or spell to aid his cause.\n",
            "Go to the Devil Himself. \nDesperate times call for desperate measures. Will Rufus risk everything to make a deal with the devil?\n"},
            {2, 3, 4},
            false,
            1,
            "The beginning", 3);

        scenarios[2] = Scenario(
            "Rufus stepped into the taverne, expecting a lively and welcoming place."
            "To his shock, he found himself in a dark and sinister den, and immediately, a chill runs down his spine. "
            "The place is dark and eerily quiet, with shadows dancing across the walls from the flickering candlelight. "
            "The air is thick with the stench of stale ale and something else—perhaps despair. " 
            "In the far corner, hidden in the darkest shadow, sits a lone, drunken customer, muttering incoherently to himself.\n\n"
            "The barkeeper, a burly man with a perpetual scowl, stands behind the counter wiping down an already spotless mug. 1"
            "His eyes are as cold and unfriendly as the rest of the establishment.\n\nRufus knows he must proceed carefully in this unsettling place.",
            2,
            {"Speak with barkeeper.\nPerhaps the grumpy barkeeper has some useful information or knows a way to get closer to the princess.\n",
            "Speak with drunk stranger.\nThe lonely customer in the corner might have a tale or a clue to help Rufus in his quest.\n",
            "Leave the taverne immediately.\nThis place feels dangerous and unwelcoming. Maybe it's best to seek help elsewhere."},
            {5, 6, 7},
            false,
            3,
            "Taverne", 2);

        scenarios[3] = Scenario(
            "Rufus decided to visit the witch in search of some magic. "
            "However, as he asked the villagers about the exact location of the witch, he found out that nobody knew where she lived. "
            "The villagers only spoke of her in hushed tones, mentioning that she could be found across seven seas, seven mountains, or seven woods. "
            "Rufus had to make a choice on where to begin his search.",
            3,
            {"Search across seven seas",
            "Search across seven mountains",
            "Search across seven woods"},
            {8, 9, 10},
            false,
            5,
            "Start of Witch Pathway", 3);

		scenarios[4] = Scenario(
			"Rufus decided to go to the Devil Himself. "
            "He knew that the devil was a powerful being, but he was willing to risk it all for the love of Princess Isabella. "
            "As he walked towards the devil's lair, he felt a chill run down his spine. "
            "The devil's lair was a dark and foreboding place, with flames flickering in the distance. "
            "Rufus knew that he had to be careful in his dealings with the devil.",
			4,
			{"Enter the devil's lair",
            "Turn back and leave",
            "wait for the devil to appear"},
			{11, 12, 13},
			false,
			4,
			"Start of Devil Pathway", 4);

		scenarios[5] = Scenario(
			"Rufus, mustering all his courage, approached the barkeeper. "
            "The man behind the counter was as rude and ugly as his appearance suggested, and the smell emanating from him was enough to make anyone's eyes water. "
            "What do you want, beggar the barkeeper growled, his voice as unfriendly as his demeanor. "
            "Please, sir, Rufus began hesitantly, I'm looking for any information that could help me get closer to Princess Isabella. "
            "The barkeeper's eyes narrowed. Information costs money, and you look like you don't have two coins to rub together. "
            "Rufus's heart sank. He had hoped for some kindness, but it was clear that this man wouldn't help him without payment. "
            "With no money in his pockets, Rufus was forced to consider his next move.",
			5,
			{"Speak with the Drunk Stranger",
            "Leave the Taverne",
            "Go and Search for Money"},
			{6, 7, 11},
			false,
			2,
			"Barkeeper", 1);

		scenarios[6] = Scenario(
            "Feeling both curiosity and caution, Rufus approached the lone figure in the darkest corner of the taverne.\n"
            "The stranger's head was hidden beneath a dark hood, and his face was obscured by shadows.\n"
            "As Rufus drew closer, he could hear the man muttering to himself, his words slurred and soaked in melancholy.\n"
            "'...Love... light... everyone... love is light... everyone is light... everyone is love...' "
            "Mustering his courage, Rufus spoke softly:\n-Hallo.\n"
            "The stranger's head lifted slightly, revealing a glint of eyes beneath the hood. "
            "He turned towards Rufus, his voice gravelly and tinged with sorrow: \n"
            "-Who goes there? What do you want?''Rufus hesitated, but then decided to be honest: \n"
            "-I am Rufus. I'm in love with Princess Isabella and I'm seeking help to win her heart. \n"
            "The stranger let out a bitter laugh, \nLove, you say? A fool's errand, but maybe... just maybe... I can help you.\n"
            "My ale is empty. If you get me another drink, I'll tell you a secret. Rufus had to decide how to respond. He had three options:",
			6,
			{"Go and Search for Money",
            "Punch the Stranger in the Face",
            "Leave the taverne"},
			{12, 13, 7},
			false,
			2,
			"Drunk Stranger", 1);

    }

    void start();
    void playScenario(int scenarioId);
};

#endif // GAME_HPP