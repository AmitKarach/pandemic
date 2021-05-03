#pragma once
#include "Board.hpp"
#include <string>
using namespace std;

namespace pandemic {
class Player{
    private:
        Board board;
        City city;
        string job;

    public:
        Player(Board& b, City c, std::string r)
        {
            board =b;
            city =c;
            job =r;
        }
        Player& drive(City c);
        virtual Player& fly_direct(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        virtual Player& build(); //building a reaserch lab in the city if there is a reaserch lab allready in this city we dont need to rais an error and the card stayies in the player hands
        virtual Player& discover_cure(Color c);
        //lower one block of ilnace from the city
        virtual Player& treat(City c);
        string role()
        {
            return job;
        }
        Player& take_card(City c);
};
}