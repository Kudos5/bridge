
class Hands {
    public:
        constexpr Hands(std::set<Card> const & west,
                std::set<Card> const & north,
                std::set<Card> const & east,
                std::set<Card> const & south)
        {
            // Redundant
            /*
            Expects(west.size() == kHandSize);
            Expects(north.size() == kHandSize);
            Expects(east.size() == kHandSize);
            Expects(south.size() == kHandSize);
            */

            // Expects that there are no duplicate cards among the hands
            // We put them all in the same set since it guaranteen that all
            // elements are unique
            std::set<Card> cards;
            cards.insert(west.begin(), west.end());
            cards.insert(north.begin(), west.end());
            cards.insert(east.begin(), west.end());
            cards.insert(south.begin(), west.end());
            Expects(cards.size() == kHandSize*kNumPlayers);
        }
    private:
}
