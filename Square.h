#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>

class Square {
    public:
        Square(const unsigned int num, const unsigned int price, const std::string &type, const bool buyable, const unsigned int player_no);
        unsigned int getNum() const;
        unsigned int getPrice() const;
        std::string getType() const;
        bool getBuyable() const;
        unsigned int getPlayerNo() const;
        bool owned;
        int houses;

    private:
        unsigned int num;
        unsigned int price;
        std::string type;
        unsigned int player_no;
        bool buyable;

};

#endif