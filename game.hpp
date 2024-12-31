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
        // Initialize all scenarios (for simplicity, only the intro scenario is added here)
        scenarios[1] = Scenario(
            "One day, as he wandered near the castle, he saw the beautiful Princess Isabella and fell head over heels in love. His heart pounded, and his vision blurred. Rufus knew, without a doubt, that he would do anything to win her heart. Even if it meant giving his soul to the devil.",
            1,
            {"Visit the Taverne in the Town", "Visit the Witch in Search of Some Magic", "Go to the Devil Himself"},
            {2, 3, 4},
            false,
            1,
            "The beginning", 3);

        scenarios[2] = Scenario(
            "Rufus stepped into the taverne, expecting a lively and welcoming place. To his shock, he found himself in a dark and sinister den, and immediately, a chill runs down his spine. The place is dark and eerily quiet, with shadows dancing across the walls from the flickering candlelight. The air is thick with the stench of stale ale and something else—perhaps despair. In the far corner, hidden in the darkest shadow, sits a lone, drunken customer, muttering incoherently to himself.\n\nThe barkeeper, a burly man with a perpetual scowl, stands behind the counter wiping down an already spotless mug. His eyes are as cold and unfriendly as the rest of the establishment.\n\nRufus knows he must proceed carefully in this unsettling place.",
            2,
            {"Speak with barkeeper", "Speak with drunk stranger", "Leave the taverne immediately"},
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
            "Start of Witch Pathway", 3);

		scenarios[4] = Scenario(
			"Rufus decided to go to the Devil Himself. He knew that the devil was a powerful being, but he was willing to risk it all for the love of Princess Isabella. As he walked towards the devil's lair, he felt a chill run down his spine. The devil's lair was a dark and foreboding place, with flames flickering in the distance. Rufus knew that he had to be careful in his dealings with the devil.",
			4,
			{"Enter the devil's lair", "Turn back and leave", "wait for the devil to appear"},
			{11, 12, 13},
			false,
			4,
			"Start of Devil Pathway", 4);

		scenarios[5] = Scenario(
			"Rufus, mustering all his courage, approached the barkeeper. The man behind the counter was as rude and ugly as his appearance suggested, and the smell emanating from him was enough to make anyone's eyes water.What do you want, beggar the barkeeper growled, his voice as unfriendly as his demeanor. Please, sir, Rufus began hesitantly, I'm looking for any information that could help me get closer to Princess Isabella. The barkeeper's eyes narrowed. Information costs money, and you look like you don't have two coins to rub together. Rufus's heart sank. He had hoped for some kindness, but it was clear that this man wouldn't help him without payment. With no money in his pockets, Rufus was forced to consider his next move.",
			5,
			{"Speak with the Drunk Stranger", "Leave the Taverne", "Go and Search for Money"},
			{6, 7, 11},
			false,
			2,
			"Barkeeper", 1);

		scenarios[6] = Scenario(
			"Rufus approached the drunken stranger, who was slumped over the table, mumbling to himself. 'Hey, you there,' Rufus called out, trying to get the stranger's attention. The stranger looked up, his eyes bloodshot and unfocused. 'What do you want?' he slurred, his words barely intelligible.",
			6,
			{"Ask about the witch", "Offer to buy him a drink", "Leave the taverne"},
			{12, 13, 7},
			false,
			2,
			"Drunk Stranger", 1);

    }

    void start();
    void playScenario(int scenarioId);
};

#endif // GAME_HPP