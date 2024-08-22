#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <string>

class TextBox {
public:
    TextBox(float x, float y, float width, float height, sf::Font& font);
    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);
    std::string getText() const;
    bool getFocus();
    void setFocus(bool focus);
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape box;
    sf::Text text;
    std::string inputText;
    bool isFocused;
};

#endif
