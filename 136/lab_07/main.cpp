#include<iostream>

#include "funcs.h"

using std::cout;

int main() {
	testascii("Cat :3 Dog");
	cout << encryptCaesar("Way to Go!", 5) << "\n";
	cout << encryptCaesar("Hello World!", 10) << "\n";
	cout << encryptVigenere("Hello, World!", "cake") << "\n";
	cout << decryptCaesar("Rovvy, Gybvn!", 10) << "\n";
	cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << "\n";
	return 0;
}