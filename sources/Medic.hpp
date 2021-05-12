#include "Player.hpp"
namespace pandemic {
class Medic : public Player {

    public:
        Medic(Board& b, City c): Player(b, c, "Medic") {}
        
        virtual Player& drive(City c) override;
        virtual Player& fly_direct(City c) override;
        virtual Player& fly_charter(City c) override;
        virtual Player& fly_shuttle(City c) override;
        Player& treat(City c) override;
};
}