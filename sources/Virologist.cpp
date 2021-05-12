#include "Virologist.hpp"
using namespace pandemic;

Player &Virologist::treat(City c)
{
    if (city == c)
    {
        return Player::treat(c);
    }

    if (cards.empty())
    {
        throw std::invalid_argument{"you dont have any cards"};
    }

    if (cards.find(c) == cards.end())
    {
        throw std::invalid_argument{"you dont have this city card"};
    }

    cards.erase(c);

    if (board[c] == 0)
    {
        throw std::invalid_argument{"number of cubes is 0"};
    }

    if (board.check_cure_discovered(c))
    {
        board[c] = 0;
    }
    else
    {
        board[c]--;
    }

    return *this;
}