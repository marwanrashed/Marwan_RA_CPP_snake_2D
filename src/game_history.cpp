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
           cout << "ERROR: Requested file cannot be opened" << endl;
        }
    }
    vector<shared_ptr<Player>> History::ReadHistory (){
        string line, name, time_stamp;
        int score, level;
        std::ifstream Hall_of_fame("Hall_of_fame.txt");
        std::getline(Hall_of_fame, line);
        std::istringstream linestream(line);
        if (Hall_of_fame.is_open())
        {
            linestream >> name >> score >> level >> time_stamp; 
            while (std::getline(Hall_of_fame, line))
            {
            if(linestream >> name >> score >> level >> time_stamp)
            {
                auto p = make_shared <Player> (&name,&score,&level,&time_stamp);
                _players_history.emplace_back(p);
            }
            }
            Hall_of_fame.close();
            cout << "Hall of Fame file is Read Successfully" << endl;
            return _players_history;
    }
    }

    void History::SortPlayers(){sort (_players_history.begin(),_players_history.end());}
    void History::DisplayHistory(){
        int i = 0;
        this->SortPlayers();
        for(auto player_instance : _players_history)
        {
            cout << "Player ("<<(i+1) << "). "<< player_instance->GetName() << ", score: " << player_instance ->GetScore()
                 << ", level: " << player_instance->GetLevel () << ", date of play: "<< player_instance->GetTime()<< endl;
        ++i;
        if (i > 10)
          break;
  }
    }
    Player History::GetHighScore(){}
    void History::DisplayHighScore(){}