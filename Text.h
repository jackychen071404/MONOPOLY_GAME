#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>

class Text {
    public: 
        Text(const sf::Font& font, const std::string &words, const sf::Color& color, const unsigned int size, const sf::Vector2f& position);
        sf::Text content;
        sf::FloatRect getBounds() const;
};

#endif