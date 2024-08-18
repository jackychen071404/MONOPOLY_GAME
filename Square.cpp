#include "Square.h"

Square::Square(const unsigned int num, const unsigned int price, const std::string &type, const unsigned int player_no) 
    : num(num), houses(0), price(price), owned(0), type(type), player_no(0)
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

unsigned int Square::getPlayerNo() const {
    return player_no;
}