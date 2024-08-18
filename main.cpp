#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include "Player.h"
#include "Dice.h"

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

    sf::Font font; //font
    if (!font.loadFromFile("C:/Windows/fonts/cambriab.ttf")) {
        throw std::invalid_argument("no font found.");
    }

    //player objects: color, init position, coordinate of positions on board, font, player #, position of money text 
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

    Dice dice(font); //dice object

    std::random_device rd; //random number generator
    std::mt19937 gen(rd()); //mt19937 is mersenne twister algorithm
    std::uniform_int_distribution<> dis(1, 6);

    sf::Clock clock; //clock for animation
    
    //booleans for game states. Is the dice rolling? Is it buying phase? Etc.
    bool canClick = true; 

    //turns and dice rolling logic
    bool diceRolled = false;
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
                diceRolled = true;
                canClick = false;
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                //roll the dice on a dice click
                if (dice.shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    dice.die1 = dis(gen);
                    dice.die2 = dis(gen);
                    dice.roll_result = dice.die1+dice.die2;
                    dice.roll_display = dice.roll_result;
                    same_roll = dice.die1==dice.die2;
                }
            }
        }

        sf::Time elapsed1 = clock.getElapsedTime();
        if (dice.roll_indices < dice.roll_result) {
            if (player1_turn) {
                if (elapsed1.asMilliseconds() >= 100) {
                    if (P1.currentPos == 39) { //making sure to loop back
                        P1.currentPos = 0;
                    }
                    else {
                        P1.currentPos++;
                    }
                    dice.roll_indices++;
                    P1.shape.setPosition(P1.position_coordinates[P1.currentPos]);
                    if (dice.roll_indices == dice.roll_result && !same_roll) { //this indicates the turn is over, when destination is reached
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
                    dice.roll_indices++;
                    P2.shape.setPosition(positions2[P2.currentPos]);
                    if (dice.roll_indices == dice.roll_result && !same_roll) {
                        player1_turn = true;
                        player2_turn = false;
                    }
                    clock.restart();
                }
            }
        } else {
            canClick = true;
            dice.roll_indices = 0;
            dice.roll_result = 0;
        }

        if (diceRolled) {
            dice.dice_info.setString("Dice Roll: " + std::to_string(dice.die1) + " and " + std::to_string(dice.die2));
        } else {
            dice.dice_info.setString("Roll the dice!");
        }

        window.clear();
        window.draw(sprite); // Draw the scaled sprite of the game board
        window.draw(P1.shape);
        window.draw(P2.shape);
        window.draw(dice.shape);
        window.draw(dice.dice_info);
        window.draw(P1.money);
        window.draw(P2.money);
        window.display();
    }

    return 0;
}
