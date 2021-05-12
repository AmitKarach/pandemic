
#include "Researcher.hpp"
using namespace pandemic;
const int five = 5;

Player &Researcher::discover_cure(Color c)
{
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
        if (temp_cards.size() == five)
        {
            break;
        }
    }

    if (temp_cards.size() < five)
    {
        throw std::invalid_argument{"not enough cards with the same color"};
    }

    for (const auto &card : temp_cards)
    {
        cards.erase(card);
    }
    board.set_cured_diseases(c);

    return *this;
}