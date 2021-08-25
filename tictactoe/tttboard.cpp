#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<exception>
#include "tttboard.h"

// Constructor

// Creates an empty tic tac toe board
// Each index represents a position on the board
TicTacToeBoard::TicTacToeBoard(){
	// Filling vector with 9 corresponding position
	char pos = '0';
	while(pos < '9'){
		board_.push_back(pos);
		pos++;
	}
}

// Member functions

// Function determines if the user input for position is valid on the board
// Has to be a number between the range of 0-8 and unused
bool TicTacToeBoard::valid_range(const std::string &pos){
	for(auto &e : pos){ // Checking that it is a positive number
		if(isdigit(e) == 0)
			return false;
	}
	int int_pos = std::stoi(pos);
	if(int_pos > 8 || isalpha(board_.at(int_pos))) // Checking that it is in range
		return false;
	return true;
}

// Check if the given position is valid, and changes to the player's symbol
void TicTacToeBoard::place(const std::string &pos, const char &player){
	if(!valid_range(pos))
		throw std::invalid_argument("");
	else{
		int int_pos = std::stoi(pos);
		board_.at(int_pos) = player;
	}
}

// Check if the player has won the game vertically
bool TicTacToeBoard::vert_win(){
	for(int i = 0; i <= 3; i++){
		if(board_.at(i) == board_.at(i + 3) && board_.at(i+3) == board_.at(i+6))
			return true;
	}
	return false;
}

bool TicTacToeBoard::horz_win(){
	for(int i = 0; i <=7; i += 3){
		if(board_.at(i) == board_.at(i+1) && board_.at(i+1) == board_.at(i+2))
			return true;
	}
	return false;
}

bool TicTacToeBoard::diag_win(){
	if(board_.at(0) == board_.at(4) && board_.at(4) == board_.at(8))
		return true;
	else if(board_.at(2) == board_.at(4) && board_.at(4) == board_.at(6))
		return true;
	else 
		return false;
}

bool TicTacToeBoard::winner(){
	return (vert_win() || horz_win() || diag_win());
}

// Overloaded operator

// This allows a formated display of the tictactoe board when printed
// An example (empty) should look like:
//		 0 | 1 | 2
//		-----------
//		 3 | 4 | 5
//		-----------
//		 6 | 7 | 8
// When a player makes a move the board will change (X, O)

std::ostream& operator << (std::ostream &out, const TicTacToeBoard &the_board){
	for(int i = 0, j = 0; i < 9; i++){
		if(j >= 2 && i <= 7){ // Starts next row with line break
			out << ' ' << the_board.board_.at(i) << std::endl;
			out << "-----------\n";
			j = 0;
		}
		else{
			if(i == 8){ // Checks for last element (doesnt add |)
				out << ' ' << the_board.board_.at(i) << std::endl;
			}
			else{
				out << ' ' << the_board.board_.at(i) << " |";
				j++;
			}
		}
	}
	return out;
}
