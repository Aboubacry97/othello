#ifndef OTHELLO_POSITION_H
#define OTHELLO_POSITION_H

#include <iostream>
#include <array>

class Position {
public:
    Position();
    ~Position();
    void emptyPositions(const char* initialDots);
    std::array<int, 64>* empty;
    std::array<int, 64>* getEmpty();
private:
    char* dots1;
};


#endif //OTHELLO_POSITION_H
