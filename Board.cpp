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
ostream& pandemic::operator<<(ostream& out, const Board& b)
{
    return out;
}