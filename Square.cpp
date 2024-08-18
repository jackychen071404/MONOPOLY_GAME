#include "Square.h"

Square::Square(const unsigned int num, const unsigned int price) 
    : num(num), houses(0), price(price), owned(0)
{

}

unsigned int Square::getNum() const {
    return num;
}

unsigned int Square::getPrice() const {
    return price;
}