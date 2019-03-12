#include <iostream>

#include "funcs.h"

int main() {
	std::cout << "\nTask A.Box\nInput width: 7\nInput height : 4\n\nShape:\n" << box(7, 4) << "\n";
	std::cout << "Input width: 3\nInput height: 5\n\nShape:\n" << box(3,5) << "\n";
	std::cout << "Task B.Checkerboard\nInput width: 11\nInput height : 6\n\nShape:\n" << checkerboard(11, 6) << "\n";
	std::cout << "Task C.Cross\nInput size: 8\n\nShape:\n" << cross(8) << "\n";
	std::cout << "Input size: 7\n\nShape:\n" << cross(7) << "\n";
	std::cout << "Task D.Lower Triangle\nInput side length: 6\n\nShape:\n" << lower_triangle(6) << "\n";
	std::cout << "Task E.Upper Triangle\nInput side length: 5\n\nShape:\n" << upper_triangle(5) << "\n";
	std::cout << "Task F.Upside-down trapezoid\nInput width: 12\nInput height : 5\n\nShape:\n" << trapezoid(12, 5) << "\n";
	std::cout << "Input width: 12\nInput height : 7\n\n" << trapezoid(12, 7) << "\n";
	std::cout << "Task G.Checkerboard(3x3)\nInput width: 16\nInput height : 11\n\nShape:\n" << checkerboard3x3(16,11) << "\n";
	std::cout << "Input width: 27\nInput height : 27\n\n" << checkerboard3x3(27,27);
	return 0;
}