#include "Player.h"
#include <iostream>

Player::Player(sf::Color fill_color, sf::Vector2f startPos, const sf::Vector2f positions[], const sf::Font& font, int player_no, sf::Vector2f moneyPos) {
    shape.setRadius(10);
    shape.setFillColor(fill_color);
    shape.setPosition(startPos);
    shape.setOutlineColor(sf::Color::Black);                              
    shape.setOutlineThickness(1.f);
    position_coordinates = new sf::Vector2f[40];
    currentPos = 0;
    money.setFont(font);
    money.setString("Player " + std::to_string(player_no) + ": $1500");
    money.setCharacterSize(48);
    money.setFillColor(fill_color);
    money.setPosition(moneyPos);
    for (int i = 0; i < 40; i++) {
        position_coordinates[i] = positions[i];
    }
}