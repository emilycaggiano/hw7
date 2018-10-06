//Othello function implementations to play 
//Emily Caggiano. CS2401, Project 6(game)

#include<iostream>
#include<iomanip>
#include "colors.h"
#include "othello.h"
#include "space.h"

namespace main_savitch_14{

Othello::Othello(){
	restart();
}

void Othello::restart(){
	board[3][3].make_white();
	board[3][4].make_black();
	board[4][3].make_black();
	board[4][4].make_white();
}

void Othello::display_status()const{
	int row = 1;
	cout << setw(5) << "A" << setw(5) << "B" << setw(5) << "C";
	cout << setw(5) << "D" << setw(5) << "E" << setw(5) << "F"; 
	cout << setw(5) << "G" << setw(5) << "H" << endl;
	    for(int i = 0; i < 8; i++){
			cout << RESET;
			cout << row;
		for(int j = 0; j < 8; j++){
			if(board[i][j].is_black()){
				cout << B_GREEN << BLACK << "|_@_|";
				cout << RESET;
			}
			else if(board[i][j].is_white()){
				cout << B_GREEN << "|_";
				cout << WHITE << "@";
				cout << BLACK << "_|";
				cout << RESET;
			}
			else{
				 cout << B_GREEN << "|___|";
			}
		}
		cout << RESET;
		cout << endl;
		++row;
	    }
}

bool Othello::is_legal(const string& move)const{
	int row = 0, column = 0;
	int i = 0,j = 0;
        column = int(toupper(move[0]-'A'));
        row = int(move[1] - '1');
	if(next_mover() == game::HUMAN){
		if(!board[row][column-1].is_empty()){
			for(i = column - 1; i > 0 && board[row][i].is_black(); i--){}
			if (board[row][i].is_white())
				return true;
		}
		if(!board[row][column+1].is_empty()){
			 for(i = column + 1; i < 8 && board[row][i].is_black(); i++){}
                         if (board[row][i].is_white())
                                return true;
                }
		if(!board[row-1][column].is_empty()){
			 for(i = row - 1; i > 0 && board[i][column].is_black(); i--){}
                         if (board[i][column].is_white())
                                return true;
                }
		if(!board[row+1][column].is_empty()){
			 for(i = row + 1; i < 8 && board[i][column].is_black(); i++){}
                         if (board[i][column].is_white())
                                return true;
                }
		if(!board[row-1][column-1].is_empty()){
			 for(i = row - 1, j = column -1; i > 0 && j > 0 && board[i][j].is_black(); i--, j--){}
                         if (board[i][j].is_white())
                                return true;
                }
		if(!board[row-1][column+1].is_empty()){
			 for(i = row - 1, j = column +1; i > 0 && j < 8 && board[i][j].is_black(); i--, j++){}
                         if (board[i][j].is_white())
                                 return true;
                }
		if(board[row+1][column-1].is_empty()){
			 for(i = row + 1, j = column -1; i < 8 && j > 0 && board[i][j].is_black(); i++, j--){}
                         if (board[i][j].is_white())
                                 return true;
                }
		if(!board[row+1][column+1].is_empty()){
			 for(i = row+1, j = column +1; i < 8 && j < 8 && board[i][j].is_black(); i++, j++){}
                         if (board[i][j].is_white())
                                 return true;
                }
		else
			return false;
	}
	if(next_mover() == game::COMPUTER){
		if(!board[row][column-1].is_empty()){
			for(i = column - 1; i > 0 && board[row][i].is_white(); i--){}
                        if (board[row][i].is_black())
                        	return true;
                }
		if(!board[row][column+1].is_empty()){
			for(i = column + 1; i < 8 && board[row][i].is_white(); i++){}
                        if (board[row][i].is_black())
                                 return true;
                }
		if(!board[row-1][column].is_empty()){
			for(i = row - 1; i > 0 && board[i][column].is_white(); i--){}
                        if (board[i][column].is_black())
                                 return true;
                }
		if(!board[row+1][column].is_empty()){
			for(i = row + 1; i < 8 && board[i][column].is_white(); i++){}
                        if (board[i][column].is_black())
                                 return true;
                }
		if(!board[row-1][column-1].is_empty()){
			for(i = row - 1, j = column - 1; i > 0 && j > 0 && board[i][j].is_white(); i--, j--){}
                        if (board[i][j].is_black())
                                 return true;
                }
		if(!board[row-1][column+1].is_empty()){
			for(i = row - 1, j = column + 1; i > 0 && j < 8 && board[i][j].is_white(); i--, j++){}
                        if (board[i][j].is_black())
                                 return true;
                }
		if(!board[row+1][column-1].is_empty()){
			for(i = row + 1, j = column - 1; i < 8 && j > 0 && board[i][j].is_white(); i++, j--){}
                        if (board[i][j].is_black())
                                 return true;
                }
		if(!board[row+1][column+1].is_empty()){
			for(i = row + 1, j = column + 1; i < 8 && j < 8 && board[i][j].is_white(); i++, j++){}
                        if (board[i][j].is_black())
                                 return true;
                }
		else
			return false;
	}			
}

void Othello::make_move(const string& move){
	int row = 0, column = 0;
	int j = 0, i = 0, k = 0, m = 0;
	column = int(toupper(move[0]-'A'));
	row = int(move[1] - '1');
	if(next_mover() == game::HUMAN){
		if(!board[row][column-1].is_empty()){
			for(i = column - 1; i > 0 && board[row][i].is_black(); i--){}
			if(i > 0 && board[row][i].is_white()){
				for(j = column -1; j > i; j--){
					board[row][j].flip();
				}
				board[row][column].make_white();
			}
		}
		if(!board[row][column+1].is_empty()){
			 for(i = column + 1; i < 8 && board[row][i].is_black(); i++){}
			 if(i < 8 && board[row][i].is_white()){
				for(j = column + 1; j < i; j++){
                                        board[row][j].flip();
				}
				board[row][column].make_white();
                        }
                }
		if(!board[row-1][column].is_empty()){
			 for(i = row - 1; i > 0 && board[i][column].is_black(); i--){}
			 if(i > 0 && board[i][column].is_white()){
				for(j = row - 1; j > i; j--){
					board[j][column].flip();
				}
                                board[row][column].make_white();
                        }
                }
		if(!board[row+1][column].is_empty()){
			 for(i = row + 1; i < 8 && board[i][column].is_black(); i++){}
			 if(i < 8 && board[i][column].is_white()){
				for(j = row + 1; j < i; j++){
					board[j][column].flip();
				}
                                board[row][column].make_white();
                        }
                }
		if(!board[row-1][column-1].is_empty()){
			 for(i = row - 1, j = column - 1; i > 0 && j > 0 && board[i][j].is_black(); i--, j--){}
			 if(i > 0 && j > 0 && board[i][j].is_white()){
				for(k = row - 1, m = column -1; k > i && m > j; k--, m--){
                                        board[k][m].flip();
				}
				board[row][column].make_white();
			}
                }
		if(!board[row-1][column+1].is_empty()){
			 for(i = row - 1, j = column + 1; i > 0 && j < 8 && board[i][j].is_black(); i--, j++){}
			 if(i > 0 && j < 8 && board[i][j].is_white()){
				for(k = row - 1, m = column + 1; k > i && m < j; k--, m++){
					board[k][m].flip();
				}
                                board[row][column].make_white();
			}
                }
		if(!board[row+1][column-1].is_empty()){
			 for(i = row + 1, j = column - 1; i < 8 && j > 0 && board[i][j].is_black(); i++, j--){}
			 if(i < 8 && j > 0 && board[i][j].is_white()){
				for(k = row + 1, m = column - 1; k < i && m > j; k++, m--){
					board[k][m].flip();
				}
                                board[row][column].make_white();
                        }
                }
		if(!board[row+1][column+1].is_empty()){
			 for(i = row+1, j = column + 1; i < 8 && j < 8 && board[i][j].is_black(); i++, j++){}
			 if(i < 8 && j < 8 && board[i][j].is_white()){
				for(k = row + 1, m = column + 1; k < i && m < j; k++, m++){
					board[k][m].flip();
				}
                                board[row][column].make_white();
                        }
                }
	}
	if(next_mover() == game::COMPUTER){
		if(!board[row][column-1].is_empty()){
			for(i = column - 1; i > 0 && board[row][i].is_white(); i--){}
			if(i > 0 && board[row][i].is_black()){
				for(j = column - 1; j > i; j--){
					board[row][j].flip();
				}
                                board[row][column].make_black();
                        }
                }
		if(!board[row][column+1].is_empty()){
			for(i = column + 1; i < 8 && board[row][i].is_white(); i++){}
			if(i < 8 && board[row][i].is_black()){
				for(j = column + 1; j < i; j++){
					board[row][j].flip();
				}
                                board[row][column].make_black();
                        }
                }
		if(!board[row-1][column].is_empty()){
			for(i = row - 1; i > 0 && board[i][column].is_white(); i--){}
			if(i > 0 && board[i][column].is_black()){
				for(j = row - 1; j > i; j--){
					board[j][column].flip();
				}
                                board[row][column].make_black();
                        }
                }
		if(!board[row+1][column].is_empty()){
			for(i = row + 1; i < 8 && board[i][column].is_white(); i++){}
			if(i < 8 && board[i][column].is_black()){
				for(j = row + 1; j < i; j++){
					board[j][column].flip();
				}
                                board[row][column].make_black();
                        }
                }
		if(!board[row-1][column-1].is_empty()){
			for(i = row - 1, j = column - 1; i > 0 && j > 0 && board[i][j].is_white(); i--, j--){}
			if(i > 0 && j > 0 && board[i][j].is_black()){
				for(k = row - 1, m = column - 1; k > i && m > j; k--, m--){
					board[k][m].flip();
				}
                                board[row][column].make_black();
                        }
                }
		if(!board[row-1][column+1].is_empty()){
			for(i = row - 1, j = column + 1; i > 0 && j < 8 && board[i][j].is_white(); i--, j++){}
			if(i > 0 && j < 8 && board[i][j].is_black()){
				for(k = row -1, m = column + 1; k > i && m < j; k--, m++){
					board[k][m].flip();
				}
                                board[row][column].make_black();
                        }
                }
		if(!board[row+1][column-1].is_empty()){
			for(i = row + 1, j = column - 1; i < 8 && j > 0 && board[i][j].is_white(); i++, j--){}
			if(i < 8 && j > 0 && board[i][j].is_black()){
				for(k = row + 1, m = column - 1; k < i && m > j; k++, m--){
					board[k][m].flip();
				}
				board[row][column].make_black();
                        }
                }
		if(!board[row+1][column+1].is_empty()){
			for(i = row+1, j = column + 1; i < 8 && j < 8 && board[i][j].is_white(); i++, j++){}
			if(i < 8 && j < 8 && board[i][j].is_black()){
				for(k = row +1, m = column + 1; k < i && m < j; k++, m++){
					board[k][m].flip();
				}
                                board[row][column].make_black();
                        }
                }			
	}
	game::make_move(move);
}
game* Othello::clone()const{
	return new Othello(*this);
}

void Othello::compute_moves(std::queue<std::string>&moves)const{
	std::string m = "  ";
	char i, j;
	for(i = 'A'; i < 'I'; ++i){
		for(j = '1'; j < '8'; ++j){
			m[0] = i;
			m[1] = j;
			if(is_legal(m)){
				moves.push(m);
			}
		}
	}
}	

int Othello::evaluate()const{
	int human = 0, computer = 0, total = 0;
	int i, j;
	for(i = 0; i < 8; ++i){
		for(j = 0; j < 8; j++){
			if(board[i][j].is_white()){
				--human;
			}
			if(board[i][j].is_black()){
				++computer;
			}
		}
	}
	total = computer + human;
	return total;
} 

game::who Othello::winning()const{
	int white_pieces = 0, black_pieces = 0;
	int i = 0 , j = 0;
	for(i = 0, j = 0; j < 8 && i < 8; ++i, ++j){
		if(board[i][j].is_white()){
			++white_pieces;
		}
		else if(board[i][j].is_black()){
			++black_pieces;
		}
	}
	if(white_pieces > black_pieces){
		return HUMAN;
	}
	else if(black_pieces > white_pieces){
		return COMPUTER;
	}
	else
		return NEUTRAL;
}
		
bool Othello::is_game_over()const{
	if(moves_completed() == 60){
		return true;
	}
	else
		return false;
}

}
