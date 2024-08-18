#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "TRAVEL GAME"); // main window
    sf::Texture texture;     // image into texture
    if (!texture.loadFromFile("TRAVEL_GAME_BOARD_PRICES.png")) {
        return -1;
    }
    sf::Sprite sprite(texture);     // sprite for texture
    sf::Vector2u windowSize = window.getSize();     // window size
    sf::Vector2u textureSize = texture.getSize();      // texture size
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;     // Calculate scale factors to fit the texture to the window size
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    sprite.setScale(scaleX, scaleY);     // scale down the sprite
    HWND hwnd = window.getSystemHandle(); // Get the window handle

    // Set the window position
    // Parameters: handle, x position, y position, width, height, flags
    SetWindowPos(hwnd, HWND_TOP, 100, 0, windowSize.x, windowSize.y, SWP_NOSIZE | SWP_NOZORDER);

    //font
    sf::Font font;
    if (!font.loadFromFile("C:/Windows/fonts/cambriab.ttf")) {
        throw std::invalid_argument("no font found.");
    }

    //player 1 circle representer
    sf::Vector2f positions1[40] = {
        sf::Vector2f(890.f, 910.f),
        sf::Vector2f(780.f, 910.f),
        sf::Vector2f(700.f, 910.f),
        sf::Vector2f(620.f, 910.f),
        sf::Vector2f(540.f, 910.f),
        sf::Vector2f(460.f, 910.f),
        sf::Vector2f(380.f, 910.f),
        sf::Vector2f(300.f, 910.f),
        sf::Vector2f(220.f, 910.f),
        sf::Vector2f(140.f, 910.f),
        sf::Vector2f(40.f, 910.f),
        sf::Vector2f(40.f, 790.f),
        sf::Vector2f(40.f, 710.f),
        sf::Vector2f(40.f, 630.f),
        sf::Vector2f(40.f, 550.f),
        sf::Vector2f(40.f, 470.f),
        sf::Vector2f(40.f, 390.f),
        sf::Vector2f(40.f, 310.f),
        sf::Vector2f(40.f, 230.f),
        sf::Vector2f(40.f, 150.f),
        sf::Vector2f(40.f, 40.f),
        sf::Vector2f(150.f, 40.f),
        sf::Vector2f(230.f, 40.f),
        sf::Vector2f(310.f, 40.f),
        sf::Vector2f(390.f, 40.f),
        sf::Vector2f(470.f, 40.f),
        sf::Vector2f(550.f, 40.f),
        sf::Vector2f(630.f, 40.f),
        sf::Vector2f(710.f, 40.f),
        sf::Vector2f(790.f, 40.f),
        sf::Vector2f(890.f, 40.f),
        sf::Vector2f(890.f, 150.f),
        sf::Vector2f(890.f, 234.f),
        sf::Vector2f(890.f, 318.f),
        sf::Vector2f(890.f, 402.f),
        sf::Vector2f(890.f, 486.f),
        sf::Vector2f(890.f, 570.f),
        sf::Vector2f(890.f, 654.f),
        sf::Vector2f(890.f, 738.f),
        sf::Vector2f(890.f, 822.f)
    };
    Player P1(sf::Color::Red, sf::Vector2f(890.f, 910.f), positions1, font, 1, sf::Vector2f(150, 750));

    //player 2 circle representer
    sf::Vector2f positions2[40] = {
        sf::Vector2f(930.f, 910.f),
        sf::Vector2f(800.f, 910.f),
        sf::Vector2f(720.f, 910.f),
        sf::Vector2f(640.f, 910.f),
        sf::Vector2f(560.f, 910.f),
        sf::Vector2f(480.f, 910.f),
        sf::Vector2f(400.f, 910.f),
        sf::Vector2f(320.f, 910.f),
        sf::Vector2f(240.f, 910.f),
        sf::Vector2f(180.f, 910.f),
        sf::Vector2f(20.f, 910.f),
        sf::Vector2f(20.f, 790.f),
        sf::Vector2f(20.f, 710.f),
        sf::Vector2f(20.f, 630.f),
        sf::Vector2f(20.f, 550.f),
        sf::Vector2f(20.f, 470.f),
        sf::Vector2f(20.f, 390.f),
        sf::Vector2f(20.f, 310.f),
        sf::Vector2f(20.f, 230.f),
        sf::Vector2f(20.f, 150.f),
        sf::Vector2f(20.f, 40.f),
        sf::Vector2f(180.f, 40.f),
        sf::Vector2f(260.f, 40.f),
        sf::Vector2f(340.f, 40.f),
        sf::Vector2f(420.f, 40.f),
        sf::Vector2f(500.f, 40.f),
        sf::Vector2f(580.f, 40.f),
        sf::Vector2f(660.f, 40.f),
        sf::Vector2f(740.f, 40.f),
        sf::Vector2f(830.f, 40.f),
        sf::Vector2f(920.f, 40.f),
        sf::Vector2f(920.f, 150.f),
        sf::Vector2f(920.f, 234.f),
        sf::Vector2f(920.f, 318.f),
        sf::Vector2f(920.f, 402.f),
        sf::Vector2f(920.f, 486.f),
        sf::Vector2f(920.f, 570.f),
        sf::Vector2f(920.f, 654.f),
        sf::Vector2f(920.f, 738.f),
        sf::Vector2f(920.f, 822.f)
    };
    Player P2(sf::Color::Blue, sf::Vector2f(930.f,910.f), positions2, font, 2, sf::Vector2f(150, 800));

    //roll dice button
    sf::RectangleShape dice;
    dice.setSize(sf::Vector2f(100, 50));
    dice.setPosition(700,200);
    dice.setFillColor(sf::Color::Red);

    //two die
    int die1;
    int die2;
    int roll_display = 0;
    int roll_result = 0;
    int roll_indices = 0;
    std::random_device rd;
    std::mt19937 gen(rd()); //mt19937 is a cpp thing that mersenne twister
    std::uniform_int_distribution<> dis(1, 6);
    sf::Text dice_info;
    dice_info.setFont(font);
    dice_info.setString("Roll Result");
    dice_info.setCharacterSize(48);
    dice_info.setFillColor(sf::Color::Red);
    dice_info.setPosition(350, 150);

    //clock for animation
    sf::Clock clock; 
    bool canClick = true;
    bool player1_turn = true;
    bool player2_turn = false;
    bool same_roll = false;

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && canClick)
            {
                canClick = false;
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                //roll the dice on a dice click
                if (dice.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    die1 = dis(gen);
                    die2 = dis(gen);
                    //std::cout << die1 << " " << die2 << std::endl;
                    roll_result = die1+die2;
                    roll_display = roll_result;
                    same_roll = die1==die2;
                }
            }
        }

        sf::Time elapsed1 = clock.getElapsedTime();
        if (roll_indices < roll_result) {
            if (player1_turn) {
                if (elapsed1.asMilliseconds() >= 100) {
                    if (P1.currentPos == 39) { //making sure to loop back
                        P1.currentPos = 0;
                    }
                    else {
                        P1.currentPos++;
                    }
                    roll_indices++;
                    P1.shape.setPosition(P1.position_coordinates[P1.currentPos]);
                    if (roll_indices == roll_result && !same_roll) { //this indicates the turn is over, when destination is reached
                        player1_turn = false;
                        player2_turn = true;
                    }
                    clock.restart();
                }
            }
            else if (player2_turn) {
                if (elapsed1.asMilliseconds() >= 100) {
                    if (P2.currentPos == 39) {
                        P2.currentPos = 0;
                    }
                    else {
                        P2.currentPos++;
                    }
                    roll_indices++;
                    P2.shape.setPosition(positions2[P2.currentPos]);
                    if (roll_indices == roll_result && !same_roll) {
                        player1_turn = true;
                        player2_turn = false;
                    }
                    clock.restart();
                }
            }
        } else {
            canClick = true;
            roll_indices = 0;
            roll_result = 0;
        }

        dice_info.setString(std::to_string(roll_display));

        window.clear();
        window.draw(sprite); // Draw the scaled sprite
        window.draw(P1.shape);
        window.draw(P2.shape);
        window.draw(dice);
        window.draw(dice_info);
        window.draw(P1.money);
        window.draw(P2.money);
        window.display();
    }

    return 0;
}
