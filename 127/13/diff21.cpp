#include <iostream>
using namespace std;

int diff21(int a) {
	if (a < 21) {
		return 21 - a;
	}
	else {
		return 2*(a-21);
	}
}

int main () {
	cout << diff21(19) << endl;
	cout << diff21(21) << endl;
	cout << diff21(30) << endl;
	return 0;
}