#include <iostream>
#ifndef OTHELLO_BOARD_H
#define OTHELLO_BOARD_H
#include <array>
#include "Position.h"
class Board: public Position{
public:
    Board();
    void setNames(std::string firstplayer,std::string secondplayer);
    void initializeBoard();
    void FourbyFour();
    void drawBoard();
    void offsetBoard(int a,int b, int c, int d);
    void play(std:: string& move, bool& checkEnd);
    int makeAMove(char Play);
    void takeTurn(std::string player1,std::string player2,std::string &playerTurn,char &Play,char &Wait);
    void setplayable(std::array<int, 64>* playablepos);
    char* getDots() const;
    void setDots(const char* newDots);
    std::array<int, 64>* board_playableposition;
    void showplayable();
    char* pieces;
    void checkForWin(std::string player1,std::string player2);
    void play2(std:: string& noMove);
    int playedposition;
    void save(std::string &playerTurn,std::string player1,std::string player2);
    void load(std::string &playerTurn,std::string &player1,std::string &player2);

private:
    int signal;
    int conversion;
    char number;
    char letter;
    std::string player1;
    std::string player2;
    bool exists;
    int black;
    int white;
};


#endif //OTHELLO_BOARD_H

