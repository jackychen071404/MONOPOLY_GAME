#include "Player.h"
#include <iostream>
#include <map>
#include <string>

Player::Player(sf::Color fill_color, sf::Vector2f startPos, const sf::Vector2f positions[], const sf::Font& font, int player_no, sf::Vector2f moneyPos) 
: player_no(player_no), inJail(false), no_trains(0)
{
    shape.setRadius(10);
    shape.setFillColor(fill_color);
    shape.setPosition(startPos);
    shape.setOutlineColor(sf::Color::Black);                              
    shape.setOutlineThickness(1.f);
    position_coordinates = new sf::Vector2f[40];
    currentPos = 0;
    money = 1500;
    money_text.setFont(font);
    money_text.setString("Player " + std::to_string(player_no) + ": $" + std::to_string(money));
    money_text.setCharacterSize(48);
    money_text.setFillColor(fill_color);
    money_text.setPosition(moneyPos);
    for (int i = 0; i < 40; i++) {
        position_coordinates[i] = positions[i];
    }
    owned_properties["brown"] = 0;
    owned_properties["cyan"] = 0;
    owned_properties["pink"] = 0;
    owned_properties["orange"] = 0;
    owned_properties["red"] = 0;
    owned_properties["yellow"] = 0;
    owned_properties["green"] = 0;
    owned_properties["blue"] = 0;
}

void Player::update_money(bool add_or_cut, int amt) {
    if (add_or_cut) {
        money += amt;
    } else {
        money -= amt;
    }
    money_text.setString("Player " + std::to_string(player_no) + ": $" + std::to_string(money));
}

unsigned int Player::getPlayerNo() const {
    return player_no;
}

bool Player::owned_all_of_color() {
     std::map<std::string, int> colorRequirements = {
        {"blue", 2},
        {"brown", 2},
        {"cyan", 3},
        {"pink", 3},
        {"orange", 3},
        {"red", 3},
        {"green", 3}
    };

    for (const auto& [color, requiredCount] : colorRequirements) {
        if (owned_properties.at(color) == requiredCount) {
            return true; 
        }
    }

    return false; 
}