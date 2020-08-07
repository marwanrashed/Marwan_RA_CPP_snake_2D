#include "game_history.h"

    // Default Constructor
    History::History () { cout << "Game Histroy instance is constructed" << endl;}
    // Methods
    void History::SaveHistory (Player& player){
        // Create output file stream
        std::ofstream Hall_of_fame;
        // format text file
        Hall_of_fame.open("Hall_of_fame.txt", std::ios::binary | std::ios::out | std::ios::app);
        
        if (Hall_of_fame.is_open())
        {
            Hall_of_fame << player.GetName() << " " << player.GetScore() << " " 
                    << player.GetLevel() << "\n";
            Hall_of_fame.close();            
        }
        else
        {
           cout << "ERROR: Requested file cannot be opened" << endl;
        }
    }
    vector<shared_ptr<Player>> History::ReadHistory (){
        string line, name;
        int score, level;
        std::ifstream Hall_of_fame("Hall_of_fame.txt");

        if (Hall_of_fame.is_open())
        {
            while (std::getline(Hall_of_fame, line))
            {
            std::istringstream linestream(line);
            if(linestream >> name >> score >> level)
            {
                // Player P (name, score, level);
                auto shared_player = make_shared <Player>(name, score, level);
                _players_history.emplace_back(std::move(shared_player));
            }
            }
            Hall_of_fame.close();
            cout << "Hall of Fame file is Read Successfully" << endl;
            return _players_history;
    }
    }

    void History::SortPlayers(){sort (_players_history.begin(),_players_history.end(),
                [](const shared_ptr<Player>& a,const shared_ptr<Player>& b ){return a->GetScore() > b->GetScore();});}

    void History::DisplayHistory(){
        if (_players_history.size() >0){
        for(int i =0; i < _players_history.size(); i++)
        {
            cout << "Player ("<<(i+1) << "). "<< _players_history[i]->GetName() << ", score: " << _players_history[i]->GetScore()
                 << ", level: " << _players_history[i]->GetLevel () << "."<< endl;
        if (i > 10)
          break;
  }
        }
    else {
        cout << "ERROR No data to display" << endl;
    }
    }


    Player History::GetHighScore(){
        this->SortPlayers();
        auto tmp = _players_history.front ();
        auto highest_player = (*tmp.get());
        return highest_player;
    }

    Player History::GetLowestScore(){
        this->SortPlayers();
        auto tmp = _players_history.back();
        auto lowest_player = (*tmp.get());
        return lowest_player; 
    }
    void History::DisplayHighScore(){
        auto highest_player = this->GetHighScore();
        cout << "Highest Score Player :"<< highest_player.GetName() << ", score: " << highest_player.GetScore()
                 << ", level: " << highest_player.GetLevel () << "."<< endl; 
    }

    void History::DisplayLowScore(){
    auto lowest_player = this->GetLowestScore();
    cout << "Lowest Score Player :"<< lowest_player.GetName() << ", score: " << lowest_player.GetScore()
                << ", level: " << lowest_player.GetLevel () << "."<< endl; 
    }