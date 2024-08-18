#include "Player.h"
#include <iostream>

Player::Player(sf::Color fill_color, sf::Vector2f startPos, const sf::Vector2f positions[], const sf::Font& font, int player_no, sf::Vector2f moneyPos) 
: player_no(player_no)
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
}

void Player::update_money(bool add_or_cut, int amt) {
    if (add_or_cut) {
        money += amt;
    } else {
        money -= amt;
    }
    money_text.setString("Player " + std::to_string(player_no) + ": $" + std::to_string(money));
}