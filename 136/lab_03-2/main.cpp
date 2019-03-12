#include <iostream>

#include "funcs.h"

int main() {
	cout << east_storage("01/01/2016") << "\n\n";
	cout << mineast() << "\n\n";
	cout << maxeast() << "\n\n";
	cout << compare("09/13/2016", "09/17/2016") << "\n";
	cout << reverse_order("05/29/2016","06/02/2016");
	return 0;
}
