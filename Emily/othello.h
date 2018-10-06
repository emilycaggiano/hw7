//Othello class header
//Emily Caggiano. CS2401, Project 6(game)

#include<iostream>
#include<string>
#include "space.h"
#include "colors.h"
#include "game.h"

namespace main_savitch_14{

class Othello:public game{
   public:
	Othello();
	void restart();
	void display_status()const;	
	bool is_legal(const string& move)const;
	void make_move(const string& move);
	game::who winning()const;
	game*clone()const;
	void compute_moves(std::queue<std::string>&moves)const;
	int evaluate()const;
	bool is_game_over()const;
  private:
	Space board[8][8];
  };
}

