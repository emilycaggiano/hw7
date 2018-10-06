//main to play othello against opponent
//Emily Caggiano. CS2401, Project 6(game)

#include<iostream>
#include<queue>
#include<string>
#include<cstdlib>
#include "space.h"
#include "othello.h"

using namespace main_savitch_14;

int main(){

game::who winner;
Othello mygame;
winner == mygame.play();
if(winner == game:: HUMAN)
	cout << "You win!\n";
else if(winner == game::COMPUTER)
	cout << "The computer wins, you lose!\n";
else
	cout << "Tie game!\n";

return 0;

}

