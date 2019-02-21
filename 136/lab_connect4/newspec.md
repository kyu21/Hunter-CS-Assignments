#Connect N
### by Connor, Gareth, Leman

## Types

A `gameboard` is a type which contains all of the information about the game. It contains the game state as a 1 or 2 dimensional vector of structs, and the size of said board. It may carry more information.


A `player` is a type that represents the index of a player. It may be an integer like `int` or `std::uint8_t`. A player should have a trap value which signals an invalid player. This may be zero or negative one.

A `column` is a type that describes the column that a move is being placed into. It may be an integer.

## Functions

`void print_board(const gameboard& gb);` 

This function takes the current state of the gameboard `gb` and prints the shit out of it.

---

`column choose_next_move(const gameboard& gb, player p);`

This function runs AI for figuring out the next move for the player `p`. It may do something mad dumb or really complicated. It then returns the shit out of the column to place the piece in.

---

`column get_next_player_move(const gameboard& gb, player p);`

Gets the shit out of the move from the human player `p` and returns the integer of corresponding column on the gameboard `gb`.

---

`void move(gameboard& gb, player p, column c);`

This function updates the shit out of the gameboard `gb` using the player `p`’s move `c` which is specified using an integer referring to the column to place the piece.

---

`player check_win_state(const gameboard& gb);`

This function takes the current state of the gameboard `gb` and checks the shit out of whether any pieces are in a winning state. Winning state is defined as N pieces adjacent to each other, horizontally, vertically and diagonally. If no player has won, return the trap value.