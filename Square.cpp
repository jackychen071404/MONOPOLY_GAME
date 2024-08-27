#include "Square.h"

Square::Square(const unsigned int num, const unsigned int price,  const unsigned int house_price, const unsigned int rent0, const unsigned int rent1, const unsigned int rent2, const unsigned int rent3, const unsigned int rent4, const unsigned int rent5, const std::string &type, bool buyable, unsigned int player_no, sf::Vector2f circlePosition, const int num_houses) 
    : num(num), houses(0), price(price), housePrice(house_price), rent0(rent0), rent1(rent1), rent2(rent2), rent3(rent3), rent4(rent4), rent5(rent5), owned(0), type(type), buyable(buyable), player_no(0), numHouses(num_houses)
{
    bought_circle.setRadius(30);
    bought_circle.setPosition(circlePosition);
    bought_circle.setFillColor(sf::Color::Transparent);
    bought_circle.setOutlineColor(sf::Color::Transparent);
    bought_circle.setOutlineThickness(2.f);
}

unsigned int Square::getNum() const {
    return num;
}

unsigned int Square::getPrice() const {
    return price;
}

unsigned int Square::getHousePrice() const {
    return housePrice;
}

unsigned int Square::getRent0() const {
    return rent0;
}

unsigned int Square::getRent1() const {
    return rent1;
}
unsigned int Square::getRent2() const {
    return rent2;
}
unsigned int Square::getRent3() const {
    return rent3;
}
unsigned int Square::getRent4() const {
    return rent4;
}
unsigned int Square::getRent5() const {
    return rent5;
}

std::string Square::getType() const {
    return type;
}

bool Square::getBuyable() const {
    return buyable;
}

void Square::setBuyable(bool truth) {
    buyable = truth;
}

unsigned int Square::getPlayerNo() const {
    return player_no;
}

void Square::setPlayerNo(unsigned int new_no) {
    player_no = new_no;
}

int Square::getNumHouses() const {
    return numHouses;
}

void Square::incrementHouses() {
    numHouses++;
}

unsigned int Square::returnRent() {
    switch (numHouses) {
        case 0: return rent0;
        case 1: return rent1;
        case 2: return rent2;
        case 3: return rent3;
        case 4: return rent4;
        case 5: return rent5;
        default: return rent0;
    }
}