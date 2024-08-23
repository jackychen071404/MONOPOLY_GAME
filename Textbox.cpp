#include "TextBox.h"

TextBox::TextBox(float x, float y, float width, float height, sf::Font& font) {
    box.setSize(sf::Vector2f(width, height));
    box.setPosition(x, y);
    box.setFillColor(sf::Color::White);
    box.setOutlineThickness(1);
    box.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 5, y + 5);
    
    inputText = "";
}

void TextBox::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128) { 
            char inputChar = static_cast<char>(event.text.unicode);

            if (inputChar == '\b') {
                if (!inputText.empty()) {
                    inputText.pop_back();
                }
            }

            else if (inputChar >= '0' && inputChar <= '9') {
                inputText += inputChar;
            }

            text.setString(inputText);
        }
    }
}

void TextBox::draw(sf::RenderWindow& window) {
    window.draw(box);
    window.draw(text);
}

std::string TextBox::getText() const {
    return inputText;
}
bool TextBox::getFocus() {
    return isFocused;
}
void TextBox::setFocus(bool focus) {
    isFocused = focus;
}

void TextBox::clear() {
    inputText.clear();      
    text.setString("");        
}

sf::FloatRect TextBox::getBounds() const {
    return box.getGlobalBounds();
}