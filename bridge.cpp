
#include "bridge.hpp"

#include <iostream>

namespace Bridge {

void Bridge::Play(Card c) {
    Expects(phase() == Phase::Play);

    std::cout << "Playing card: " << static_cast<int>(c.suit) << " " << static_cast<int>(c.rank) << std::endl;
}

} // end namespace Bridge
