#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <map>
#include <set>

namespace pandemic
{
    class Board
    {
    private:
        static std::map<pandemic::City, std::set<pandemic::City>> city_relations;
            
        std::map<City, Color> city_color =
            {
                {Algiers, Color::Black},
                {Atlanta, Color::Blue},
                {Baghdad, Color::Black},
                {Bangkok, Color::Red},
                {Beijing, Color::Red},
                {Bogota, Color::Yellow},
                {BuenosAires, Color::Yellow},
                {Cairo, Color::Black},
                {Chennai, Color::Black},
                {Chicago, Color::Blue},
                {Delhi, Color::Black},
                {Essen, Color::Blue},
                {HoChiMinhCity, Color::Red},
                {HongKong, Color::Red},
                {Istanbul, Color::Black},
                {Jakarta, Color::Red},
                {Johannesburg, Color::Yellow},
                {Karachi, Color::Black},
                {Khartoum, Color::Yellow},
                {Kinshasa, Color::Yellow},
                {Kolkata, Color::Black},
                {Lagos, Color::Yellow},
                {Lima, Color::Yellow},
                {London, Color::Blue},
                {LosAngeles, Color::Yellow},
                {Madrid, Color::Blue},
                {Manila, Color::Red},
                {MexicoCity, Color::Yellow},
                {Miami, Color::Yellow},
                {Milan, Color::Blue},
                {Montreal, Color::Blue},
                {Moscow, Color::Black},
                {Mumbai, Color::Black},
                {NewYork, Color::Blue},
                {Osaka, Color::Red},
                {Paris, Color::Blue},
                {Riyadh, Color::Black},
                {SanFrancisco,Color::Blue},
                {Santiago, Color::Yellow},
                {SaoPaulo, Color::Yellow},
                {Seoul, Color::Red},
                {Shanghai, Color::Red},
                {StPetersburg, Color::Blue},
                {Sydney, Color::Red},
                {Taipei, Color::Red},
                {Tehran, Color::Black},
                {Tokyo, Color::Red},
                {Washington, Color::Blue}
            };
        std::map<pandemic::City, int> lvl_of_disease;
        std::set<pandemic::City> stations;
        std::set<pandemic::Color> cured_diseases;
    public:
        Board() {}
        static bool check_if_connected(City a, City b);
        bool check_if_station(City c);
        void add_station(City c);
        Color check_color(City c);
        void set_cured_diseases(Color c);
        bool check_cure_discovered(City c);
        bool check_cure_discovered(Color c);


        void remove_cures();
        bool is_clean();
        int &operator[](City c);
        friend std::ostream &operator<<(std::ostream &out, const Board &b);
    };
}