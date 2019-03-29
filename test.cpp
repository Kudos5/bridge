
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "bridge.hpp"

SCENARIO( "cards can be played ", "[bridge]" ) {
	using Bridge::Bridge;
    using namespace Bridge;
    GIVEN( "A game of bridge" ) {
        Bridge b;
        WHEN( "a card is played" ) {
            Card c{Suit::Spades, Rank::Ace};
            b.Play(c);
            THEN( "nothing happens" ) {
                REQUIRE( false );
            }
        }
    }
}

