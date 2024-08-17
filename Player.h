#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>


class Player {
    public: 
        Player(sf::Color fill_color, sf::Vector2f startPos, const sf::Vector2f positions[]);
        sf::CircleShape shape;
        sf::Vector2f* position_coordinates;

    private: 
};

#endif