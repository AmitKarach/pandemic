#pragma once
#include "Color.hpp"
#include "City.hpp"
#include <map>

namespace pandemic {
class Board{
    private:
        std::map<City,int> lvl_of_disease;
    public:
        Board() {}
        void remove_cures();
        bool is_clean();
        int& operator[] (City c);
        friend std::ostream& operator<<(std::ostream& out, const Board& b);
};
}