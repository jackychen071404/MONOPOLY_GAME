#ifndef GAMESTATES_H
#define GAMESTATES_H
#include <string>
enum class PlayerTurn {
    player1_turn,
    player2_turn,
};

enum class AuctionTurn {
    player1_turn,
    player2_turn,
};

enum class GamePhase {
    WaitForDice,
    RollingDice,
    is_buying_phase,
    isNot_buying_phase,
    auctioning,
    mortgaging,
    remortgaging,
};
std::string to_string(GamePhase phase);
std::string to_string(PlayerTurn turn);

#endif // GAMESTATES_H