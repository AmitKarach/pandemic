#include "Medic.hpp"
using namespace pandemic;

Player& Medic::drive(City c)
{
    if (!board.check_cure_discovered(c))
    {
        return Player::drive(c);
    }

    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }
    if (!Board::check_if_connected(city,c))
    {
        throw std::invalid_argument{"this citys are not connected"};
    }
    city=c;
    board[c]=0;
    return *this;    
}

Player& Medic::fly_direct(City c)
{
    if (!board.check_cure_discovered(c))
    {
        return Player::fly_direct(c);
    }

    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }

    if(cards.find(c) == cards.end())
    {
        throw std::invalid_argument{"you dont have this citys card"};
    }

    city=c;
    board[c]=0;
    cards.erase(c);
    return *this;
}


Player& Medic::fly_charter(City c)
{
    if (!board.check_cure_discovered(c))
    {
        return Player::fly_charter(c);
    }
    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }   
    if (cards.find(city) == cards.end())
    {
        throw std::invalid_argument{"you dont have the card for the city you are in"};
    }

    city=c;
    board[c]= 0;
    cards.erase(city);
    return *this;
}

Player& Medic::fly_shuttle(City c)
{
    if (!board.check_cure_discovered(c))
    {
        return Player::fly_shuttle(c);
    }

    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }  
    if (board.check_if_station(city) && board.check_if_station(c))
    {
        city = c;
        board[c]=0;
        return *this;
    }

    throw std::invalid_argument{"one of the citys dont have a station"};
}

Player& Medic::treat(City c)
{
    if (city != c) {
        throw std::invalid_argument{"you cant treat this city becouse you are not there"};
    }

    if(board[c]==0)
    {
        throw std::invalid_argument{"number of cubes is 0"};
    }

    board[c] = 0;
    return *this;
}