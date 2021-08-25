#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include "tttboard.h"

void catz_game(){
	std::cout << "CATZ GAME! SORRY!\n";
}

int main() {
	TicTacToeBoard tttb;
	std::cout << tttb;
	int turn_count = 0;
	std::string pos;
	char player = 'X';

	while(turn_count <= 8){
		try{
			std::cout << "Where would you like to place player " << player << "?\n";
			std::cin >> pos;
			tttb.place(pos, player);
		}
		catch(std::invalid_argument & e){
			std::cout << "Your input must be a number between 0-8 and not previously played!\n";
			continue;
		}
		catch(std::out_of_range & e){
			std::cout << "BETWEEN 0 - 8!\n";
			continue;
		}
		if(tttb.winner()){
			std::cout << tttb << std::endl;
			std::cout << "Congrats player " << player << "! You win!\n";
			break;
		}
		if(player == 'X')
			player = 'O';
		else
			player = 'X';
		std::cout << tttb;
		turn_count++;
	}
	if(turn_count == 9)
		catz_game();
}
