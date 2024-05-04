#include <iostream>
#include "Game.h"

void Game::start(std::string& menuOption) {
    using namespace std;
    do {
    string load = "1. Load a Game";
    string quit = "2. Quit";
    string start = "3. Start a New Game";
    cout<<load<<endl<<quit<<endl<<start<<endl;
    cout<<"Choose an option: ";
    cin>>menuOption;}
    while ((menuOption != "1") && (menuOption != "2") && (menuOption != "3"));
}


void Game::game(std::string& player1,std::string& player2) {
    std::cout<<"Choose a name for Player1: ";
    std::cin>>player1;

    std::cout<<"Choose a name for Player2: ";
    std::cin>>player2;
}