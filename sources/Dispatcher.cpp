#include "Dispatcher.hpp"

using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }

    if (!board.check_if_station(city))
    {
        return Player::fly_direct(c);    
    }
    city = c;
    return *this;
}
