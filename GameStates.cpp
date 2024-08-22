#include "GameStates.h"
#include <string>

std::string to_string(GamePhase phase) {
    switch (phase) {
        case GamePhase::RollingDice: return "RollingDice";
        case GamePhase::WaitForDice: return "WaitForDice";
        case GamePhase::is_buying_phase: return "is_buying_phase";
        case GamePhase::mortgaging: return "mortgaging";
        case GamePhase::remortgaging: return "remortgaging";
        case GamePhase::auctioning: return "auctioning";
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