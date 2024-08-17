#include <iostream>
#include <random>
#include <cstdlib>

int main() {
    int die1;
    int die2;
    int roll_result;

    std::random_device rd;
    std::mt19937 gen(rd()); //mt19937 is a cpp thing that mersenne twister
    std::uniform_int_distribution<> dis(1, 6);

    int twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, sevens = 0, eights = 0, nines = 0, tens = 0, elevens = 0, twelves = 0;

    for (int i = 0; i < 100000; i++) {
        die1 = dis(gen);
        die2 = dis(gen);
        roll_result = die1+die2;
        switch(roll_result) {
            case 2:twos++;break;
            case 3:threes++;break;
            case 4:fours++;break;
            case 5:fives++;break;
            case 6:sixes++;break;
            case 7:sevens++;break;
            case 8:eights++;break;
            case 9:nines++;break;
            case 10:tens++;break;
            case 11:elevens++;break;
            case 12:twelves++;break;
        }
    }

    std::cout << "2: " << twos << std::endl;
    std::cout << "3: " << threes << std::endl;
    std::cout << "4: " << fours << std::endl;
    std::cout << "5: " << fives << std::endl;
    std::cout << "6: " << sixes << std::endl;
    std::cout << "7: " << sevens << std::endl;
    std::cout << "8: " << eights << std::endl;
    std::cout << "9: " << nines << std::endl;
    std::cout << "10: " << tens << std::endl;
    std::cout << "11: " << elevens << std::endl;
    std::cout << "12: " << twelves << std::endl;
}