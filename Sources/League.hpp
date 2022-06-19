//
// Created by barak on 18/06/2022.
//

#ifndef B_BALL_LEAGUE_HPP
#define B_BALL_LEAGUE_HPP
#include <unordered_map>
#include <vector>
#include <map>
#include "Team.hpp"

namespace Ball {

    class League {
    private:
        std::vector<Team*> pLeague;
        std::vector<Team> helper ;
    public:

        explicit League(std::vector<Team> &team_group);

        League();


        const std::vector<Team *> &getMyTeam() const;

        std::vector<std::string> top_n(int n);
        std::tuple<std::string , int> Sequence_of_victories();
        std::tuple<std::string , int> Sequence_of_losses();
        std::tuple<std::string, int> max_score();
        std::string top_skill();


    };
}
#endif //B_BALL_LEAGUE_HPP
