#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>


class Player {
    public: 
        Player(sf::Color fill_color, sf::Vector2f startPos, const sf::Vector2f positions[], const sf::Font& font, int player_no, sf::Vector2f moneyPos);
        sf::CircleShape shape;
        sf::Vector2f* position_coordinates;
        int currentPos;
        int no_trains;
        unsigned int money;
        unsigned int getPlayerNo() const; 
        sf::Text money_text;
        bool inJail;
        void update_money(bool add_or_cut, int amt);
        std::map<std::string, int> owned_properties;
        bool owned_all_of_color();
    private: 
        int player_no;
};

#endif