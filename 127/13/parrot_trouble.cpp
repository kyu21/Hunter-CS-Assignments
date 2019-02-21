#include <iostream>
using namespace std;

bool parrot_trouble (bool talking, int hour) {
	if ((hour < 7 && talking) || (hour > 20 and talking)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cout << boolalpha;
	cout << parrot_trouble(true, 6) << endl;
	cout << parrot_trouble(true, 18) << endl;
	return 0;
}