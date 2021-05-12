#include "FieldDoctor.hpp"
using namespace pandemic ;

Player& FieldDoctor::treat(City c) 
{
    if (city != c && !Board::check_if_connected(city,c)) 
    {
        throw std::invalid_argument{"you cant treat this city becouse you are not there"};       
    }

    if(board[c]==0)
    {
        throw std::invalid_argument{"number of cubes is 0"};
    }

    if(board.check_cure_discovered(c))
    {
        board[c]= 0;
    }
    else{
        board[c]--;
    }
    return *this;
}