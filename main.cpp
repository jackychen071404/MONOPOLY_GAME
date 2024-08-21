#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include "Player.h"
#include "Dice.h"
#include "Text.h"
#include "Square.h"
#include "GameStates.h"

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

    //array of Squares
    Square squares[40] = {
        Square(0, 0, 0, 0, 0, 0, 0, 0, "GO!", 0, 0, positions1[0]), //go
        Square(1, 60, 2, 10, 30, 90, 160, 250, "brown", 1, 0,positions1[1]), //New Zealand
        Square(2, 0, 0, 0, 0, 0, 0, 0, "shipment", 0,0,positions1[2]),
        Square(3, 60, 4, 20, 60, 180, 320, 450, "brown", 1, 0,positions1[3]), //Australia
        Square(4, 200, 0, 0, 0, 0, 0, 0,"fee", 0,0,positions1[4]),
        Square(5, 200, 50, 100, 150, 200, 0, 0, "airport", 1, 0,positions1[5]),
        Square(6, 100, 6, 30, 90, 270, 400, 550, "cyan", 1, 0,positions1[6]),
        Square(7, 0, 0, 0, 0, 0, 0, 0,"god's plan", 0,0,positions1[7]),
        Square(8, 100, 6, 30, 90, 270, 400, 550, "cyan", 1, 0,positions1[8]),
        Square(9, 120, 8, 40, 100, 300, 450, 600, "cyan", 1, 0,positions1[9]),
        Square(10,0,0, 0, 0, 0, 0, 0,"free", 0,0,positions1[10]),
        Square(11, 140, 10, 50, 150, 450, 625, 750, "pink", 1, 0,positions1[11]),
        Square(12, 150, 0, 0, 0, 0, 0, 0,"util", 1,0,positions1[12]),
        Square(13, 140, 10, 50, 150, 450, 625, 750, "pink", 1, 0,positions1[13]),
        Square(14, 160, 12, 60, 180, 500, 700, 900, "pink", 1, 0,positions1[14]),
        Square(15, 200, 50, 100, 150, 200, 0, 0, "airport", 1, 0,positions1[15]),
        Square(16, 180, 14, 70, 200, 550, 750, 950, "orange", 1, 0,positions1[16]),
        Square(17, 0, 0, 0, 0, 0, 0, 0,"shipment", 0,0,positions1[17]),
        Square(18, 180, 14, 70, 200, 550, 750, 950, "orange", 1, 0,positions1[18]),
        Square(19, 200, 16, 80, 220, 600, 800, 1000, "orange", 1, 0,positions1[19]),
        Square(20, 0, 0, 0, 0, 0, 0, 0,"IMF", 0,0,positions1[20]),
        Square(21, 220, 18, 90, 250, 700, 875, 1050, "red", 1, 0,positions1[21]),
        Square(22, 0, 0, 0, 0, 0, 0, 0,"god's plan", 0,0,positions1[22]),
        Square(23, 220, 18, 90, 250, 700, 875, 1050, "red", 1, 0,positions1[23]),
        Square(24, 240, 20, 100, 300, 750, 925, 1100, "red", 1, 0,positions1[24]),
        Square(25, 200, 50, 100, 150, 200, 0 ,0, "airport", 1,0,positions1[25]),
        Square(26, 260, 22, 110, 330, 800, 975, 1150, "yellow", 1, 0,positions1[26]),
        Square(27, 260, 22, 110, 330, 800, 975, 1150, "yellow", 1, 0,positions1[27]),
        Square(28, 150, 0, 0, 0, 0, 0, 0,"util", 1,0,positions1[28]),
        Square(29, 280, 24, 120, 360, 850, 1025, 1200, "yellow", 1, 0,positions1[29]),
        Square(30, 0, 0, 0, 0, 0, 0, 0,"jail", 0,0,positions1[30]),
        Square(31, 300, 26, 130, 390, 900, 1100, 1275, "green", 1, 0,positions1[31]),
        Square(32, 300, 26, 130, 390, 900, 1100, 1275, "green", 1, 0,positions1[32]),
        Square(33, 0, 0, 0, 0, 0, 0, 0,"shipment", 0,0,positions1[33]),
        Square(34, 320, 28, 150, 450, 1000, 1200, 1400, "green", 1, 0,positions1[34]),
        Square(35, 200, 50, 100, 150, 200, 0, 0, "airport", 1, 0,positions1[35]),
        Square(36, 0, 0, 0, 0, 0, 0, 0,"god's plan", 0,0,positions1[36]),
        Square(37, 350, 35, 175, 500, 1100, 1300, 1500, "blue", 1, 0,positions1[37]),
        Square(38, 100,0, 0, 0, 0, 0, 0, "fee", 0,0,positions1[38]),
        Square(39, 400, 50, 200, 600, 1400, 1700, 2000, "blue", 1, 0,positions1[39]),
    };

    std::random_device rd; //random number generator
    std::mt19937 gen(rd()); //mt19937 is mersenne twister algorithm
    std::uniform_int_distribution<> dis(1, 6);

    sf::Clock clock; //clock for animation
    
    //booleans for game states. Is the dice rolling? Is it buying phase? Etc.
    bool canRoll = true; 
    bool same_roll = false;

    //various game messages
    Text same_roll_notif(font, "Same numbers! Roll again.", sf::Color::Black, 48, sf::Vector2f(250.f,250.f));
    Text buying_phase(font, "BUY?", sf::Color::Black, 48, sf::Vector2f(250.f,350.f));
    Text auction_phase(font, "AUCTION?", sf::Color::Black, 48, sf::Vector2f(600.f,350.f));
    Text jail_notif(font, "GO TO JAIL.", sf::Color::Black, 48, sf::Vector2f(250.f,350.f));

    GamePhase currentPhase = GamePhase::WaitForDice;
    PlayerTurn currentTurn = PlayerTurn::player1_turn;

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::WaitForDice)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                //roll the dice on a dice click
                if (dice.shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    currentPhase = GamePhase::RollingDice;
                    dice.die1 = dis(gen);
                    dice.die2 = dis(gen);
                    dice.roll_result = dice.die1+dice.die2;
                    dice.roll_display = dice.roll_result;
                    same_roll = dice.die1==dice.die2;

                    if (currentTurn == PlayerTurn::player1_turn)
                        dice.dice_info.setString("Player " + std::to_string(1) + ": " + std::to_string(dice.die1) + " and " + std::to_string(dice.die2));
                    else
                        dice.dice_info.setString("Player " + std::to_string(2) + ": " + std::to_string(dice.die1) + " and " + std::to_string(dice.die2));
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::is_buying_phase) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (buying_phase.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    if (currentTurn == PlayerTurn::player1_turn) {
                        P1.update_money(0,squares[P1.currentPos].getPrice());
                        squares[P1.currentPos].setPlayerNo(1);
                        squares[P1.currentPos].setBuyable(0);
                        currentTurn = PlayerTurn::player2_turn;
                    } else if (currentTurn == PlayerTurn::player2_turn) {
                        P2.update_money(0,squares[P2.currentPos].getPrice());
                        squares[P2.currentPos].setPlayerNo(2);
                        squares[P2.currentPos].setBuyable(0);
                        currentTurn = PlayerTurn::player1_turn;
                    }
                    currentPhase = GamePhase::WaitForDice;
                }
            }
        }
        //std::cout << squares[P1.currentPos].getPlayerNo() << std::endl;
        sf::Time elapsed1 = clock.getElapsedTime();
        if (dice.roll_indices < dice.roll_result) {
            if (currentTurn == PlayerTurn::player1_turn) {
    
                if (elapsed1.asMilliseconds() >= 100) {
                    if (P1.currentPos == 39) { //making sure to loop back
                        P1.currentPos = 0;
                        P1.update_money(1,200);
                    }
                    else {
                        P1.currentPos++;
                    }
                    dice.roll_indices++;
                    P1.shape.setPosition(P1.position_coordinates[P1.currentPos]);
                    if (dice.roll_indices == dice.roll_result && !same_roll) { //this indicates the turn is over, when destination is reached
                        if (squares[P1.currentPos].getBuyable()) {
                            currentPhase = GamePhase::is_buying_phase;
                        }
                        else {
                            //P1.update_money(0, squares[P1.currentPos].getRent0());
                            currentPhase = GamePhase::WaitForDice;
                            currentTurn = PlayerTurn::player2_turn;
                        }
                    }
                    clock.restart();
                }
            }
            else if (currentTurn == PlayerTurn::player2_turn) {
                if (elapsed1.asMilliseconds() >= 100) {
                    if (P2.currentPos == 39) {
                        P2.currentPos = 0;
                        P2.update_money(1,200);
                    }
                    else {
                        P2.currentPos++;
                    }
                    dice.roll_indices++;
                    P2.shape.setPosition(positions2[P2.currentPos]);
                    if (dice.roll_indices == dice.roll_result && !same_roll) {
                        if (squares[P2.currentPos].getBuyable()) {
                            currentPhase = GamePhase::is_buying_phase;
                        } else {
                            //P2.update_money(0, squares[P2.currentPos].getRent0());
                            currentPhase = GamePhase::WaitForDice;
                            currentTurn = PlayerTurn::player1_turn;
                        }
                    }
                    clock.restart();
                }
            }
        } else {
            if (same_roll) currentPhase = GamePhase::WaitForDice;
            dice.roll_indices = 0;
            dice.roll_result = 0;
        }
        //std::cout << to_string(currentPhase) << std::endl;

        window.clear();
        window.draw(sprite); // Draw the scaled sprite of the game board
        if (same_roll) window.draw(same_roll_notif.content);
        if (currentPhase == GamePhase::is_buying_phase) {
            window.draw(buying_phase.content);
            window.draw(auction_phase.content);
        }
        for (int i = 0; i < 40; i++) {
            if (squares[i].getPlayerNo() == 1) squares[i].bought_circle.setOutlineColor(sf::Color::Red);
            if (squares[i].getPlayerNo() == 2) squares[i].bought_circle.setOutlineColor(sf::Color::Blue);
            if (!squares[i].getBuyable()) window.draw(squares[i].bought_circle);
        }
        window.draw(P1.shape);
        window.draw(P2.shape);
        window.draw(dice.shape);
        window.draw(dice.dice_info);
        window.draw(P1.money_text);
        window.draw(P2.money_text);
        window.display();
    }

    return 0;
}
