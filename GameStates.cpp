#include "GameStates.h"
#include <string>

std::string to_string(GamePhase phase) {
    switch (phase) {
        case GamePhase::RollingDice: return "RollingDice";
        case GamePhase::WaitForDice: return "WaitForDice";
        case GamePhase::is_buying_phase: return "is_buying_phase";
        case GamePhase::isNot_buying_phase: return "is_not_buying_phase";
        case GamePhase::mortgaging: return "mortgaging";
        case GamePhase::remortgaging: return "remortgaging";
        case GamePhase::auctioning: return "auctioning";
        case GamePhase::SendingtoJail: return "SendingtoJail";
        case GamePhase::inJail: return "inJail";
        default: return "Unknown GamePhase";
    }
}

std::string to_string(PlayerTurn turn) {
    switch (turn) {
        case PlayerTurn::player1_turn: return "player1";
        case PlayerTurn::player2_turn: return "player2";
        default: return "Unknown GamePhase";
    }
}

std::string to_string(AuctionTurn turn) {
    switch (turn) {
        case AuctionTurn::player1_turn: return "auc_player1";
        case AuctionTurn::player2_turn: return "auc_player2";
        default: return "Unknown GamePhase";
    }
}