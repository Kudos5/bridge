
namespace Bridge {
enum class Phase {
    Play;
};
class Bridge {
    public:
        void Play(Card c);
    private:
        [[nodiscard]] constexpr auto Phase() const noexcept -> Phase {return m_phase;};
        Phase m_phase;
};
} // end namespace Bridge
