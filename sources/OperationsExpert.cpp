#include "OperationsExpert.hpp"


using namespace pandemic;

Player &OperationsExpert::build()
{
    board.add_station(city);
    return *this;
}