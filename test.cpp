
#include "bridge.hpp"

int main() {
	using Bridge::Bridge;
    using namespace Bridge;
    Bridge b;
    Card c{Suit::Spades, Rank::Ace};
    b.Play(c);
}
