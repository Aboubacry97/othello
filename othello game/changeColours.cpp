
#include "changeColours.h"
changeColours::changeColours(const char* initialDots, char Playing, char Waiting,int played) {
    playedposition = played;
    Play = Playing;
    Wait = Waiting;
    for (int i = 0; i < 64; i++) {
        pieces[i] = initialDots[i];
    }
}


void changeColours::ColChangeAlldir(int iterationNumber) {
        int startPos = -1;
        int endPos = -1;

        // Check to the right
        for (int j = playedposition + iterationNumber; j % 8 < 8; j += iterationNumber) {
            if (pieces[j] == Wait) {
                if (startPos == -1) {
                    startPos = j;
                }
            } else if (pieces[j] == Play) {
                if (startPos != -1) {
                    endPos = j;
                    break;
                }
            } else {
                break;
            }
        }

        // Update pieces to the right
        if (startPos != -1 && endPos != -1) {
            for (int p = startPos; p < endPos; p += iterationNumber) {
                pieces[p] = Play;
            }
        }

        // Check to the left
        startPos = -1;
        endPos = -1;

        for (int j = playedposition - iterationNumber; j % 8 >= 0; j -= iterationNumber) {
            if (pieces[j] == Wait) {
                if (startPos == -1) {
                    startPos = j;
                }
            } else if (pieces[j] == Play) {
                if (startPos != -1) {
                    endPos = j;
                    break;
                }
            } else {
                break;
            }
        }

        // Update pieces to the left
        if (startPos != -1 && endPos != -1) {
            for (int p = startPos; p > endPos; p -= iterationNumber) {
                pieces[p] = Play;
            }
        }
    }




