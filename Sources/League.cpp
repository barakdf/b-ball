//
// Created by barak on 18/06/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "League.hpp"

#include "random"

using namespace std;
string basic_team_names[26] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16",
                               "17", "18",
                               "19", "20"};

Ball::League::League(std::vector<Team> &team_group) {

    /** In case the input is a full group of 20 teams */
    if (team_group.size() == 20) {
        for (auto &i: team_group) {
            this->pLeague.push_back(&i);
        }
    }
        /** else complete the rest of the groups up to 20 teams **/
    else {
        for (size_t i = 0; i < team_group.size(); ++i) {
            this->pLeague.push_back(&team_group.at(i));
        }


        std::vector<string> dic_name;
        std::string str;

        for (size_t i = 0; i < 20 - team_group.size(); ++i) {
            srand((unsigned) time(NULL));
            if ((float) rand() / RAND_MAX < 0.5) {
                str = "Macbi - ";
            } else {
                str = "Apoel - ";
            }
            str += basic_team_names[i];
            std::string name = str;

            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // seed the generator
            std::uniform_real_distribution<float> distr(0, 1);
            float star = distr(gen);
            Team temp_team{name, star};

            this->helper.push_back(temp_team);
        }
        for (size_t i = 0; i < 20; ++i) {
            this->pLeague.push_back(&helper.at(i));
        }

    }
}

Ball::League::League() {


    std::vector<string> dic_name;
    char r;
    for (size_t i = 0; i < 20; ++i) {

        std::string name = to_string(i);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> distr(0, 1);


        float star = distr(gen);

        Team temp_team{name, star};
        this->helper.push_back(temp_team);
    }


    for (size_t i = 0; i < 20; ++i) {
        this->pLeague.push_back(&helper.at(i));
    }


}


const vector<Ball::Team *> &Ball::League::getMyTeam() const {
    return (this->pLeague);
}




    bool cum(Ball::Team *team, Ball::Team *team2) {

        float stat, stat2;

        if (team->getLose() != 0 && team2->getLose() != 0) {
            stat = team->getWin() / team->getLose();
            stat2 = team2->getWin() / team2->getLose();

            return stat > stat2;
        }
        return team->getScore() > team2->getScore();
    }



std::vector<std::string> Ball::League::top_n(int n) {

    std::vector<string> ans;
    std::sort(this->pLeague.begin(), this->pLeague.end(), [](Ball::Team *team, Ball::Team *team2) {
        float stat, stat2;
        if (team->getLose() != 0 && team2->getLose() != 0) {
            stat = team->getWin() / team->getLose();
            stat2 = team2->getWin() / team2->getLose();
            return stat > stat2;
        }
        return team->getScore() > team2->getScore();
    });

    std::vector<Team *> temp_n;
    temp_n.assign(this->pLeague.begin(), this->pLeague.begin() + n);
    for (size_t i = 0; i < temp_n.size(); ++i) {
        ans.push_back(temp_n.at(i)->_name());
    }

    return ans;

}

std::tuple<std::string, int> Ball::League::Sequence_of_losses() {
    string temp;
    int lose = 0;

    for (size_t i = 0; i < this->pLeague.size(); ++i) {
        if (lose < this->pLeague.at(i)->getMaxLost()) {
            lose = this->pLeague.at(i)->getMaxLost();
            temp = this->pLeague.at(i)->_name();
        }
    }

    tuple<std::string, int> ans = {temp, lose};
    return ans;
}


std::tuple<std::string, int> Ball::League::Sequence_of_victories() {
    string temp;
    int maxWIN = 0;

    for (size_t i = 0; i < this->pLeague.size(); ++i) {
        if (maxWIN < this->pLeague.at(i)->getMaxWin()) {
            maxWIN = this->pLeague.at(i)->getWin();
            temp = this->pLeague.at(i)->_name();
        }
    }

    tuple<std::string, int> ans = {temp, maxWIN};
    return ans;
}

std::tuple<std::string, int> Ball::League::max_score() {
    string temp;
    int score = 0;

    for (size_t i = 0; i < this->pLeague.size(); ++i) {
        if (score < this->pLeague.at(i)->getScore()) {
            score = this->pLeague.at(i)->getScore();
            temp = this->pLeague.at(i)->_name();
        }
    }

    tuple<std::string, int> ans = {temp, score};
    return ans;
}

std::string Ball::League::top_skill() {
    string temp;
    float talent = 0;

    for (size_t i = 0; i < this->pLeague.size(); ++i) {
        if (talent < this->pLeague.at(i)->getTalent()) {
            temp = this->pLeague.at(i)->_name();
        }
    }

    return temp;
}

