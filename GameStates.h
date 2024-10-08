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

enum class TradeTurn {
    player1_turn,
    player2_turn,
};

enum class GamePhase {
    WaitForDice,
    RollingDice,
    SendingtoJail,
    inJail,
    is_buying_phase,
    isNot_buying_phase,
    auctioning,
    mortgaging,
    remortgaging,
    trading,
    trade_request,
    trade_accept,
    buy_houses,
    pay_debts,
    game_decided,
};
std::string to_string(GamePhase phase);
std::string to_string(PlayerTurn turn);
std::string to_string(AuctionTurn turn);
std::string to_string(TradeTurn turn);

#endif // GAMESTATES_H