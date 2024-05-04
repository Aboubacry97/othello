#include <iostream>
#include "Board.h"
#include <fstream>
Board::Board() : Position(){
    pieces = new char[64];
}
void Board:: setNames(std::string firstplayer,std::string secondplayer){
    player1 = firstplayer;
    player2 = secondplayer;}




void Board::play2(std:: string& noMove) {
    do{ std::cout<<"Play"<<std::endl<<"1. concede the game"<<std::endl<<"2. save"<<std::endl<<"3. forfeit your turn"<<std::endl<<"select an option:";
        std::cin>>noMove;}
    while ((noMove != "1") && (noMove != "2") && (noMove != "3") );
}

void Board::checkForWin(std::string player1,std::string player2){
    black = 0;
    white = 0;
    for (int i = 0; i < 64; i++) {
        if (pieces[i] == 'B'){
            black++;}
        else if(pieces[i] == 'W'){
            white++;}
        else{}}
        std::cout<<player1<<": "<<black<<" pieces"<<std::endl;
        std::cout<<player2<<": "<<white<<" pieces"<<std::endl;
     if (black > white){
        std::cout<<player1<< " has won the game"<<std::endl;}
        else if (black < white){
            std::cout<<player2<< " has won the game"<<std::endl;}
        else{ std::cout<< " It's a tied game"<<std::endl; }
}


char* Board::getDots() const {
    return pieces;
}
void Board::setDots(const char* initialDots) {
    for (int i = 0; i < 64; i++) {
        pieces[i] = initialDots[i];
        if (pieces[i] == 'o'){
            pieces[i] = '.';
        }
    }
}

void Board::takeTurn(std::string player1,std::string player2,std::string &playerTurn,char &Play,char &Wait) {
if (playerTurn == player1){
    playerTurn = player2; Play = 'W'; Wait = 'B';}
else{playerTurn = player1; Play = 'B'; Wait = 'W';}
std::cout<<"It is " <<playerTurn<<"'s turn"<<std::endl;
}

void Board::initializeBoard() {
    using namespace std;
    int k=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            pieces[k]='.';
            k++;}
    }
    pieces[0] = 'x'; pieces[7] = 'x'; pieces[56] = 'x'; pieces[63] = 'x';
}

void Board::drawBoard(){
    using namespace std;
    int k=0;
    cout<<"  A B C D E F G H"<<endl;
    cout<<"1 ";
    for(int i=2;i<10;i++){
        for(int j=0;j<8;j++){
            cout<<pieces[k]<<" ";
            k++;}
        cout<<endl;
        if(i<9){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void Board::offsetBoard(int a,int b, int c, int d) {

    pieces[a]= 'W'; pieces[b]= 'B'; pieces[c]= 'B'; pieces[d]= 'W';

}
void Board::FourbyFour() {
    using namespace std;
    std::array<int, 16> color = {18,19,26,27,36,37,44,45,34,35,42,43,20,21,28,29};
    for (int i=0;i<8;i++){
        pieces[color[i]]= 'W';
    }
    for (int i=8;i<16;i++){
        pieces[color[i]]= 'B';
    }

}


void Board::play(std:: string& move, bool& checkEnd) {
    using namespace std;
    checkEnd = 0;
    for (int i = 0; i < 64; i++) {
        if (pieces[i] == '.'){
            checkEnd = 1;
        }}
    if(checkEnd != 0){
    do{ std::cout<<"Play"<<std::endl<<"1. make a move"<<std::endl<<"2. save"<<std::endl<<"3. concede"<<std::endl<<"select an option:";
        std::cin>>move;}
    while ((move != "1") && (move != "2") &&(move != "3") );}
}

int Board::makeAMove(char Play) {
    signal= 0;
    conversion = 8;
   do {
       using namespace std;
       cout << "Select a valid move: ";
       cin >> letter >> number;
       playedposition = (int(letter) - 65) + conversion * (int(number) - 49);
       cout << playedposition << endl;
       if ((playedposition >= 0) && (playedposition < 64)) {
           for (int i = 0; i < 64; i++) {
               if (pieces[i] == 'o') {
                   if (i == playedposition) {
                       signal = 1;
                   }
               }
           }
       }

   } while(signal == 0);
    pieces[playedposition] = Play;
   return playedposition;
}




void Board::setplayable(std::array<int, 64>* playablepos) {
    board_playableposition = playablepos;}

void Board::showplayable(){
    for (int i = 0; i < 64; i++) {
        if ((*board_playableposition)[i] != 0) {
            pieces[(*board_playableposition)[i]] = 'o';
        }
    }
}

void Board::load(std::string &playerTurn,std::string &player1,std::string &player2){
    exists = true;
    while(exists){
    std::cout << "Choose the name of the file you want to load:" << std::endl;
    std::string file;
    std::cin >> file;
    std::fstream fs;
    fs.open (file, std::fstream::in);
    fs >> player1;
    fs >> player2;
    fs >> playerTurn;
    int k = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            fs >> pieces[k];
            k++;}
    }
    fs.close();
    if (playerTurn == player1){
        playerTurn = player2;}
    else {playerTurn = player1;}
    if(!player1.empty()){
        exists = false;
    }}
}
void Board::save(std::string &playerTurn,std::string player1,std::string player2){

    std::cout << "Choose a name for the file:" << std::endl;
    std::string file;
    std::cin >> file;
    std::fstream fs;
    fs.open (file, std::fstream::out);
    fs << player1 << std::endl;
    fs << player2 << std::endl;
    fs << playerTurn << std::endl;
    int k = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            fs << pieces[k];
            k++;}
        fs <<std::endl;
    }
    fs.close();
}
