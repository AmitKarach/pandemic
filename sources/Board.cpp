#include "Board.hpp"

using namespace pandemic;
void Board::remove_cures()
{

}
bool Board::is_clean()
{
    return true;
}
int& Board::operator[] (City c)
{
    return lvl_of_disease[c];
}
std::ostream& pandemic::operator<<(std::ostream& out, const Board& b)
{
    return out;
}