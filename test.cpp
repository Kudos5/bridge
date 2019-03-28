
#include "bridge.hpp"

int main() {
    using namespace Bridge;
    using Bridge::Bridge;
    Bridge b;
    Card c{Suit::Spades, Rank::Ace};
    b.Play(c);
}
