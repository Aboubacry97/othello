#include <iostream>
#include "Position.h"

    void Position::emptyPositions(const char* initialDots) {
        for (int i = 0; i < 64; i++) {
            dots1[i] = initialDots[i];
        }
        for (int i = 0; i < 64; i++) {
            if (dots1[i] == '.') {
                (*empty)[i] = i;
        }}
    /*for (int i = 0; i < 64; i++) {
        std::cout << (*empty)[i]<<std::endl;
        if( (*white)[i] != 0)
            std::cout <<"       "<< (*white)[i]<<std::endl;
        if( (*black)[i] != 0)
            std::cout <<"       "<< (*black)[i]<<std::endl;
    }*/
}
std::array<int, 64>* Position::getEmpty() {
    return empty;
}


Position::Position() {
    empty = new std::array<int,64>();
    dots1 = new char[64];
}

// Destructor
Position::~Position() {
    delete empty;

}