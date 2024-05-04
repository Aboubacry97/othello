#include <iostream>
#include "Board.h"

#ifndef OTHELLO_CHANGECOLOURS_H
#define OTHELLO_CHANGECOLOURS_H


class changeColours: public Board {
public:
    changeColours(const char* initialDots, char Play, char Wait,int played);
    void ColChangeAlldir(int iterationNumber);
    std::array<int, 64> changeablePositions;
private:
    char Play;
    char Wait;
};


#endif //OTHELLO_CHANGECOLOURS_H
