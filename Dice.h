#ifndef DICE_H
#define DICE_H

#include <SFML/Graphics.hpp>


class Dice {
    public: 
        Dice(const sf::Font& font);
        sf::RectangleShape shape;
        int die1;
        int die2;
        int roll_display;
        int roll_result;
        int roll_indices;
        sf::Text dice_info;

    private: 
};

#endif