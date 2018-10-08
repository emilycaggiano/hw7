/****************************
	Jennifer Sroka
	CS2401 Project 6a
	*********************/
#include "mancala.h"
#include <iostream>
#include <cstdlib>


Mancala::Mancala()
{
	for(int i = 0; i < 14; i++)
	{
		if(i==0)
		{
			board[i] = 0; 
		}
		else if(i==7)
		{
			board[i] = 0; 
		}
		else
		{
			board[i] = 4;
		}
	}
}

bool Mancala::is_legal(const std::string& move)const
{ 
	int x; 
	if(next_mover()==COMPUTER)
	{
		if(move == "G" || move == "g")
		{
			return false; 
		}
		if(move == "H" || move == "h")
		{
			return false; 
		}
		if(move == "I" || move == "i")
		{
			return false; 
		}
		if(move == "J" || move == "j")
		{
			return false; 
		}
		if(move == "K" || move == "k")
		{
			return false; 
		}
		if(move == "L" || move == "l")
		{
			return false; 
		}
		else
		{
			if(move == "A" || move == "a")
			{
				x = 8; 
			}
			else if(move == "B" || move == "b")
			{
				x = 9; 
			}
			else if(move == "C" || move == "c")
			{
				x = 10; 
			}
			else if(move == "D" || move == "d")
			{
				x = 11; 
			}
			else if (move == "E" || move == "e")
			{
				x = 12; 
			}
			else if(move == "F" || move == "f")
			{
				x = 13; 
			}
			if(board[x] > 0)
				return true;
			else 
				return false; 
		}
	 
	}
	
	if(next_mover() == HUMAN)
	{
		if(move=="A" || move == "a")
		{
			return false; 
		}
		if(move == "B" || move == "b")
		{
			return false; 
		}
		if(move == "C" || move == "c")
		{
			return false; 
		}
		if(move == "D" || move == "d")
		{
			return false; 
		}
		if(move == "E" || move == "e")
		{
			return false; 
		}
		if(move == "F" || move == "f")
		{
			return false; 
		}
		else
		{
			if(move == "G" || move == "g")
			{
				x = 1;
			}
			if(move == "H" || move == "h")
			{
				x = 2; 
			}
			if(move == "I" || move == "i")
			{
				x = 3; 
			}
			if(move == "J" || move == "j")
			{
				x = 4; 
			}
			if(move == "K" || move == "k")
			{
				x = 5; 
			}
			if(move == "L" || move == "l")
			{
				x = 6; 
			}
			if(board[x] > 0)
				return true; 
			else 
				return false; 
		}
		
	}

		return false;
}

void Mancala::make_move(const std::string& move)
{
	if(is_legal(move))
	{
		int x; 
		if(move == "A" || move == "a")
		{
			x = 8; 
		}
		else if(move == "B" || move == "b")
		{
			x = 9; 
		}
		else if(move == "C" || move == "c")
		{
			x = 10; 
		}
		else if(move == "D" || move == "d")
		{
			x = 11; 
		}
		else if(move == "E" || move == "e")
		{
			x = 12; 
		}
		else if(move == "F" || move == "f")
		{
			x = 13;
		}
		else if(move == "G" || move == "g")
		{
			x = 1;
		}
		else if(move == "H" || move == "h")
		{
			x = 2; 
		}
		else if(move == "I" || move == "i")
		{
			x = 3; 
		}
		else if(move == "J" || move == "j")
		{
			x = 4; 
		}
		else if(move == "K" || move == "k")
		{
			x = 5; 
		}
		else if(move == "L" || move == "l")
		{
			x = 6; 
		}
		int pieces = board[x];
		board[x] = 0; 
		while(pieces > 0)
		{
			if(x==6)
			{
				if(next_mover()==HUMAN)
				{
					int temp = board[0];
					temp++; 
					board[0] = temp; 
					x = 14; 
					pieces--; 
				}
				else 
				{
					int temp = board[13]; 
					temp++;
					board[13] = temp; 
					x = 13; 
					pieces--; 
				}
			}
			if(x==8)
			{
				if(next_mover()==HUMAN)
				{
					int temp = board[1]; 
					temp++;
					board[1] = temp; 
					x = 1; 
					pieces--; 
				}
				else
				{
					int temp = board[7];
					temp++;
					board[7] = temp; 
					x = 0; 
					pieces--;
				}
			}
			else if(x > 7 && x <= 14)
			{
				int temp = board[x-1];
				temp++; 
				board[x-1] = temp; 
				x--; 
				pieces--; 
			}
			else if(x >= 0 && x < 7)
			{
				int temp = board[x+1];
				temp++;
				board[x+1] = temp; 
				x++; 
				pieces--; 
			}
		}
	}
		std::cout<< "End of turn." << std::endl; 
		game::make_move(move);
}

void Mancala::display_status()const
{
	std::cout << "         C O M P U T E R      " << std::endl; 
	std::cout << "   (A    B    C    D    E    F)" << std::endl;
	std::cout << "   ";
	for(int i = 8; i < 14; i++)
	{
		std::cout <<"(" << board[i] << ")  ";
	}
	std::cout << std::endl;
	std::cout <<"	  		  " << std::endl; 				 
	std::cout << "(" << board[7] << ")		              (" << board[0] <<")" << std::endl; 
	std::cout << "   ";
	for(int j = 1; j < 7; j++)
	{
		std::cout << "(" << board[j] << ")  ";
	}
	std::cout << std::endl << "   (G    H    I    J    K    L)";
	std::cout << std::endl << "             U S E R    " << std::endl;
}

void Mancala::compute_moves(std::queue<std::string>& moves)const
{
	std::string move; 
	move = "A";
	if(is_legal(move))
	{
		moves.push(move); 
	}
	move = "B";
	if(is_legal(move))
	{
		moves.push(move); 
	}
	move = "C";
	if(is_legal(move))
	{
		moves.push(move); 
	}
	move = "D";
	if(is_legal(move))
	{
		moves.push(move);
	}
	move = "E";
	if(is_legal(move))
	{
		moves.push(move); 
	}
	move = "F";
	if(is_legal(move))
	{
		moves.push(move); 
	}
}

void Mancala::restart()
{
	new Mancala();
}

game* Mancala::clone( )const
{
	return new Mancala(*this); 
}

bool Mancala::is_game_over() const
{
	if(board[8] == 0)
	{
		if(board[9] == 0)
		{
			if(board[10] == 0)
			{
				if(board[11] == 0)
				{
					if(board[12] == 0)
					{
						if(board[13] == 0)
						{
							return true; 
						}
					}
				}
			}
		}
	}
	else if(board[1] == 0)
	{
		if(board[2] == 0)
		{
			if(board[3] == 0)
			{
				if(board[4] == 0)
				{
					if(board[5] == 0)
					{
						if(board[6] == 0)
						{
							return true; 
						}
					}
				}
			}
		}
	}
	return false;
}

int Mancala::evaluate() const
{
	if(board[0] < board[7])
		return -1; 
	else
		return 1; 

}

game::who Mancala::winning()const
{
	if(board[7] > board[0])
	{
		return COMPUTER;
	}
	else if(board[0] > board[7])
	{
		return HUMAN;
	}
	else 
		return NEUTRAL;
}



