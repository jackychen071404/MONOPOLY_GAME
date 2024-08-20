#include "GameStates.h"
#include <string>

std::string to_string(GamePhase phase) {
    switch (phase) {
        case GamePhase::RollingDice: return "RollingDice";
        case GamePhase::WaitForDice: return "WaitForDice";
        case GamePhase::is_buying_phase: return "is_buying_phase";
        default: return "Unknown GamePhase";
    }
}