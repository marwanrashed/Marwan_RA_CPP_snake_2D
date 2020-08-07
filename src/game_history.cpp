#include "game_history.h"

    // Default Constructor
    // History ();
    // Methods
    void History::SaveHistory (Player& player){
        // Create output file stream
        std::ofstream Hall_of_fame;
        // format text file
        Hall_of_fame.open("Hall_of_fame.txt", std::ios::binary | std::ios::out | std::ios::app);
        
        if (Hall_of_fame.is_open())
        {
            Hall_of_fame << "Player_name" << " " << "Score" << " " << "Level" << " " << "Time_Stamp" << "\n";
            for (auto player_instance : _players_history) 
            {
            Hall_of_fame << player_instance-> GetName() << " " << player_instance -> GetScore << " " 
                    << player_instance -> GetLevel() << " " << player_instance -> GetTime()<< "\n";
            }

            Hall_of_fame.close();            
        }
        else
        {
           std::cout << "ERROR: Requested file cannot be opened" << std::endl;
        }
    }
    vector<Player> History::ReadHistory (){}
    vector<Player> History::SortPlayers(){}
    void History::DisplayHistory(){}
    Player History::GetHighScore(){}
    void History::DisplayHighScore(){}