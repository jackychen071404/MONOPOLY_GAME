#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>


class Player {
    public: 
        Player(sf::Color fill_color, sf::Vector2f startPos, const sf::Vector2f positions[], const sf::Font& font, int player_no, sf::Vector2f moneyPos);
        sf::CircleShape shape;
        sf::Vector2f* position_coordinates;
        int currentPos;
        int money;
        unsigned int getPlayerNo() const; 
        sf::Text money_text;

        void update_money(bool add_or_cut, int amt);
    private: 
        int player_no;
};

#endif