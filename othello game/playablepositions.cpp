
#include "playablepositions.h"

std::array<int, 64>* playablepositions::getplayable() {
    return hplayable;
}
void playablepositions::setcolours(char a, char b) {
    Play = a;
    Wait = b;
}

bool playablepositions::checkPlayableposition(){
    bool canPlay;
    for (int i = 0; i < 64; i++) {
        if( (*hplayable)[i] != 0){
        canPlay = 1;}
    }
return canPlay;}



playablepositions::playablepositions(const char* initialDots, std::array<int, 64>* initialEmpty) {
    dots1 = new char[64];
    for (int i = 0; i < 64; i++) {
        dots1[i] = initialDots[i];
    }
    empty = initialEmpty;
    hplayable = new std::array<int, 64>();
}

void playablepositions::playPosAlldir(int iterationNumber) {
    for (int i = 0; i < 64; i++) {
        int row = i / 8;

        if (dots1[i] == Play) {
            int j = i + iterationNumber;
            while (j % 8 < 8) {
                if (j >= 0 && j < 64) {
                    if (dots1[j] == Wait) {
                        if (j % 8 < 7 && j + iterationNumber >= 0 && j + iterationNumber < 64 && dots1[j + iterationNumber] == '.') {
                            (*hplayable)[j + iterationNumber] = (*empty)[j + iterationNumber];
                        }
                    }
                    if (dots1[j] == '.') {
                        break;
                    }
                    j = j + iterationNumber;
                } else {
                    break;
                }
            }

            j = i - iterationNumber;
            while (j % 8 >= 0) {
                if (j >= 0 && j < 64) {
                    if (dots1[j] == Wait) {
                        if (j % 8 > 0 && j - iterationNumber >= 0 && j - iterationNumber < 64 && dots1[j - iterationNumber] == '.') {
                            (*hplayable)[j - iterationNumber] = (*empty)[j - iterationNumber];
                        }
                    }
                    if (dots1[j] == '.') {
                        break;
                    }
                    j = j - iterationNumber;
                } else {
                    break;
                }
            }
        }
    }
}



