#ifndef GAMESTATES_H
#define GAMESTATES_H

enum class PlayerTurn {
    player1_turn,
    player2_turn,
};

enum class GamePhase {
    WaitForDice,
    RollingDice,
    is_buying_phase,
};

#endif // GAMESTATES_H