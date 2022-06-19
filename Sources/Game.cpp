//
// Created by barak on 18/06/2022.
//

#include "Game.hpp"

#include <iostream>
#include "random"
#define min_o 50
#define min_h 55
#define max 100

Ball::Game::Game(Ball::Team &home_, Ball::Team &out_)
    :home(&home_), out(&out_){


    /** distribution for game score */

    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> distr_out(80, 20);
    std::normal_distribution<> distr_home(80, 20);


    int balbazor = 0;
    int piqatho = 0;

    for(;;) {
        /** randomised values */
        balbazor = (int) distr_out(gen);
        piqatho = (int) distr_home(gen);

        /** check range */
        if (balbazor >= min_o && balbazor <= max && piqatho >= min_h && piqatho <= max) {
            break;
        }
    }

    /** the team who has most talent will receive the extra points */

    if (home_.getTalent() > out_.getTalent()) {
        piqatho += 10*home_.getTalent() + 1;
    } else {
        balbazor += 10*home_.getTalent() + 1;
    }

    /** update scores for every team */
    this->home->addScore(piqatho);
    this->home->add_neg_baskets(balbazor);

    this->out->addScore(balbazor);
    this->out->add_neg_baskets(piqatho);


    /** if the score is the same value, home team is always the winner */

    if (balbazor <= piqatho) {
        this->home->addWin();
        this->out->addLose();
    } else {
        this->out->addWin();
        this->home->addLose();
    }
}
