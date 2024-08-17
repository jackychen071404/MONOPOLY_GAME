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
    sf::CircleShape p1(10);
    //p1.setFillColor(sf::Color::Red);
    //p1.setPosition(890.f, 910.f); 
    int pos1 = 0;
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
    //p1.setOutlineColor(sf::Color::Black);                              
    //p1.setOutlineThickness(1.f);
    Player P1(sf::Color::Red, sf::Vector2f(890.f, 910.f), positions1);

    //player 2 circle representer
    sf::CircleShape p2(10);
    p2.setFillColor(sf::Color::Blue);
    p2.setPosition(930.f,910.f);
    int pos2 = 0;
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
    p2.setOutlineColor(sf::Color::Black);                              
    p2.setOutlineThickness(1.f);

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

    //money
    sf::Text p1_money;
    p1_money.setFont(font);
    p1_money.setString("Player 1: $1500");
    p1_money.setCharacterSize(48);
    p1_money.setFillColor(sf::Color::Red);
    p1_money.setPosition(150, 750);
    sf::Text p2_money;
    p2_money.setFont(font);
    p2_money.setString("Player 2: $1500");
    p2_money.setCharacterSize(48);
    p2_money.setFillColor(sf::Color::Blue);
    p2_money.setPosition(150, 800);

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
                    roll_result = die1+die2;
                    roll_display = roll_result;
                }
            }
        }

        sf::Time elapsed1 = clock.getElapsedTime();
        if (roll_indices < roll_result) {
            if (player1_turn) {
                if (elapsed1.asMilliseconds() >= 100) {
                    if (pos1 == 39) { //making sure to loop back
                        pos1 = 0;
                    }
                    else {
                        pos1++;
                    }
                    roll_indices++;
                    P1.shape.setPosition(P1.position_coordinates[pos1]);
                    if (roll_indices == roll_result) { //this indicates the turn is over, when destination is reached
                        player1_turn = false;
                        player2_turn = true;
                    }
                    clock.restart();
                }
            }
            else if (player2_turn) {
                if (elapsed1.asMilliseconds() >= 100) {
                    if (pos2 == 39) {
                        pos2 = 0;
                    }
                    else {
                        pos2++;
                    }
                    roll_indices++;
                    p2.setPosition(positions2[pos2]);
                    if (roll_indices == roll_result) {
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
        window.draw(p2);
        window.draw(dice);
        window.draw(dice_info);
        window.draw(p1_money);
        window.draw(p2_money);
        window.display();
    }

    return 0;
}
