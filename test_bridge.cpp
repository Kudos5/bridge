#include "bridge.hpp"
#include "catch2/catch.hpp"

// Taken from https://github.com/lefticus/cpp_box/blob/master/test/constexpr_tests.cpp
template<bool B> bool static_test()
{
  static_assert(B);
  return B;
}
#define REQUIRE_STATIC(X) REQUIRE( static_test<(X)>() )

SCENARIO( "cards can be played ", "[bridge]" ) {
	using Bridge::Bridge;
    using namespace Bridge;
    GIVEN( "A game of bridge" ) {
        constexpr Bridge b(Player::West, Vulnerability::None);
        WHEN( "a card is played" ) {
            constexpr Card c{Suit::Spades, Rank::Ace};
            b.Play(c);
            THEN( "nothing happens" ) {
                REQUIRE_STATIC( true );
            }
        }
        WHEN( "in bidding phase" ) {
            THEN ( "cards can not be played" ) {
            }
        }
    }
}

