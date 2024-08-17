#include "Player.h"

Player::Player(sf::Color fill_color, sf::Vector2f startPos, const sf::Vector2f positions[]) {
    shape.setRadius(10);
    shape.setFillColor(fill_color);
    shape.setPosition(startPos);
    shape.setOutlineColor(sf::Color::Black);                              
    shape.setOutlineThickness(1.f);
    position_coordinates = new sf::Vector2f[40];
    for (int i = 0; i < 40; i++) {
        position_coordinates[i] = positions[i];
    }
}