#include "GeneSplicer.hpp"
using namespace pandemic;
const int five = 5;

Player &GeneSplicer::discover_cure(Color c)
{
    if (!board.check_if_station(city))
    {
        throw std::invalid_argument{"this city dosent have a station"};
    }

    if (board.check_cure_discovered(c))
    {
        return *this;
    }

    if (cards.size() < five)
    {
        throw std::invalid_argument{"not enough cards"};
    }

    int counter = 0;
    int i = 1;
    for(auto card = cards.begin(); card != cards.end(); i++){
        if(i == five) 
        { 
            break;
        }
        card = cards.erase(card);
    }
    
    board.set_cured_diseases(c);
    return *this;
}
