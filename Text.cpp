#include "Text.h"

Text::Text(const sf::Font& font, const std::string &words, const sf::Color& color, const unsigned int size, const sf::Vector2f& position) {
    content.setFont(font);
    content.setString(words);
    content.setCharacterSize(size);
    content.setFillColor(color);
    content.setPosition(position);
}