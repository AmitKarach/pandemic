#pragma once
#include "Board.hpp"
#include <string>

namespace pandemic {
class Player{
    private:
        Board board;
        City city;
        std::string job;

    public:
        Player(Board& b, City c, std::string r)
        {
            board =b;
            city =c;
            job =r;
        }
        Player& drive(City c);
        virtual Player& fly_direct(City c);// if u have the card of anther city u can go there by droping the city card
        Player& fly_charter(City c);//if u have the card for the city u are in u can drop this card and go to tny city you want 
        Player& fly_shuttle(City c);//if there is a research lab in this city u can move to any city with a research lab
        virtual Player& build(); //building a research lab in the city, if there is a research lab allready in this city we dont need to rais an error and the card stayies in the player hands
        virtual Player& discover_cure(Color c);
        //lower one block of ilnace from the city
        virtual Player& treat(City c);
        std::string role()
        {
            return job;
        }
        Player& take_card(City c);
};
}