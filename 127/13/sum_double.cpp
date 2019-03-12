#include <iostream>
using namespace std;

int sum_double(int a, int b) {
	if (a == b) {
		return (a+b)*2;
	}
	else {
		return (a+b);
	}
}

int main() {
	cout << sum_double(1, 2) << endl;
	cout << sum_double(3, 2) << endl;
	cout << sum_double(3, 3) << endl;
 	return 0;
}