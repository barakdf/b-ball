//
// Created by barak on 18/06/2022.
//

#ifndef B_BALL_TEAM_HPP
#define B_BALL_TEAM_HPP
#include "iostream"

namespace Ball {
    class Team {
        std::string name;
        float skill;
        int win;
        int lose;
        int max_win;
        int max_lose;
        int score;
        int count_win;
        int count_lose;
        int negative_baskets;

    public:
        Team(const std::string& _name, float _skill);

        int getScore() const {return this->score;}

        int get_neg_baskets() const {return this->negative_baskets;}

        const std::string & _name() const {return this->name;}

        float getTalent() const {return this->skill;}

        int getWin() const {return this->win;}

        int getLose() const {return this->lose;}

        int getMaxWin() const {return this->max_win;}

        int getMaxLost() const {return this->max_lose;}

        void addScore(int score);

        void addLose();

        void addWin();

        void add_neg_baskets(int absorbed);

    };
}
#endif //B_BALL_TEAM_HPP
