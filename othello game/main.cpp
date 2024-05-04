#include <iostream>
#include <string>
#include "Game.h"
#include "Board.h"
#include "Position.h"
#include "changeColours.h"
#include "playablepositions.h"

std::string player1;
std::string player2;
std::string playerTurn;
char Play = '0';
char Wait = '0';
int main() {
    while (true){
    Game *menu = new Game;
    Board *board = new Board;
    std::string menuOption;
        menu->start(menuOption);
   if (menuOption == "1") {
      board->load(playerTurn,player1,player2);
  }else if (menuOption == "2"){
      return 0;}
          else {menu->game(player1,player2);
       board->setNames(player1,player2);
       board->initializeBoard();
  std::cout<<"1.1) A non-standard, offset starting position"<<std::endl;
       board->offsetBoard(18,19,26,27);
       board->drawBoard();
       board->initializeBoard();
  std::cout<<"1.2) A non-standard, offset starting position"<<std::endl;
       board->offsetBoard(20,21,28,29);
       board->drawBoard();
       board->initializeBoard();
  std::cout<<"1.3) A non-standard, offset starting position"<<std::endl;
       board->offsetBoard(34,35,42,43);
       board->drawBoard();
       board->initializeBoard();
  std::cout<<"1.4) A non-standard, offset starting position"<<std::endl;
       board->offsetBoard(36,37,44,45);
       board->drawBoard();
       board->initializeBoard();
       std::cout<<"2) Four-by-Four starting position"<<std::endl;
       board->FourbyFour();
       board->drawBoard();
       board->initializeBoard();
  std::string choice1;
  do{
      std::cout<<"1. Choose an offset starting position or 2. Four-by-Four starting position: ";
      std::cin>>choice1;}
  while ((choice1 != "1") && (choice1 != "2"));
  std::string choice2;
  if(choice1=="1") {
      do {
          std::cout<<"1.Choose an non-standart offset starting position between 1-4: ";
          std::cin >> choice2;
      } while ((choice2 != "1") && (choice2 != "2") && (choice2 != "3") && (choice2 != "4"));
      if(choice2 == "1"){board->offsetBoard(18,19,26,27);}
      else if(choice2=="2"){board->offsetBoard(20,21,28,29);}
      else if(choice2=="3"){board->offsetBoard(34,35,42,43);}
      else{board->offsetBoard(36,37,44,45);}
  }else {board->FourbyFour();}
       board->drawBoard();
       playerTurn = player2;}
    const char *boardDots;
    boardDots = board->getDots();
    delete menu;
    delete board;

    while(true) {
        Board *playingBoard = new Board;
        playingBoard->setDots(boardDots);
        bool checkEnd = 0;
        std::string move;
        playingBoard->play(move,checkEnd);
        if (checkEnd == 0){
            playingBoard->checkForWin(player1,player2);
            break;
        }
        playingBoard->takeTurn(player1, player2, playerTurn, Play, Wait);
        if (move == "1") {
            boardDots = playingBoard->getDots();
            playingBoard->emptyPositions(boardDots);
            std::array<int, 64> *emptypositions = playingBoard->getEmpty();
            playablepositions *playable = new playablepositions(boardDots, emptypositions);
            playable->setcolours(Play, Wait);
            playable->playPosAlldir(1);
            playable->playPosAlldir(8);
            playable->playPosAlldir(9);
            bool canPlay = playable->checkPlayableposition();
            if (canPlay == 1){
            std::array<int, 64> *playableposition = playable->getplayable();
            delete playable;
                playingBoard->setplayable(playableposition);
                playingBoard->showplayable();
                playingBoard->drawBoard();
            std::cout << "Select the row number followed by the column letter" << std::endl;
            int played = playingBoard->makeAMove(Play);
            boardDots = playingBoard->getDots();
            changeColours *colour = new changeColours(boardDots, Play, Wait,played);
            colour->ColChangeAlldir(1);
            colour->ColChangeAlldir(8);
            colour->ColChangeAlldir(9);
            colour->ColChangeAlldir(7);
            boardDots = colour->getDots();
            delete colour;
            playingBoard->setDots(boardDots);
            playingBoard->drawBoard();}
            else{
                std::string noMove;
                playingBoard->play2(noMove);
                if (noMove == "1"){
                std:: cout<<playerTurn<<"has lost the game"<<std::endl;
                break;}
                else if (noMove == "2"){
                playingBoard->save(playerTurn,player1,player2);
                break;
                }
                else{}
            }
            }
        else if (move == "2") {
              playingBoard->save(playerTurn,player1,player2);
              break;
        } else {std:: cout<<playerTurn<<"has lost the game"<<std::endl;
            break;}
        delete playingBoard;
    }}
         return 0;
}
