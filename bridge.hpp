
#ifndef _BRIDGE_HPP_
#define _BRIDGE_HPP_

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#endif // __GNUC__
#include <gsl/gsl>
#ifdef __GNUC__
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

enum class Player {
    South,
    West,
    North,
    East
};

enum class Vulnerability {
    None,
    Ns,
    Ew,
    All
};

class Bridge {
    public:
        constexpr Bridge(Player dealer, Vulnerability vulnerability) noexcept;
        constexpr auto Play(Card c) const noexcept -> void;
    private:
        Player m_dealer;
        Vulnerability m_vulnerability;
        Phase m_phase;
        [[nodiscard]] constexpr auto phase() const noexcept -> Phase {return m_phase;};
};

constexpr Bridge::Bridge(Player dealer, Vulnerability vulnerability) noexcept
    : m_dealer(dealer), m_vulnerability(vulnerability), m_phase(Phase::Play)
{
}

constexpr auto Bridge::Play(Card c) const noexcept -> void
{
    Expects(phase() == Phase::Play);
    Expects(c.suit == Suit::Spades);
}
} // end namespace Bridge

#endif // _BRIDGE_HPP_
