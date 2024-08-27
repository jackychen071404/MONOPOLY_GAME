#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>

class Square {
    public:
        Square(const unsigned int num, const unsigned int price, const unsigned int house_price, const unsigned int rent0, const unsigned int rent1, const unsigned int rent2, const unsigned int rent3, const unsigned int rent4, const unsigned int rent5, 
        const std::string &type, bool buyable, unsigned int player_no, sf::Vector2f circlePosition, const int num_houses);
        unsigned int getNum() const;
        unsigned int getPrice() const;
        unsigned int getHousePrice() const;
        unsigned int getRent0() const;
        unsigned int getRent1() const;
        unsigned int getRent2() const;
        unsigned int getRent3() const;
        unsigned int getRent4() const;
        unsigned int getRent5() const;
        std::string getType() const;
        int getNumHouses() const;
        void incrementHouses();
        unsigned int returnRent();
        bool getBuyable() const;
        void setBuyable(bool truth);
        unsigned int getPlayerNo() const;
        void setPlayerNo(unsigned int new_no);
        bool owned;
        int houses;
        sf::CircleShape bought_circle;

    private:
        unsigned int num;
        unsigned int price;
        unsigned int housePrice;
        unsigned int rent0;
        unsigned int rent1;
        unsigned int rent2;
        unsigned int rent3;
        unsigned int rent4;
        unsigned int rent5;
        std::string type;
        unsigned int player_no;
        bool buyable;
        int numHouses;

};

#endif