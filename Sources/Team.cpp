//
// Created by barak on 18/06/2022.
//



#include "Team.hpp"


/**
 * */

Ball::Team::Team(const std::string &_name, float _skill)
    :name(_name), skill(_skill), win(0),max_win(0),lose(0),count_lose(0),count_win(0),negative_baskets(0){
}



void Ball::Team::addWin() {

    this->win ++;
    this->count_win++;
    this->count_lose = 0;

    //The length of the season's longest winning streak
    if(this->count_win > this->max_win){
        this->max_win = this->count_win;
    }


}

void Ball::Team::addLose() {
    this->lose++;
    this->count_lose++;
    this->count_win = 0;
    if (this->count_lose > this->lose){
        this->lose = this->count_lose;
    }


}

void Ball::Team::addScore(int score_ ){
    this->score += score_;
}

void Ball::Team::add_neg_baskets(int absorbed) {
    this->negative_baskets += absorbed;
}