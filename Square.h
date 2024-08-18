#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>

class Square {
    public:
        Square(const unsigned int num, const unsigned int price);
        unsigned int getNum() const;
        unsigned int getPrice() const;
        bool owned;
        int houses;

    private:
        unsigned int num;
        unsigned int price;

};

#endif