#include "game_settings.h"


void ProfileManager::WelcomeMenu () {
    cout << "*************** Welcome to the 2D Snake Game ***************" << endl;
    cout << "************************ Main Menu *************************" << endl;
    cout << "Options:****************************************************" << endl;
    cout << "1. Play Game - Press 1**************************************" << endl;
    cout << "2. Show Hall of Fame - Press 2******************************" << endl;
}

int ProfileManager::Input () {
        int key;
        while (!(cin >> key))
    {
        cin.clear();
        while (std::cin.get() != '\n')
            continue;
        // Ask user to try again:
        std::cout << "WARNING: Invalid input, please try again.";
    }
    return key;
}

string ProfileManager::Input_string () {
        string key;
        while (!(cin >> key))
    {
        cin.clear();
        while (std::cin.get() != '\n')
            continue;
        // Ask user to try again:
        std::cout << "WARNING: Invalid input, please try again.";
    }
    return key;
}

void ProfileManager::PlayMenu () {
    cout << "********************** Game Settings ***********************" << endl;
    cout << "Options:****************************************************" << endl;
    cout << "7. Go to default (Level 1)**********************************" << endl;
    cout << "8. Hard mode (Level 2)**************************************" << endl;
    cout << "9. Change theme with default mode***************************" << endl;
}

void ProfileManager::GetPlayerName () {
    cout << "********************** Game Settings ***********************" << endl;
    cout << "Please enter your name:*************************************" << endl;
}

void ProfileManager::DisplayMenu () {
    cout << "****************** Hall of Fame Options ********************" << endl;
    cout << "Options:****************************************************" << endl;
    cout << "3. List by date*********************************************" << endl;
    cout << "4. List by High Scores**************************************" << endl;
    cout << "5. Display Highest Score************************************" << endl;
    cout << "6. Display Lowest Score*************************************" << endl;

}


