#ifndef GAMESTATES_H
#define GAMESTATES_H
#include <string>
enum class PlayerTurn {
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

#endif // GAMESTATES_H