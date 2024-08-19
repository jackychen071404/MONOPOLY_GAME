#include "Square.h"

Square::Square(const unsigned int num, const unsigned int price,  const std::string &type, bool buyable, unsigned int player_no) 
    : num(num), houses(0), price(price), owned(0), type(type), buyable(buyable), player_no(0)
{

}

unsigned int Square::getNum() const {
    return num;
}

unsigned int Square::getPrice() const {
    return price;
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