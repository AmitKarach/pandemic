#include "Player.hpp"
const int five = 5;

using namespace pandemic;

Player &Player::take_card(City c)
{
    cards.insert(c);
    return *this;
}
Player &Player::remove_cards()
{
    cards.clear();
    return *this;
}

Player &Player::drive(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }
    if (!Board::check_if_connected(city, c))
    {
        throw std::invalid_argument{"this citys are not connected"};
    }
    city = c;
    return *this;
}

Player &Player::fly_direct(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }

    if (cards.find(c) == cards.end())
    {
        throw std::invalid_argument{"you dont have this citys card"};
    }

    city = c;
    cards.erase(c);
    return *this;
}

Player &Player::fly_charter(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }

    if (cards.find(city) == cards.end())
    {
        throw std::invalid_argument{"you dont have the card for the city you are in"};
    }
    cards.erase(city);
    city = c;
    return *this;
}

Player &Player::fly_shuttle(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already there"};
    }
    if (board.check_if_station(city)&& board.check_if_station(c))
    {
        city = c;
        return *this;
    }

    throw std::invalid_argument{"one of the citys dont have a station"};
}

Player &Player::build()
{
    if (cards.find(city) == cards.end())
    {
        throw std::invalid_argument{"you dont have the card for the city you are in"};
    }
    cards.erase(city);
    board.add_station(city);
    return *this;
}

Player &Player::discover_cure(Color c)
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
        if (temp_cards.size() == five) {break;}
    }
    if (temp_cards.size() < five)
    {
        throw std::invalid_argument{"not enough cards with this color"};
    }

    for (const auto &card : temp_cards)
    {
        cards.erase(card);
    }

    board.set_cured_diseases(c);

    return *this;
}

Player &Player::treat(City c)
{
    if (city != c)
    {
        throw std::invalid_argument{"you cant treat this city becouse you are not there"};
    }

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
