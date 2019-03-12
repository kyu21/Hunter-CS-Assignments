#include <iostream>
using namespace std;

bool makes10 (int a, int b) {
	if (a == 10 || b == 10 || a+b == 10) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cout << boolalpha;
	cout << makes10(9, 10) << endl;
	cout << makes10(10, 1) << endl;
	cout << makes10(4, 6) << endl;
	cout << makes10(1, 1) << endl;
}