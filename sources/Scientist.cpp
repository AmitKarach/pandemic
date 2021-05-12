#include "Scientist.hpp"
using namespace pandemic;

Player &Scientist::discover_cure(Color c)
{

    if (!board.check_if_station(city))
    {
        throw std::invalid_argument{"this city dosent have a station"};
    }

    if (board.check_cure_discovered(c))
    {
        return *this;
    }
    

    std::set<City> temp_cards;

    for (const auto &card : cards)
    {
        if (board.check_color(card) == c)
        {
            temp_cards.insert(card);
        }
        if (temp_cards.size() == number){break;}
    }
    if (temp_cards.size() != number)
    {
        throw std::invalid_argument{"not enough cards in this color"};
    }

    for (const auto &card : temp_cards)
    {
        cards.erase(card);
    }
    board.set_cured_diseases(c);

    return *this;
}
