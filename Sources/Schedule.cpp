//
// Created by barak on 18/06/2022.
//

#include "Schedule.hpp"
#include <iostream>
#include <algorithm>


Ball::Schedule::Schedule(Ball::League &league_) {

    this->league = &league_;
    std::vector<Game> games;



    const int numDays = 38;
    const int halfSize = 19;
    Team *first = (this->league->getMyTeam().at(0));
    std::vector<Team *> teams;
//    std::copy(this->league->getMyTeam().begin() + 1, this->league->getMyTeam().end(), teams.begin());
    teams = this->league->getMyTeam();
    teams.erase(teams.cbegin());
    int teamsSize = teams.size();

    for (int day = 0; day < numDays; day++) {


        int teamIdx = day % teamsSize;

        if (day + 1 <= 19) {

            Game game{*(teams[(unsigned long)teamIdx]), *first};
            games.push_back(game);

            for (int idx = 1; idx < halfSize; idx++) {
                int firstTeam = (day + idx) % teamsSize;
                int secondTeam = (day + teamsSize - idx) % teamsSize;

                Game game{*(teams[(unsigned long)firstTeam]), *(teams[(unsigned long)secondTeam])};
                games.push_back(game);


            }
        } else {


            Game game{*first, *teams[(unsigned long)teamIdx]};
            games.push_back(game);

            for (int idx = 1; idx < halfSize; idx++) {
                int firstTeam = (day + idx) % teamsSize;
                int secondTeam = (day + teamsSize - idx) % teamsSize;


                Game game{*(teams[(unsigned long)firstTeam]), *(teams[(unsigned long)secondTeam])};
                games.push_back(game);

            }

        }

    }

}
