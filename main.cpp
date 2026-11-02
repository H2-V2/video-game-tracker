// ============================================================
// Video Game Character Tracker
// Tracks player name, health, and level for multiple characters
// The program keeps asking until the user types a valid value.
// ============================================================

#include <iostream>
#include <string>
#include <cstdlib>   // for exit()
using namespace std;

// Limits used by the input checks
const int MAX_NAME_LENGTH = 16;
const int MAX_HEALTH = 100;
const int MAX_LEVEL_DIGITS = 6;   // levels go up to 999999

// ------------------------------------------------------------
// Class: Character
// Stores the data for one video game character
// ------------------------------------------------------------
class Character {
private:
    // Private variables (data hiding) - can only be accessed inside the class
    string playerName;
    int health;
    int level;

public:
    // Parameterized constructor: assigns the name, health, and level
    Character(string name, int hp, int lvl) {
        playerName = name;
        health = hp;
        level = lvl;
    }

    // Getter methods: let main() read the private data safely
    string getName() {
        return playerName;
    }

    int getHealth() {
        return health;
    }

    int getLevel() {
        return level;
    }

    // Method: determines the status of the character using if / else
    string getStatus() {
        if (health >= 70) {
            return "Healthy";
        }
        else if (health >= 30) {
            return "Wounded";
        }
        else {
            return "Critical";
        }
    }

    // Method: displays all the information for this character
    void displayInfo() {
        cout << "Player Name : " << playerName << endl;
        cout << "Health      : " << health << endl;
        cout << "Level       : " << level << endl;
        cout << "Status      : " << getStatus() << endl;
        cout << "------------------------------" << endl;
    }
};

// ------------------------------------------------------------
// Input check functions
// ------------------------------------------------------------

// Reads one whole line that the user typed.
// If there is no more input, the program ends.
string readLine() {
    string line;
    if (!getline(cin, line)) {
        cout << endl << "No more input. Goodbye!" << endl;
        exit(0);
    }
    return line;
}

// A valid name is 1 to 16 characters long with no spaces
bool isValidName(string text) {
    if ((int)text.length() == 0 || (int)text.length() > MAX_NAME_LENGTH) {
        return false;
    }
    for (int i = 0; i < (int)text.length(); i++) {
        if (text[i] == ' ') {
            return false;
        }
    }
    return true;
}

// A whole number is only digits (0-9), and here at most "maxDigits" long.
// This rejects things like "", "abc", "-5", and "12.5".
bool isWholeNumber(string text, int maxDigits) {
    if ((int)text.length() == 0 || (int)text.length() > maxDigits) {
        return false;
    }
    for (int i = 0; i < (int)text.length(); i++) {
        if (text[i] < '0' || text[i] > '9') {
            return false;
        }
    }
    return true;
}

// Keeps asking for a name until it is valid (while loop)
string readName() {
    cout << "Player name: ";
    string text = readLine();
    while (!isValidName(text)) {
        cout << "Invalid name. Use one word, 1 to 16 characters, no spaces." << endl;
        cout << "Player name: ";
        text = readLine();
    }
    return text;
}

// Keeps asking for health until it is a whole number from 0 to 100.
// stoi() turns text like "85" into the number 85. It is only called
// after isWholeNumber() says the text is all digits.
int readHealth() {
    cout << "Health (0-100): ";
    string text = readLine();
    while (!isWholeNumber(text, 3) || stoi(text) > MAX_HEALTH) {
        cout << "Invalid health. Enter a whole number from 0 to 100." << endl;
        cout << "Health (0-100): ";
        text = readLine();
    }
    return stoi(text);
}

// Keeps asking for a level until it is a whole number from 0 to 999999
int readLevel() {
    cout << "Level: ";
    string text = readLine();
    while (!isWholeNumber(text, MAX_LEVEL_DIGITS)) {
        cout << "Invalid level. Enter a whole number from 0 to 999999." << endl;
        cout << "Level: ";
        text = readLine();
    }
    return stoi(text);
}

// ------------------------------------------------------------
// main(): creates the objects and runs the program
// ------------------------------------------------------------
int main() {
    // Variables to hold user input
    string name;
    int hp, lvl;

    // Variables for calculations
    int totalHealth = 0;
    int totalLevel = 0;
    const int NUM_CHARACTERS = 3;

    cout << "==============================" << endl;
    cout << "  VIDEO GAME CHARACTER TRACKER" << endl;
    cout << "==============================" << endl << endl;

    // --------------------------------------------------------
    // Get info for the first 3 characters using cin / cout
    // --------------------------------------------------------
    cout << "Enter info for Character 1" << endl;
    name = readName();
    hp = readHealth();
    lvl = readLevel();
    Character player1(name, hp, lvl);   // Object 1 created with constructor

    cout << endl << "Enter info for Character 2" << endl;
    name = readName();
    hp = readHealth();
    lvl = readLevel();
    Character player2(name, hp, lvl);   // Object 2

    cout << endl << "Enter info for Character 3" << endl;
    name = readName();
    hp = readHealth();
    lvl = readLevel();
    Character player3(name, hp, lvl);   // Object 3

    // Store the objects in an array so we can loop through them
    Character players[NUM_CHARACTERS] = { player1, player2, player3 };

    // --------------------------------------------------------
    // Loop: display every character and add up totals
    // --------------------------------------------------------
    cout << endl << "====== CHARACTER REPORT ======" << endl << endl;

    for (int i = 0; i < NUM_CHARACTERS; i++) {
        players[i].displayInfo();
        totalHealth += players[i].getHealth();
        totalLevel += players[i].getLevel();
    }

    // --------------------------------------------------------
    // Extra calculations: averages
    // --------------------------------------------------------
    double averageHealth = (double)totalHealth / NUM_CHARACTERS;
    double averageLevel = (double)totalLevel / NUM_CHARACTERS;

    cout << "====== TEAM STATISTICS ======" << endl;
    cout << "Average Health : " << averageHealth << endl;
    cout << "Average Level  : " << averageLevel << endl;

    // Find the highest level character using a loop and if statement
    int highestIndex = 0;
    for (int i = 1; i < NUM_CHARACTERS; i++) {
        if (players[i].getLevel() > players[highestIndex].getLevel()) {
            highestIndex = i;
        }
    }
    cout << "Highest Level  : " << players[highestIndex].getName()
         << " (Level " << players[highestIndex].getLevel() << ")" << endl;

    cout << endl << "Thanks for using the tracker!" << endl;

    return 0;
}
