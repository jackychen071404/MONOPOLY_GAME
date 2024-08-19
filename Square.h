#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>

class Square {
    public:
        Square(const unsigned int num, const unsigned int price, const std::string &type, bool buyable, unsigned int player_no);
        unsigned int getNum() const;
        unsigned int getPrice() const;
        std::string getType() const;
        bool getBuyable() const;
        void setBuyable(bool truth);
        unsigned int getPlayerNo() const;
        void setPlayerNo(unsigned int new_no);
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