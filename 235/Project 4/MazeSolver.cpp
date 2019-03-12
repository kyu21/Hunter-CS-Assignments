//
//  MazeSolver.cpp
//
//  Maze:
//  This class finds a solution to a maze read from an input file
//  and prints a solution to the standard output
//
//  Kun Yu
//  CSCI 235 Fall 2018
//  Project 4
//

#include "MazeSolver.h"

// Parametrized Constructor
// If file exists, intialize variables
MazeSolver::MazeSolver(std::string input_file) {
	std::ifstream fin(input_file);

	if (fin) {
		fin >> maze_rows_ >> maze_columns_;
		initializeMaze(maze_rows_, maze_columns_);
		fillMaze(fin);
		initializeSolution();

		maze_ready = true;
	}
	else {
		std::cout << "Cannot read from " << input_file << "\n";
	}

	fin.close();
} 

// Destructor for dynamically allocated 2d-array
MazeSolver::~MazeSolver() {
	if (mazeIsReady()) {
		// Maze
		for (auto i = 0; i < maze_rows_; ++i) {
			delete[] maze_[i];
		}
		delete[] maze_;

		// Solution
		for (auto i = 0; i < maze_rows_; ++i) {
			delete[] solution_[i];
		}
		delete[] solution_;
	}
}

// Returns if variables have been initialized
bool MazeSolver::mazeIsReady() {
	return maze_ready;
}

// Goes through maze with a stack-based approach
// Only 2 valid directions - Down (SOUTH), Right (EAST)
// > marks the path
// X marks dead ends
// @ marks paths that have been backtracked through
bool MazeSolver::solveMaze() {
	Position curr = {0,0};
	backtrack_stack_.push(curr);

	while (!(backtrack_stack_.empty())) {
		int r = curr.row;
		int c = curr.column;

		if (solution_[r][c] == '$') {
			std::cout << "Found the exit!!!\n";
			return true;
		}
		else if(extendPath(curr)) {
			solution_[r][c] = '>';
			curr = backtrack_stack_.top();
		}
		else {
			maze_[r][c] = 'X';
			solution_[r][c] = '@';

			backtrack_stack_.pop();

			if (!(backtrack_stack_.empty())) {
				curr = backtrack_stack_.top();
			}
			else {
				std::cout << "This maze has no solution.\n";
				return false;
			}
		}
	}

	return false;
}

// Prints solution path and maze
// Symbols seperated by spaces
void MazeSolver::printSolution() {
	std::cout << "The solution to this maze is:\n";

	for (auto r = 0; r < maze_rows_; ++r) {
		for (auto c = 0; c < maze_columns_; ++c) {
			if (c == maze_columns_ - 1) {
				std::cout << solution_[r][c];
			}
			else {
				std::cout << solution_[r][c] << " ";
			}
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}

// Dynamically Allocates 2D Character Maze Array
void MazeSolver::initializeMaze(int rows, int columns) {
	maze_ = new char*[rows];

	for (auto i = 0; i < rows; ++i) {
		maze_[i] = new char[columns];
	}
}

// Fills Character Array with symbols from input file
void MazeSolver::fillMaze(std::ifstream& input_stream) {
	for (auto r = 0; r < maze_rows_; ++r) {
		for (auto c = 0; c < maze_columns_; ++c) {
			input_stream >> maze_[r][c];
		}
	}
}

// Dynamically Allocates 2D Character Solution Array
void MazeSolver::initializeSolution() {
	solution_ = new char*[maze_rows_];

	for (auto i = 0; i < maze_rows_; ++i) {
		solution_[i] = new char[maze_columns_];
	}

	copyMazetoSolution();
}

// Fills Character Array with symbols from input file
void MazeSolver::copyMazetoSolution() {
	for (auto r = 0; r < maze_rows_; ++r) {
		for (auto c = 0; c < maze_columns_; ++c) {
			solution_[r][c] = maze_[r][c];
		}
	}
}

// Returns if can move down or right
// Used for checking dead ends
bool MazeSolver::extendPath(Position current_position) {
	bool extended = false;

	if (isExtensible(current_position, SOUTH)) {
		backtrack_stack_.push(getNewPosition(current_position, SOUTH));
		extended = true;
	}

	if (isExtensible(current_position, EAST)) {
		backtrack_stack_.push(getNewPosition(current_position, EAST));
		extended = true;
	}

	return extended;

}

// Responsible for filling stack with new positions to check
Position MazeSolver::getNewPosition(Position old_Position, direction dir) {
	Position south = {old_Position.row + 1, old_Position.column};
	Position east = {old_Position.row, old_Position.column + 1};

	if (dir == SOUTH) {
		return south;
	}

	if (dir == EAST) {
		return east;
	}

	return {-1, -1};
}

// Logic for if can proceed down or right
// If symbol to the bottom or right is _ or $, can proceed
// Must stay within maze
bool MazeSolver::isExtensible(Position current_position, direction dir) {
	int r = current_position.row;
	int c = current_position.column;

	if (dir == SOUTH && (r + 1) < maze_rows_) {
		// char c = maze_[r + 1][c];
		if (maze_[r + 1][c] == '_' || maze_[r + 1][c] == '$') {
			return true;
		}
	}
	else if (dir == EAST && (c + 1) < maze_columns_) {
		// char c = maze_[r][c + 1];
		if (maze_[r][c + 1] == '_' || maze_[r][c + 1] == '$') {
			return true;
		}
	}

	return false;
}