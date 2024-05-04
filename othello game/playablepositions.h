
#ifndef OTHELLO_PLAYABLEPOSITIONS_H
#define OTHELLO_PLAYABLEPOSITIONS_H
#include <iostream>
#include <array>
class playablepositions{

public:
    playablepositions(const char* initialDots, std::array<int, 64>* initialEmpty);// Declaration of the constructor
    char* dots1;
    std::array<int, 64>* empty;
    std::array<int, 64>* hplayable;
    void playPosAlldir(int iterationNumber);
    bool checkPlayableposition();
    std::array<int, 64>* getplayable();
    void setcolours(char a, char b);
private:
    char Play;
    char Wait;
};

#endif //OTHELLO_PLAYABLEPOSITIONS_H
