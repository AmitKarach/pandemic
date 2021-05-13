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

//the player can go to the nighboring cities withot throwing any card 

Player &Player::drive(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already in -"+ city_to_string(c)};
    }
    if (!Board::check_if_connected(city, c))
    {
        throw std::invalid_argument{"the city -"+city_to_string(c)+" is not connected to the city"+city_to_string(city)};
    }
    city = c;
    return *this;
}

//if the player has a card of a city he can throw this card and go to this city

Player &Player::fly_direct(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already in -"+ city_to_string(c)};
    }

    if (cards.find(c) == cards.end())
    {
        throw std::invalid_argument{"you dont have "+city_to_string(c)+" card"};
    }

    city = c;
    cards.erase(c);
    return *this;
}

//if the player have the card of the city he is in he can throw this card and go to every city he wants

Player &Player::fly_charter(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already in -"+ city_to_string(c)};
    }

    if (cards.find(city) == cards.end())
    {
        throw std::invalid_argument{"you dont have the card for "+city_to_string(city)+" the city you are in"};
    }
    cards.erase(city);
    city = c;
    return *this;
}

// if the city has a station he can go to every city that has a station

Player &Player::fly_shuttle(City c)
{
    if (city == c)
    {
        throw std::invalid_argument{"you are already in -"+ city_to_string(c)};
    }
    if (!board.check_if_station(city))
    {
       throw std::invalid_argument{"the city "+city_to_string(city)+" dosent has a station"};
    }

    if (!board.check_if_station(c))
    {
       throw std::invalid_argument{"the city "+city_to_string(c)+" dosent has a station"};
    }
    city = c;
    return *this;
}

//if the player has the card of the city he is in he can throw this card and build a station there

Player &Player::build()
{
    if (cards.find(city) == cards.end())
    {
        throw std::invalid_argument{"you dont have the card for "+city_to_string(city)+" the city you are in"};
    }
    cards.erase(city);
    board.add_station(city);
    return *this;
}

//if the player is in a city that has a station and has 5 cards with the color of the diesis he is trying to cure then he can cure this dsesis

Player &Player::discover_cure(Color c)
{

    if (!board.check_if_station(city))
    {
        throw std::invalid_argument{"the city- "+city_to_string(city)+" dosent have a station"};
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
        throw std::invalid_argument{"not enough cards with "+color_to_string(c)+" color"};
    }

    for (const auto &card : temp_cards)
    {
        cards.erase(card);
    }

    board.set_cured_diseases(c);
    return *this;
}

//the player can treat a city he is in and remove on of its cubes

Player &Player::treat(City c)
{
    if (city != c)
    {
        throw std::invalid_argument{"you cant treat the city "+city_to_string(c)+" when you are in "+city_to_string(city)};
    }

    if (board[c] == 0)
    {
        throw std::invalid_argument{"number of cubes int the city "+city_to_string(city)+"is 0"};
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
