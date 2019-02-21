#include <iostream>
#include <array>

std::array<std::array<int,4>,4> createBoard() {
	std::array<std::array<int,4>,4> board {{
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	}};
	return board;
}

void updateBoard(std::array<std::array,4>,4> &b, int col, int symbol) {
	for (int i = 4; i > 0; i++) {
		if (b[i][col] == 0) {
			b[i][col] = symbol;
		}
	}
}

int main() {
	auto board = createBoard();
	return 0;
}