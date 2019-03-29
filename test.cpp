
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "bridge.hpp"

TEST_CASE( "Card is played", "[Bridge::Play]" ) {
	using Bridge::Bridge;
    using namespace Bridge;
    Bridge b;
    Card c{Suit::Spades, Rank::Ace};
    b.Play(c);
    REQUIRE( true );
}

