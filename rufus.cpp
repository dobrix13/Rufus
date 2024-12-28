/*


    cout << "  ______ _     _ _______ _     _ ______  " << endl;
    cout << " (_____ (_)   (_|_______|_)   (_) _____) " << endl;
    cout << "  _____) )     _ _____   _     ( (____   " << endl;
    cout << " |  __  / |   | |  ___) | |   | \____ \  " << endl;
    cout << " | |  \ \ |___| | |     | |___| |____) ) " << endl;
    cout << " |_|   |_\_____/|_|      \_____(______/  " << endl;

*/


#include "rufus.hpp"
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

void showIntro(){
	cout << "\tLong, long, and longer time ago in a far, far, very far land, there lived a beggar named Rufus. \nHe resided just outside the kingdom, in the woods, in a very poor wooden cabin. \nDespite his ragged clothes and humble life, Rufus had a heart full of dreams." << endl;
	cout << endl << "Press Enter to continue...\n";
}

void gameOver(){
    cout << "You Loose ! \nYou are a looser and you never going to get her. \nHa ha ha haaa... " << endl;
}