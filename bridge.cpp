
#include "bridge.hpp"

#include <iostream>

namespace Bridge {

void Bridge::Play(Card c) {
    Expects(phase() == Phase::Play);
    if ( phase() == Phase::Play) {
        std::cout << static_cast<int>(phase()) << std::endl;
    }
}

} // end namespace Bridge
