#ifndef B_BALL_GAME_HPP
#define B_BALL_GAME_HPP

#include "Team.hpp"
#include "League.hpp"
namespace Ball {
    class Game {

    private:
        Team *home;
        Team *out;



    public:
        Game( Team& home_,Team& out_) ;



    };
}

#endif //B_BALL_GAME_HPP