//
// Created by barak on 19/06/2022.
//

#include "../doctest.h"
#include "League.hpp"
#include "Schedule.hpp"


using namespace Ball;
using namespace std;

TEST_CASE ("League _ build") {
    League l;

            CHECK_EQ(l.getMyTeam().size(), 20);
    vector<string> name;
    for (int i = 0; i <= 19; ++i) {
        name.push_back(to_string(i));
    }

    for (uint i = 0; i < l.getMyTeam().size(); ++i) {
                CHECK_EQ(l.getMyTeam().at(i)->_name(), name.at(i));
                CHECK_FALSE(l.getMyTeam().at(i)->getTalent() > 1);
                CHECK(l.getMyTeam().at(i)->getTalent() > 0);
    }
}

TEST_CASE ("Statistics") {
    League l;
    Schedule S{l};
            CHECK(get<1>(l.max_score()) > 100);
            CHECK(get<1>(l.Sequence_of_victories()) > 0);
    for (int i = 0;i < 20; ++i) {
        vector<string> top_n = l.top_n(i);
        CHECK_EQ(top_n.size(), i);
    }

}
