/***************************
	Jennifer Sroka
	CS2401 Project 6a
	*********************/
#include "game.h"
using namespace main_savitch_14;


class Mancala : public game
{
	public:
		Mancala();
		bool is_legal(const std::string& move)const;
		void make_move(const std::string& move);
		void display_status()const;
		void compute_moves(std::queue<std::string>& moves) const;
		game* clone( ) const;
		bool is_game_over( ) const;
		int evaluate( ) const;
		void restart( );
		game::who winning() const; 

	private: 
		int board[14]; 


};