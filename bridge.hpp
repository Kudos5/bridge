
#ifndef _BRIDGE_HPP_
#define _BRIDGE_HPP_

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include <gsl/gsl>
#pragma GCC diagnostic pop
#endif // __GNUC__

namespace Bridge {
enum class Phase {
    Play,
    Bidding
};

enum class Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

enum class Rank {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

struct Card {
    Suit suit;
    Rank rank;
};

class Bridge {
    public:
        void Play(Card c);
    private:
        Phase m_phase = Phase::Play;
        [[nodiscard]] constexpr auto phase() const noexcept -> Phase {return m_phase;};
};

} // end namespace Bridge

#endif // _BRIDGE_HPP_
