#include <iostream>
#include "MazeSolver.h"

int main() {
	MazeSolver solverA("inputA.txt");
	MazeSolver solverB("inputB.txt");
	MazeSolver solverC("inputC.txt");
	MazeSolver solverD("inputD.txt");

	if (solverA.mazeIsReady()) {
		solverA.solveMaze();
		solverA.printSolution();

		solverB.solveMaze();
		solverB.printSolution();

		solverC.solveMaze();
		solverC.printSolution();

		solverD.solveMaze();
		solverD.printSolution();
	}

	return 0;
}