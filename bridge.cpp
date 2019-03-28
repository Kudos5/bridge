
#include "bridge.hpp"

namespace Bridge {

Bridge::Play(Card c) {
    Expects(Phase() == Phase::Play);
}

} // end namespace Bridge
