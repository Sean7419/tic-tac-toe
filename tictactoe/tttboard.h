#ifndef TTTBOARD_H
#define TTTBOARD_H

#include<iostream>
#include<vector>
#include<sstream>

class TicTacToeBoard {
private:
	// The board consists of a vector
	// Reads position as L -> R U -> 
	// One list used for easier construction
	std::vector<char> board_;

public:
	// Constructor
	TicTacToeBoard();

	// Member Functions
	bool valid_range(const std::string &);
	void place(const std::string &, const char &);
	bool vert_win();
	bool horz_win();
	bool diag_win();
	bool winner();

	// Overloaded operators
	friend std::ostream &operator << (std::ostream&, const TicTacToeBoard&);
};

#endif
