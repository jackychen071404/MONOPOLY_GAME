#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <string>
#include <map>
#include <iostream>
#include <random>
#include <cstdlib>
#include "Player.h"
#include "Dice.h"
#include "Text.h"
#include "Textbox.h"
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
    Dice jail_dice(font);
    unsigned int jailRollCount = 0;

    //array of Squares
    Square squares[40] = {
        Square(font, 0, 0, 0, 0, 0, 0, 0, 0, 0, "GO!", 0, 0, positions1[0], 0), //go
        Square(font,1, 60, 50, 2, 10, 30, 90, 160, 250, "brown", 1, 0,positions1[1], 0), //New Zealand
        Square(font,2, 0, 0, 0, 0, 0, 0, 0, 0, "shipment", 0,0,positions1[2], 0),
        Square(font,3, 60, 50, 4, 20, 60, 180, 320, 450, "brown", 1, 0,positions1[3], 0), //Australia
        Square(font,4, 200, 0, 0, 0, 0, 0, 0, 0,"fee", 0,0,positions1[4], 0),
        Square(font,5, 200, 0, 50, 100, 150, 200, 0, 0, "airport", 1, 0,positions1[5], 0),
        Square(font,6, 100, 50, 6, 30, 90, 270, 400, 550, "cyan", 1, 0,positions1[6], 0),
        Square(font,7, 0, 0, 0, 0, 0, 0, 0, 0,"god's plan", 0,0,positions1[7],0),
        Square(font,8, 100, 50, 6, 30, 90, 270, 400, 550, "cyan", 1, 0,positions1[8],0),
        Square(font,9, 120, 50, 8, 40, 100, 300, 450, 600, "cyan", 1, 0,positions1[9],0),
        Square(font,10,0,0,0, 0, 0, 0, 0, 0,"free", 0,0,positions1[10],0),
        Square(font,11, 140, 100, 10, 50, 150, 450, 625, 750, "pink", 1, 0,positions1[11],0),
        Square(font,12, 150, 0, 0, 0, 0, 0, 0, 0,"util", 1,0,positions1[12],0),
        Square(font,13, 140, 100, 10, 50, 150, 450, 625, 750, "pink", 1, 0,positions1[13],0),
        Square(font,14, 160, 100, 12, 60, 180, 500, 700, 900, "pink", 1, 0,positions1[14],0),
        Square(font,15, 200, 0, 50, 100, 150, 200, 0, 0, "airport", 1, 0,positions1[15],0),
        Square(font,16, 180, 100, 14, 70, 200, 550, 750, 950, "orange", 1, 0,positions1[16],0),
        Square(font,17, 0, 0, 0, 0, 0, 0, 0, 0,"shipment", 0,0,positions1[17],0),
        Square(font,18, 180, 100, 14, 70, 200, 550, 750, 950, "orange", 1, 0,positions1[18],0),
        Square(font,19, 200, 100, 16, 80, 220, 600, 800, 1000, "orange", 1, 0,positions1[19],0),
        Square(font,20, 0, 0, 0, 0, 0, 0, 0, 0,"IMF", 0,0,positions1[20],0),
        Square(font,21, 220, 150, 18, 90, 250, 700, 875, 1050, "red", 1, 0,positions1[21],0),
        Square(font,22, 0, 0, 0, 0, 0, 0, 0, 0,"god's plan", 0,0,positions1[22],0),
        Square(font,23, 220, 150, 18, 90, 250, 700, 875, 1050, "red", 1, 0,positions1[23],0),
        Square(font,24, 240, 150, 20, 100, 300, 750, 925, 1100, "red", 1, 0,positions1[24],0),
        Square(font,25, 200, 0, 50, 100, 150, 200, 0 ,0, "airport", 1,0,positions1[25],0),
        Square(font,26, 260, 150, 22, 110, 330, 800, 975, 1150, "yellow", 1, 0,positions1[26],0),
        Square(font,27, 260, 150, 22, 110, 330, 800, 975, 1150, "yellow", 1, 0,positions1[27],0),
        Square(font,28, 150, 0, 0, 0, 0, 0, 0, 0,"util", 1,0,positions1[28],0),
        Square(font,29, 280, 150, 24, 120, 360, 850, 1025, 1200, "yellow", 1, 0,positions1[29],0),
        Square(font,30, 0, 0, 0, 0, 0, 0, 0, 0,"jail", 0,0,positions1[30],0),
        Square(font,31, 300, 200, 26, 130, 390, 900, 1100, 1275, "green", 1, 0,positions1[31],0),
        Square(font,32, 300, 200, 26, 130, 390, 900, 1100, 1275, "green", 1, 0,positions1[32],0),
        Square(font,33, 0, 0, 0, 0, 0, 0, 0, 0,"shipment", 0,0,positions1[33],0),
        Square(font,34, 320, 200, 28, 150, 450, 1000, 1200, 1400, "green", 1, 0,positions1[34],0),
        Square(font,35, 200, 0, 50, 100, 150, 200, 0, 0, "airport", 1, 0,positions1[35],0),
        Square(font,36, 0, 0, 0, 0, 0, 0, 0, 0,"god's plan", 0,0,positions1[36],0),
        Square(font,37, 350, 200, 35, 175, 500, 1100, 1300, 1500, "blue", 1, 0,positions1[37],0),
        Square(font,38, 100,0, 0, 0, 0, 0, 0, 0, "fee", 0,0,positions1[38],0),
        Square(font,39, 400, 200, 50, 200, 600, 1400, 1700, 2000, "blue", 1, 0,positions1[39],0),
    };

    std::random_device rd; //random number generator
    std::mt19937 gen(rd()); //mt19937 is mersenne twister algorithm
    std::uniform_int_distribution<> dis(1, 6);

    sf::Clock clock; //clock for animation
    
    //booleans for game states. Is the dice rolling? Is it buying phase? Etc.
    bool returnToBuy = false;
    bool same_roll = false;
    int biddingNo = 0;
    int previousBiddingNo = 0;
    int sameRollCount = 0;

    //various game messages
    Text same_roll_notif(font, "Same numbers! Roll again.", sf::Color::Black, 48, sf::Vector2f(250.f,250.f));
    Text buying_phase(font, "BUY?", sf::Color::Black, 48, sf::Vector2f(250.f,350.f));
    Text auction_phase(font, "AUCTION?", sf::Color::Black, 48, sf::Vector2f(600.f,350.f));
    Text trade(font, "TRADE?", sf::Color::Black, 48, sf::Vector2f(500.f,400.f));
    Text offer(font, "OFFER", sf::Color::Black, 48, sf::Vector2f(500.f,700.f));
    Text buy_hotels(font, "BUY HOTELS?", sf::Color::Black, 48, sf::Vector2f(200.f,500.f));
    Text request(font, "REQUEST", sf::Color::Black, 48, sf::Vector2f(500.f,700.f));
    Text trade_notif(font, "CAN'T AFFORD", sf::Color::Black, 48, sf::Vector2f(500.f,650.f));
    TextBox moneyOffer(350, 600, 300, 50, font);
    TextBox moneyRequest(350, 600, 300, 50, font);
    Text forfeit(font, "BANKRUPT?", sf::Color::Black, 48, sf::Vector2f(140.f,700.f));
    Text accept(font, "ACCEPT?", sf::Color::Black, 48, sf::Vector2f(250.f,350.f));
    Text refuse(font, "REFUSE?", sf::Color::Black, 48, sf::Vector2f(600.f,350.f));
    Text remortgage(font, "REMORTGAGE?", sf::Color::Black, 48, sf::Vector2f(500.f,600.f));
    Text mortgage(font, "MORTGAGE?", sf::Color::Black, 48, sf::Vector2f(500.f,700.f));
    Text end_mortgage(font, "END", sf::Color::Black, 48, sf::Vector2f(700.f,700.f));
    Text pass(font, "PASS", sf::Color::Black, 48, sf::Vector2f(700.f,800.f));
    Text jail_notif(font, "GO TO JAIL.", sf::Color::Black, 48, sf::Vector2f(500.f,100.f));
    Text who_jail(font, "", sf::Color::Black, 48, sf::Vector2f(250.f,350.f));
    Text pay50(font, "PAY 50$?", sf::Color::Black,48,sf::Vector2f(300,300));
    Text roll_freedom(font, "ROLL?", sf::Color::Black,48,sf::Vector2f(600,300));
    Text jail_rolls(font, "", sf::Color::Black,48,sf::Vector2f(200,600));
    Text p1_notif(font, "+$", sf::Color::Black, 48, sf::Vector2f(600,750));
    Text p2_notif(font, "+$", sf::Color::Black, 48, sf::Vector2f(600,800));
    TextBox textBox(350, 600, 300, 50, font);
    Text auction_notes(font, "Enter bid.", sf::Color::Black, 48, sf::Vector2f(350.f, 500.f));
    Text how_much(font, "HOW MUCH?", sf::Color::Black, 48, sf::Vector2f(350.f, 300.f));
    Text bid(font, "BID!", sf::Color::Black, 48, sf::Vector2f(150.f, 700.f));
    Text GIVE(font, "GIVE UP!", sf::Color::Black, 48, sf::Vector2f(700.f, 700.f));
    Text biddingNoText(font, "Previous bid: 0", sf::Color::Black, 48, sf::Vector2f(120.f, 120.f));
    Text auc_turn(font, "Auction Turn: ", sf::Color::Black, 48, sf::Vector2f(650.f, 120.f));
    Text game_decision(font,"",sf::Color::Black,100,sf::Vector2f(150,500));

    GamePhase currentPhase = GamePhase::WaitForDice;
    PlayerTurn currentTurn = PlayerTurn::player1_turn;
    AuctionTurn auctionTurn = AuctionTurn::player1_turn;
    bool firstAuction = true;
    bool firstBid = false;
    Player* currentPlayer;
    Player* otherPlayer;

    std::map<std::string, int> colorRequirements = {
        {"blue", 2},
        {"brown", 2},
        {"cyan", 3},
        {"pink", 3},
        {"orange", 3},
        {"red", 3},
        {"green", 3}
    };
    // Main loop
    while (window.isOpen())
    {
        if (currentTurn == PlayerTurn::player1_turn) {
            currentPlayer = &P1;
            otherPlayer = &P2;
        } else if (currentTurn == PlayerTurn::player2_turn) {
            currentPlayer = &P2;
            otherPlayer = &P1;
        }
        sf::Event event;
        sf::Time elapsed1 = clock.getElapsedTime();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (currentPhase == GamePhase::auctioning) {
                if (textBox.getFocus()) textBox.handleEvent(event);
            } else if (currentPhase == GamePhase::trade_request) {
                if (moneyRequest.getFocus()) moneyRequest.handleEvent(event);
            } else if (currentPhase == GamePhase::trading) {
                if (moneyOffer.getFocus()) moneyOffer.handleEvent(event);
            }
            //std::cout<<P2.owned_properties["brown"]<<std::endl;
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::WaitForDice)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (dice.shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    dice.die1 = 1;//dis(gen);
                    dice.die2 = 0;//dis(gen);
                    dice.roll_result = dice.die1+dice.die2;
                    dice.roll_display = dice.roll_result;
                    if (dice.die1 != dice.die2) sameRollCount = 0;
                    same_roll = dice.die1==dice.die2;
                    if (same_roll && currentPhase != GamePhase::RollingDice) sameRollCount++;
                    currentPhase = GamePhase::RollingDice;

                    if (currentTurn == PlayerTurn::player1_turn) dice.dice_info.setString("Player " + std::to_string(1) + ": " + std::to_string(dice.die1) + " and " + std::to_string(dice.die2));
                    else dice.dice_info.setString("Player " + std::to_string(2) + ": " + std::to_string(dice.die1) + " and " + std::to_string(dice.die2));
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::is_buying_phase) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (buying_phase.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && squares[currentPlayer->currentPos].getPrice() <= currentPlayer->money) {
                    currentPlayer->update_money(0,squares[currentPlayer->currentPos].getPrice());
                    squares[currentPlayer->currentPos].setPlayerNo(currentPlayer->getPlayerNo());
                    squares[currentPlayer->currentPos].setBuyable(0);
                    currentPlayer->owned_properties[squares[currentPlayer->currentPos].getType()]++;
                    if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                    if (!(otherPlayer->inJail))  currentPhase = GamePhase::WaitForDice;
                    else currentPhase = GamePhase::inJail;
                }   else if (mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPhase = GamePhase::mortgaging;
                }   else if (remortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPhase = GamePhase::remortgaging;
                }   else if (auction_phase.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && currentPlayer->money > 0) {
                    currentPhase = GamePhase::auctioning;
                }   else if (trade.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPhase = GamePhase::trading;
                }   else if (forfeit.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPhase = GamePhase::game_decided;
                }   else if (buy_hotels.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && currentPlayer->owned_all_of_color()) {
                    currentPhase = GamePhase::buy_houses;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::mortgaging) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (end_mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && returnToBuy) {
                    currentPhase = GamePhase::is_buying_phase;
                } else if (end_mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && !returnToBuy) {
                    currentPhase = GamePhase::isNot_buying_phase;
                } else {
                    for (int i = 0; i < 40; i++) {
                        if (squares[i].getPlayerNo() == currentPlayer->getPlayerNo()) {
                            if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && squares[i].getNumHouses() == 0) {
                                if (currentTurn == PlayerTurn::player1_turn) {
                                    squares[i].setPlayerNo(3);
                                    squares[i].bought_circle.setOutlineColor(sf::Color::Green);
                                    currentPlayer->owned_properties[squares[i].getType()]--;
                                } else {
                                    squares[i].setPlayerNo(4); 
                                    squares[i].bought_circle.setOutlineColor(sf::Color::Yellow); //mortgaged
                                    currentPlayer->owned_properties[squares[i].getType()]--;
                                }
                                currentPlayer->update_money(1, squares[i].getPrice() * .5);
                            } else if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && squares[i].getNumHouses() != 0) {
                                squares[i].decrementHouses();
                                squares[i].houseText.setString(std::to_string(squares[i].getNumHouses()));
                                currentPlayer->update_money(1, squares[i].getHousePrice() * .5);
                            }
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::remortgaging) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (end_mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && returnToBuy) {
                    currentPhase = GamePhase::is_buying_phase;
                } else if (end_mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && !returnToBuy) {
                    currentPhase = GamePhase::isNot_buying_phase;
                } else {
                    for (int i = 0; i < 40; i++) {
                        if (currentPlayer->getPlayerNo() == 1) {
                            if (squares[i].getPlayerNo() == 3) {
                                if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && currentPlayer->money >= squares[i].getPrice() * .5 * 1.1) {
                                    currentPlayer->update_money(0, squares[i].getPrice() * .5 * 1.1);
                                    squares[i].bought_circle.setOutlineColor(sf::Color::Red);
                                    squares[i].setPlayerNo(1);
                                    currentPlayer->owned_properties[squares[i].getType()]++;
                                }
                            }
                        } else {
                            if (squares[i].getPlayerNo() == 4) {
                                if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                                    currentPlayer->update_money(0, squares[i].getPrice() * .5 * 1.1);
                                    squares[i].bought_circle.setOutlineColor(sf::Color::Blue);
                                    squares[i].setPlayerNo(2);
                                    currentPlayer->owned_properties[squares[i].getType()]++;
                                }
                            }
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::isNot_buying_phase) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        currentPhase = GamePhase::mortgaging;
                }   else if (remortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        currentPhase = GamePhase::remortgaging;
                }   else if (trade.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        currentPhase = GamePhase::trading;
                }   else if (forfeit.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        currentPhase = GamePhase::game_decided;
                }   else if (buy_hotels.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && currentPlayer->owned_all_of_color()) {
                    currentPhase = GamePhase::buy_houses;
                }   else if (pass.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                        if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                        else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                        if (!(otherPlayer->inJail))  currentPhase = GamePhase::WaitForDice;
                        else currentPhase = GamePhase::inJail;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::auctioning) {
                if (firstAuction) {
                    if (currentTurn == PlayerTurn::player1_turn)  auctionTurn = AuctionTurn::player1_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) auctionTurn = AuctionTurn::player2_turn;
                    biddingNo = 0;
                    previousBiddingNo = 0;
                    std::string previousBiddingStr = "Previous bid: " + std::to_string(previousBiddingNo);
                    biddingNoText.setText(previousBiddingStr);
                    textBox.clear();
                    firstAuction = false;
                    firstBid = false;
                }
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (textBox.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    textBox.setFocus(true);
                }   else {
                    textBox.setFocus(false);
                }

                if (GIVE.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && !textBox.getText().empty() && firstBid) {
                    if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                    if (auctionTurn == AuctionTurn::player1_turn)  {
                        P2.update_money(0, biddingNo);
                        squares[currentPlayer->currentPos].setPlayerNo(P2.getPlayerNo());
                        squares[currentPlayer->currentPos].setBuyable(0);
                        P2.owned_properties[squares[currentPlayer->currentPos].getType()]++;
                        
                    } else if (auctionTurn == AuctionTurn::player2_turn) {
                        P1.update_money(0, biddingNo);
                        squares[currentPlayer->currentPos].setPlayerNo(P1.getPlayerNo());
                        squares[currentPlayer->currentPos].setBuyable(0);
                        P1.owned_properties[squares[currentPlayer->currentPos].getType()]++;
                    }
                    biddingNo = 0;
                    previousBiddingNo = 0;
                    if (!(otherPlayer->inJail))  currentPhase = GamePhase::WaitForDice;
                    else currentPhase = GamePhase::inJail;
                    firstAuction = true;
                    //reset auction values
                } else if (bid.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    if (textBox.getText() != "") biddingNo = std::stoi(textBox.getText());
                    if (biddingNo < 1) {
                        auction_notes.setText("Enter value higher than 1!");
                        firstBid = false;
                    }
                    else if (auctionTurn == AuctionTurn::player1_turn && previousBiddingNo >= P1.money) {
                        P2.update_money(0, previousBiddingNo);
                        squares[currentPlayer->currentPos].setPlayerNo(P2.getPlayerNo());
                        squares[currentPlayer->currentPos].setBuyable(0);
                        biddingNo = 0;
                        previousBiddingNo = 0;
                        if (!(otherPlayer->inJail))  currentPhase = GamePhase::WaitForDice;
                        else currentPhase = GamePhase::inJail;
                        firstAuction = true;
                    } else if (auctionTurn == AuctionTurn::player2_turn && previousBiddingNo >= P2.money) {
                        P1.update_money(0, previousBiddingNo);
                        squares[currentPlayer->currentPos].setPlayerNo(P1.getPlayerNo());
                        squares[currentPlayer->currentPos].setBuyable(0);
                        biddingNo = 0;
                        previousBiddingNo = 0;
                        if (!(otherPlayer->inJail))  currentPhase = GamePhase::WaitForDice;
                        else currentPhase = GamePhase::inJail;
                        firstAuction = true;
                    }
                    else if (biddingNo <= previousBiddingNo) {
                        auction_notes.setText("Set value higher than previous bid!");
                        firstBid = false;
                    }
                    else if (auctionTurn == AuctionTurn::player1_turn && biddingNo > P1.money) {
                        auction_notes.setText("Can't afford!");
                        firstBid = false;
                    } else if (auctionTurn == AuctionTurn::player2_turn && biddingNo > P2.money) {
                        auction_notes.setText("Can't afford!");
                        firstBid = false;
                    }
                    else {
                        firstBid = true;
                        auction_notes.setText("How much?");
                        previousBiddingNo = biddingNo;
                        std::string previousBiddingStr = "Previous bid: " + std::to_string(previousBiddingNo);
                        biddingNoText.setText(previousBiddingStr);
                        if (auctionTurn == AuctionTurn::player1_turn)  {
                            auctionTurn = AuctionTurn::player2_turn;
                            auc_turn.setText("Turn: Player 2");
                        }
                        else if (auctionTurn == AuctionTurn::player2_turn) {
                            auctionTurn = AuctionTurn::player1_turn;
                            auc_turn.setText("Turn: Player 1");
                        }
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::inJail) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (pay50.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPlayer->update_money(0, 50);
                    currentPlayer->inJail = false;
                    if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                    if (!(otherPlayer->inJail))  currentPhase = GamePhase::WaitForDice;
                    else currentPhase = GamePhase::inJail;
                } else if (roll_freedom.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && jailRollCount < 4) {
                    jail_dice.die1 = dis(gen);
                    jail_dice.die2 = dis(gen);
                    if (currentTurn == PlayerTurn::player1_turn) jail_rolls.setText("Player " + std::to_string(1) + ": " + std::to_string(jail_dice.die1) + " and " + std::to_string(jail_dice.die2));
                    else jail_rolls.setText("Player " + std::to_string(2) + ": " + std::to_string(jail_dice.die1) + " and " + std::to_string(jail_dice.die2));
                    if (jail_dice.die1 == jail_dice.die2) currentPlayer->inJail=false;
                    jailRollCount++;
                    if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                    if (!(otherPlayer->inJail))  currentPhase = GamePhase::WaitForDice;
                    else currentPhase = GamePhase::inJail;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::trading) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (moneyOffer.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    moneyOffer.setFocus(true);
                }   else {
                    moneyOffer.setFocus(false);
                }

                for (int i = 0; i < 40; i++) {
                    if (squares[i].getPlayerNo() == currentPlayer->getPlayerNo()) {
                        if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && squares[i].getNumHouses() == 0) {
                            squares[i].setPlayerNo(5);
                            squares[i].bought_circle.setOutlineColor(sf::Color::Magenta);
                        }
                    }
                }
                if (offer.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    if (moneyOffer.getText() == "") {
                        currentPhase = GamePhase::trade_request;
                    } else if (std::stoi(moneyOffer.getText()) <= currentPlayer->money) {
                        currentPhase = GamePhase::trade_request;
                    }
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::trade_request)  {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (moneyRequest.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    moneyRequest.setFocus(true);
                }   else {
                    moneyRequest.setFocus(false);
                }

                for (int i = 0; i < 40; i++) {
                    if (squares[i].getPlayerNo() == otherPlayer->getPlayerNo() && squares[i].getNumHouses() == 0) {
                        if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                            squares[i].setPlayerNo(6);
                            squares[i].bought_circle.setOutlineColor(sf::Color::Cyan);
                        }
                    }
                }

                if (offer.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    if (moneyRequest.getText() == "") {
                        currentPhase = GamePhase::trade_accept;
                    } else if (std::stoi(moneyRequest.getText()) <= otherPlayer->money) {
                        currentPhase = GamePhase::trade_accept;
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::trade_accept) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (refuse.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) { //refuse? give back property
                    for (int i = 0; i < 40; i++) {
                        if (squares[i].getPlayerNo() == 5) {
                            if (currentTurn == PlayerTurn::player1_turn) {
                                squares[i].setPlayerNo(1);
                                squares[i].bought_circle.setOutlineColor(sf::Color::Red);
                            } else if (currentTurn == PlayerTurn::player2_turn) {
                                squares[i].setPlayerNo(2);
                                squares[i].bought_circle.setOutlineColor(sf::Color::Blue);
                            }
                        } else if (squares[i].getPlayerNo() == 6) {
                            if (currentTurn == PlayerTurn::player1_turn) {
                                squares[i].setPlayerNo(2);
                                squares[i].bought_circle.setOutlineColor(sf::Color::Blue);
                            } else if (currentTurn == PlayerTurn::player2_turn) {
                                squares[i].setPlayerNo(1);
                                squares[i].bought_circle.setOutlineColor(sf::Color::Red);
                            }
                        }
                    }
                    moneyOffer.clear();
                    moneyRequest.clear();
                    if (squares[currentPlayer->currentPos].getBuyable())currentPhase = GamePhase::is_buying_phase;
                    else currentPhase = GamePhase::isNot_buying_phase;
                } else if (accept.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) { //money exchange
                    if (moneyOffer.getText() != "") {
                        currentPlayer->update_money(0,std::stoi(moneyOffer.getText()));
                        otherPlayer->update_money(1,std::stoi(moneyOffer.getText()));
                    }
                    if (moneyRequest.getText() != "") {
                        currentPlayer->update_money(1,std::stoi(moneyRequest.getText()));
                        otherPlayer->update_money(0,std::stoi(moneyRequest.getText()));
                    }
                    for (int i = 0; i < 40; i++) {
                        if (squares[i].getPlayerNo() == 5) { //offer accepted (magenta)
                            if (currentTurn == PlayerTurn::player1_turn) {
                                squares[i].setPlayerNo(2);
                                squares[i].bought_circle.setOutlineColor(sf::Color::Blue);
                                P1.owned_properties[squares[i].getType()]--;
                                P2.owned_properties[squares[i].getType()]++;
                            } else if (currentTurn == PlayerTurn::player2_turn) {
                                squares[i].setPlayerNo(1);
                                squares[i].bought_circle.setOutlineColor(sf::Color::Red);
                                P2.owned_properties[squares[i].getType()]--;
                                P1.owned_properties[squares[i].getType()]++;
                            }
                        } else if (squares[i].getPlayerNo() == 6) { //request accepted (cyan)
                            if (currentTurn == PlayerTurn::player1_turn) {
                                squares[i].setPlayerNo(1);
                                squares[i].bought_circle.setOutlineColor(sf::Color::Red);
                                P1.owned_properties[squares[i].getType()]++;
                                P2.owned_properties[squares[i].getType()]--;
                            } else if (currentTurn == PlayerTurn::player2_turn) {
                                squares[i].setPlayerNo(2);
                                squares[i].bought_circle.setOutlineColor(sf::Color::Blue);
                                P2.owned_properties[squares[i].getType()]++;
                                P1.owned_properties[squares[i].getType()]--;
                            }
                        }
                    }
                    moneyOffer.clear();
                    moneyRequest.clear();
                    if (squares[currentPlayer->currentPos].getBuyable())currentPhase = GamePhase::is_buying_phase;
                    else currentPhase = GamePhase::isNot_buying_phase;
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::buy_houses) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (end_mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && returnToBuy) {
                    currentPhase = GamePhase::is_buying_phase;
                } else if (end_mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && !returnToBuy) {
                    currentPhase = GamePhase::isNot_buying_phase;
                } else {
                    for (int i = 0; i < 40; i++) {
                        if (currentPlayer->getPlayerNo() == squares[i].getPlayerNo()) {
                            if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                                if (currentPlayer->owned_properties[squares[i].getType()] == colorRequirements[squares[i].getType()]) {
                                    std::cout<<"fuck"<<std::endl;
                                    if (squares[i].getNumHouses() < 5) {
                                        currentPlayer->update_money(0, squares[i].getHousePrice());
                                        squares[i].incrementHouses();
                                        squares[i].houseText.setString(std::to_string(squares[i].getNumHouses()));
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //std::cout << squares[currentPlayer->currentPos].getPlayerNo() << std::endl;
        if (dice.roll_indices < dice.roll_result) {
            if (elapsed1.asMilliseconds() >= 100) {
                if (currentPlayer->currentPos == 39) { //making sure to loop back
                    currentPlayer->currentPos = 0;
                    currentPlayer->update_money(1,200);
                }
                else {
                    currentPlayer->currentPos++;
                }
                dice.roll_indices++;
                currentPlayer->shape.setPosition(currentPlayer->position_coordinates[currentPlayer->currentPos]);
                if (dice.roll_indices == dice.roll_result && !same_roll) { //this indicates the turn is over, when destination is reached
                    if (squares[currentPlayer->currentPos].getBuyable()) {
                        currentPhase = GamePhase::is_buying_phase;
                        returnToBuy = true;
                    }
                    else {
                        if (squares[currentPlayer->currentPos].getPlayerNo() != currentPlayer->getPlayerNo() && squares[currentPlayer->currentPos].bought_circle.getOutlineColor() != sf::Color::Yellow && squares[currentPlayer->currentPos].bought_circle.getOutlineColor() != sf::Color::Green) {
                            currentPlayer->update_money(0, squares[currentPlayer->currentPos].returnRent());
                            otherPlayer->update_money(1, squares[currentPlayer->currentPos].returnRent());
                        } 
                        if (currentPlayer->currentPos == 4) currentPlayer->update_money(0, 200);
                        else if (currentPlayer->currentPos == 38) currentPlayer->update_money(0, 100); //two fees
                        else if (currentPlayer->currentPos == 30) {
                            currentPlayer->inJail = true;
                            currentPhase = GamePhase::SendingtoJail;
                        }
                        if (currentPhase != GamePhase::SendingtoJail) currentPhase = GamePhase::isNot_buying_phase;
                        returnToBuy = false;
                    }
                }
                clock.restart();
            }
        } else if (currentPhase != GamePhase::SendingtoJail) { //same roll, roll again
            if (same_roll) {
                currentPhase = GamePhase::WaitForDice;
            }
            dice.roll_indices = 0;
            dice.roll_result = 0;
        }

        if (sameRollCount == 3) { //3 same rolls = jail
            currentPhase = GamePhase::SendingtoJail;
            currentPlayer->inJail = true;
            sameRollCount = 0;
            jail_notif.setText("3 SAME ROLLS! GO TO JAIL");
        }

        //std::cout << to_string(currentPhase) << " " << currentPlayer->inJail << same_roll << std::endl;
        if (currentPhase == GamePhase::SendingtoJail) {
            int jailer = currentPlayer->currentPos;
            if (elapsed1.asMilliseconds() >= 200) {
                if (currentPlayer->currentPos > 10) {
                    currentPlayer->currentPos--;
                    jailer--;
                } else if (currentPlayer->currentPos < 10) {
                    currentPlayer->currentPos++;
                    jailer++;
                } else {
                    pass;
                }
                currentPlayer->shape.setPosition(currentPlayer->position_coordinates[currentPlayer->currentPos]);
                if (jailer == 10) {
                    if (!(otherPlayer->inJail))  currentPhase = GamePhase::WaitForDice;
                    else currentPhase = GamePhase::inJail;
                    jail_notif.setText("GO TO JAIL");
                    if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                    jailer = otherPlayer->currentPos;
                    same_roll = false;
                }
                clock.restart(); 
            }
        }
        
        window.clear();
        window.draw(sprite); // Draw the scaled sprite of the game board
        if (same_roll) window.draw(same_roll_notif.content);
        if (currentPhase == GamePhase::is_buying_phase) {
            if (squares[currentPlayer->currentPos].getPrice() <= currentPlayer->money) window.draw(buying_phase.content);
            if (currentPlayer->money > 0) window.draw(auction_phase.content);
            if (currentPlayer->owned_all_of_color()) window.draw(buy_hotels.content);
            window.draw(mortgage.content);
            window.draw(remortgage.content);
            window.draw(trade.content);
            window.draw(forfeit.content);
        } else if (currentPhase == GamePhase::mortgaging || currentPhase == GamePhase::remortgaging || currentPhase == GamePhase::buy_houses) {
            window.draw(end_mortgage.content);
        } else if (currentPhase == GamePhase::isNot_buying_phase) {
            if (currentPlayer->owned_all_of_color()) window.draw(buy_hotels.content);
            window.draw(mortgage.content);
            window.draw(remortgage.content);
            window.draw(trade.content);
            window.draw(pass.content);
            window.draw(forfeit.content);
        }   else if (currentPhase == GamePhase::auctioning) {
            textBox.draw(window);
            window.draw(how_much.content);
            window.draw(auction_notes.content);
            window.draw(bid.content);
            if (!textBox.getText().empty() && firstBid) window.draw(GIVE.content);
            window.draw(biddingNoText.content);
            window.draw(auc_turn.content);
        }   else if (currentPhase == GamePhase::SendingtoJail) {
            window.draw(jail_notif.content);
        }   else if (currentPhase == GamePhase::inJail) {
            if (currentTurn == PlayerTurn::player1_turn) who_jail.setText("Player 1 in jail");
            else who_jail.setText("Player 2 in jail");
            window.draw(who_jail.content);
            window.draw(pay50.content);
            if (jailRollCount < 4) window.draw(roll_freedom.content);
            window.draw(jail_rolls.content);
        }   else if (currentPhase == GamePhase::trading) {
            moneyOffer.draw(window);
            window.draw(offer.content);
        }   else if (currentPhase == GamePhase::trade_request) {
            moneyRequest.draw(window);
            window.draw(request.content);
        }   else if (currentPhase == GamePhase::trade_accept) {
            window.draw(accept.content);
            window.draw(refuse.content);
        }   else if (currentPhase == GamePhase::game_decided) {
            if (currentTurn == PlayerTurn::player1_turn) game_decision.setText("PLAYER 2 WINS");
            else game_decision.setText("PLAYER 1 WINS");
            window.draw(game_decision.content);
        }
        if (currentPhase == GamePhase::RollingDice) window.draw(dice.dice_info);
        for (int i = 0; i < 40; i++) {
            if (squares[i].getPlayerNo() == 1) squares[i].bought_circle.setOutlineColor(sf::Color::Red);
            if (squares[i].getPlayerNo() == 2) squares[i].bought_circle.setOutlineColor(sf::Color::Blue);
            if (!squares[i].getBuyable()) window.draw(squares[i].bought_circle);
            if (squares[i].getNumHouses() > 0)window.draw(squares[i].houseText);
        }
        window.draw(P1.shape);
        window.draw(P2.shape);
        window.draw(dice.shape);
        window.draw(P1.money_text);
        window.draw(P2.money_text);
        window.display();
    }

    return 0;
}
