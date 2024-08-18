#include "Dice.h"
#include <iostream>

Dice::Dice(const sf::Font& font) {
    shape.setSize(sf::Vector2f(100, 50));
    shape.setPosition(700,200);
    shape.setFillColor(sf::Color::Red);
    roll_display = 0;
    roll_result = 0;
    roll_indices = 0;
    dice_info.setFont(font);
    dice_info.setString("Roll Result");
    dice_info.setCharacterSize(48);
    dice_info.setFillColor(sf::Color::Red);
    dice_info.setPosition(350, 150);
}