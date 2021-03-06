# tic-tac-toe
Command Line Tool that allows two player tic tac toe
TicTacToeBoard struct contains:
  - A list of 9 spaces (0 = TL, 1 = TM, 2 = TR, 3 = ML, etc.) read left to right, top to bottom
  - A constructor that will create a list where each index indicates the position on the board
  - Member functions that will allow for:
    - Determining whether the user input is a valid range (range must be from 0-8 and not previously played)
    - Placing the player's symbol in the requested spot (throws error 'invalid_argument' for any invalid position)
    - Checks for a horizontal win
    - Checks for a vertical win
    - checks for a diagonal win
    - Checks to see if there is a winner
  - Overloaded '<<' operator to allow the board to be printed properly to the Terminal in proper format

Compiled using command:
  - g++ -std=c++17 tictactoe.cpp tttboard.cpp -o tttgame.exe
  - ./tttgame.exe

Future updates:
  - A better struct to make the code more intuitive for develper. This struct will also assist in determining a winner much easier
    - Ideas for struct is a hash table, a map, or even a graph
  - Create a CPU to play against
  - Develop a GUI for the game
  - __Personal: The C++ code will follow a different format and better commenting style (Doxygen)__

Time Line:
  - TicTacToeBoard struct and main function:
    - Started: 08/22/21 @ 10:00
    - Ended: 08/23/21 @ 17:00

  - EDITS:
    - Added valid_range() on 08/23/21 @ 18:00
    - Added win determining functions on 08/23/21 @ 18:30

  - Future:
    - Better Struct: TBD
    - CPU: TBD
    - GUI: TBD
