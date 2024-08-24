#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <string>
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
    bool returnToBuy = false;
    bool same_roll = false;
    int biddingNo = 0;
    int previousBiddingNo = 0;

    //various game messages
    Text same_roll_notif(font, "Same numbers! Roll again.", sf::Color::Black, 48, sf::Vector2f(250.f,250.f));
    Text buying_phase(font, "BUY?", sf::Color::Black, 48, sf::Vector2f(250.f,350.f));
    Text auction_phase(font, "AUCTION?", sf::Color::Black, 48, sf::Vector2f(600.f,350.f));
    Text forfeit(font, "FORFEIT?", sf::Color::Black, 48, sf::Vector2f(300.f,700.f));
    Text remortgage(font, "REMORTGAGE?", sf::Color::Black, 48, sf::Vector2f(500.f,600.f));
    Text mortgage(font, "MORTGAGE?", sf::Color::Black, 48, sf::Vector2f(500.f,700.f));
    Text end_mortgage(font, "END", sf::Color::Black, 48, sf::Vector2f(700.f,700.f));
    Text pass(font, "PASS", sf::Color::Black, 48, sf::Vector2f(700.f,800.f));
    Text jail_notif(font, "GO TO JAIL.", sf::Color::Black, 48, sf::Vector2f(250.f,350.f));
    Text p1_notif(font, "+$", sf::Color::Black, 48, sf::Vector2f(600,750));
    Text p2_notif(font, "+$", sf::Color::Black, 48, sf::Vector2f(600,800));
    TextBox textBox(350, 600, 300, 50, font);
    Text auction_notes(font, "Enter bid.", sf::Color::Black, 48, sf::Vector2f(350.f, 500.f));
    Text how_much(font, "HOW MUCH?", sf::Color::Black, 48, sf::Vector2f(350.f, 300.f));
    Text bid(font, "BID!", sf::Color::Black, 48, sf::Vector2f(150.f, 700.f));
    Text GIVE(font, "GIVE UP!", sf::Color::Black, 48, sf::Vector2f(700.f, 700.f));
    Text biddingNoText(font, "Previous bid: 0", sf::Color::Black, 48, sf::Vector2f(120.f, 120.f));
    Text auc_turn(font, "Auction Turn: ", sf::Color::Black, 48, sf::Vector2f(650.f, 120.f));

    GamePhase currentPhase = GamePhase::WaitForDice;
    PlayerTurn currentTurn = PlayerTurn::player1_turn;
    AuctionTurn auctionTurn = AuctionTurn::player1_turn;
    bool firstAuction = true;
    bool firstBid = false;
    Player* currentPlayer;
    Player* otherPlayer;

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
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if (currentPhase == GamePhase::auctioning) {
                if (textBox.getFocus()) textBox.handleEvent(event);
            }

            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::WaitForDice)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (dice.shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                {
                    currentPhase = GamePhase::RollingDice;
                    dice.die1 = dis(gen);
                    dice.die2 = dis(gen);
                    dice.roll_result = dice.die1+dice.die2;
                    dice.roll_display = dice.roll_result;
                    same_roll = dice.die1==dice.die2;

                    if (currentTurn == PlayerTurn::player1_turn) dice.dice_info.setString("Player " + std::to_string(1) + ": " + std::to_string(dice.die1) + " and " + std::to_string(dice.die2));
                    else dice.dice_info.setString("Player " + std::to_string(2) + ": " + std::to_string(dice.die1) + " and " + std::to_string(dice.die2));
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPhase == GamePhase::is_buying_phase) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (buying_phase.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPlayer->update_money(0,squares[currentPlayer->currentPos].getPrice());
                    squares[currentPlayer->currentPos].setPlayerNo(currentPlayer->getPlayerNo());
                    squares[currentPlayer->currentPos].setBuyable(0);
                    if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                    currentPhase = GamePhase::WaitForDice;
                }   else if (mortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPhase = GamePhase::mortgaging;
                }   else if (remortgage.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPhase = GamePhase::remortgaging;
                }   else if (auction_phase.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    currentPhase = GamePhase::auctioning;
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
                            if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                                if (currentTurn == PlayerTurn::player1_turn) {
                                    squares[i].setPlayerNo(3);
                                    squares[i].bought_circle.setOutlineColor(sf::Color::Green);
                                } else {
                                    squares[i].setPlayerNo(4); 
                                    squares[i].bought_circle.setOutlineColor(sf::Color::Yellow); //mortgaged
                                }
                                currentPlayer->update_money(1, squares[i].getPrice() * .5);
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
                                if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                                    currentPlayer->update_money(0, squares[i].getPrice() * .5 * 1.1);
                                    squares[i].bought_circle.setOutlineColor(sf::Color::Red);
                                    squares[i].setPlayerNo(1);
                                }
                            }
                        } else {
                            if (squares[i].getPlayerNo() == 4) {
                                if (squares[i].bought_circle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                                    currentPlayer->update_money(0, squares[i].getPrice() * .5 * 1.1);
                                    squares[i].bought_circle.setOutlineColor(sf::Color::Blue);
                                    squares[i].setPlayerNo(2);
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
                } else if (pass.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                    currentPhase = GamePhase::WaitForDice;
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

                if (GIVE.getBounds().contains(static_cast<sf::Vector2f>(mousePos)) && !textBox.getText().empty()) {
                    if (currentTurn == PlayerTurn::player1_turn) currentTurn = PlayerTurn::player2_turn;
                    else if (currentTurn == PlayerTurn::player2_turn) currentTurn = PlayerTurn::player1_turn;
                    if (auctionTurn == AuctionTurn::player1_turn)  {
                        P2.update_money(0, biddingNo);
                        squares[currentPlayer->currentPos].setPlayerNo(P2.getPlayerNo());
                        squares[currentPlayer->currentPos].setBuyable(0);
                    } else if (auctionTurn == AuctionTurn::player2_turn) {
                        P1.update_money(0, biddingNo);
                        squares[currentPlayer->currentPos].setPlayerNo(P1.getPlayerNo());
                        squares[currentPlayer->currentPos].setBuyable(0);
                    }
                    biddingNo = 0;
                    previousBiddingNo = 0;
                    currentPhase = GamePhase::WaitForDice;
                    firstAuction = true;
                    //reset auction values
                } else if (bid.getBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    firstBid = true;
                    biddingNo = std::stoi(textBox.getText());
                    if (biddingNo < 1) auction_notes.setText("Enter value higher than 1!");
                    else if (biddingNo <= previousBiddingNo) auction_notes.setText("Set value higher than previous bid!");
                    else {
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
        }

        //std::cout << squares[currentPlayer->currentPos].getPlayerNo() << std::endl;
        sf::Time elapsed1 = clock.getElapsedTime();
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
                            currentPlayer->update_money(0, squares[currentPlayer->currentPos].getRent0());
                            otherPlayer->update_money(1, squares[currentPlayer->currentPos].getRent0());
                        } 
                        if (currentPlayer->currentPos == 4) currentPlayer->update_money(0, 200);
                        else if (currentPlayer->currentPos == 38) currentPlayer->update_money(0, 100); //two fees
                        currentPhase = GamePhase::isNot_buying_phase;
                        returnToBuy = false;
                    }
                }
                clock.restart();
            }
        } else {
            if (same_roll) currentPhase = GamePhase::WaitForDice;
            dice.roll_indices = 0;
            dice.roll_result = 0;
        }
        std::cout << to_string(auctionTurn) << std::endl;

        window.clear();
        window.draw(sprite); // Draw the scaled sprite of the game board
        if (same_roll) window.draw(same_roll_notif.content);
        if (currentPhase == GamePhase::is_buying_phase) {
            window.draw(buying_phase.content);
            window.draw(auction_phase.content);
            window.draw(mortgage.content);
            window.draw(remortgage.content);
        } else if (currentPhase == GamePhase::mortgaging || currentPhase == GamePhase::remortgaging) {
            window.draw(end_mortgage.content);
        } else if (currentPhase == GamePhase::isNot_buying_phase) {
            window.draw(mortgage.content);
            window.draw(remortgage.content);
            window.draw(pass.content);
        } else if (currentPhase == GamePhase::auctioning) {
            textBox.draw(window);
            window.draw(how_much.content);
            window.draw(auction_notes.content);
            window.draw(bid.content);
            if (!textBox.getText().empty() && firstBid) window.draw(GIVE.content);
            window.draw(biddingNoText.content);
            window.draw(auc_turn.content);
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
