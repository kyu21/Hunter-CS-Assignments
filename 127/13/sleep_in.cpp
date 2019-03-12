#include <iostream>

// The parameter weekday is True if it is a weekday, and the parameter vacation is True if we are on vacation. We sleep in if it is not a weekday or we're on vacation. Return True if we sleep in.

bool sleep_in(bool weekday, bool vacation) {
	if (vacation == true) {
		return true;
	}
	else if (weekday == false) {
		return true;
	}
	return false;
}

int main() {
	std::cout << std::boolalpha;
	std::cout << sleep_in(false, false) << std::endl;
	std::cout << sleep_in(true, false) << std::endl;
	std::cout << sleep_in(false, true) << std::endl;
	std::cout << sleep_in(true, true) << std::endl;
	return 0;
}

