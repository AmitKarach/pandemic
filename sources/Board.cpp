
#include "Board.hpp"

using namespace pandemic;


bool Board::check_if_connected(City a, City b)
{
    bool flag = false;
    if (city_relations.at(a).find(b) != city_relations.at(a).end())
    {
        flag = true;
    }

    return flag;
}

bool Board::check_if_station(City c)
{
    bool flag = false;
    if (stations.find(c) != stations.end())
    {
        flag = true;
    }
    return flag;
}

void Board::add_station(City c)
{
    if (!check_if_station(c))
    {
        stations.insert(c);
    }
}

Color Board::check_color(City c)
{
    return city_color.at(c);
}

void Board::set_cured_diseases(Color c)
{
    cured_diseases.insert(c);
}

bool Board::check_cure_discovered(City c)
{
    bool flag = false;
    if (cured_diseases.find(check_color(c)) != cured_diseases.end())
    {
        flag = true;
    }
    return flag;
}

bool Board::check_cure_discovered(Color c)
{
    bool flag = false;
    if (cured_diseases.find(c) != cured_diseases.end())
    {
        flag = true;
    }
    return flag;
}

void Board::remove_cures()
{
    cured_diseases.clear();
}

bool Board::is_clean()
{
    for (auto &city_num : lvl_of_disease)
    {
        if (city_num.second != 0)
        {
            return false;
        }
    }
    return true;
}

int &Board::operator[](City c)
{
    return lvl_of_disease[c];
}

std::ostream &pandemic::operator<<(std::ostream &out, const Board &b)
{
    out << "this is what we have on the board so far:" << std::endl;

    out << "each city and it number of cubes:" << std::endl;

    for (auto const &pair : b.lvl_of_disease)
    {
        out <<"the city "<< city_to_string(pair.first) << " has " << pair.second <<"number of cubes"<< std::endl;
    }

    out << "you found a cure for this colors : " << std::endl;

    for (auto const &color : b.cured_diseases)
    {
        out << color_to_string(color) << std::endl;
    }

    out << "you have build stations in this cities : " << std::endl;

    for (auto const &city : b.stations)
    {
        out << city_to_string(city) << std::endl;
    }

    return out;
}

std::map<pandemic::City, std::set<pandemic::City>> Board::city_relations =
    {
        {Algiers, {Madrid, Paris, Istanbul, Cairo}},
        {Atlanta, {Chicago, Miami, Washington}},
        {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
        {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
        {Beijing, {Shanghai, Seoul}},
        {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
        {BuenosAires, {Bogota, SaoPaulo}},
        {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
        {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
        {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
        {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
        {Essen, {London, Paris, Milan, StPetersburg}},
        {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
        {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
        {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
        {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
        {Johannesburg, {Kinshasa, Khartoum}},
        {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
        {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
        {Kinshasa, {Lagos, Khartoum, Johannesburg}},
        {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
        {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
        {Lima, {MexicoCity, Bogota, Santiago}},
        {London, {NewYork, Madrid, Essen, Paris}},
        {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
        {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
        {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
        {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
        {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
        {Milan, {Essen, Paris, Istanbul}},
        {Montreal, {Chicago, Washington, NewYork}},
        {Moscow, {StPetersburg, Istanbul, Tehran}},
        {Mumbai, {Karachi, Delhi, Chennai}},
        {NewYork, {Montreal, Washington, London, Madrid}},
        {Osaka, {Taipei, Tokyo}},
        {Paris, {Algiers, Essen, Madrid, Milan, London}},
        {Riyadh, {Baghdad, Cairo, Karachi}},
        {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
        {Santiago, {Lima}},
        {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
        {Seoul, {Beijing, Shanghai, Tokyo}},
        {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
        {StPetersburg, {Essen, Istanbul, Moscow}},
        {Sydney, {Jakarta, Manila, LosAngeles}},
        {Taipei, {Shanghai, HongKong, Osaka, Manila}},
        {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
        {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
        {Washington, {Atlanta, NewYork, Montreal, Miami}}
    };
