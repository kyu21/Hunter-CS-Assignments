#include <iostream>
#include <string>

using std::cout;
using std::string;

void testascii(string s) {
	char c;
	for (int i = 0; i < s.length(); i++) {
		cout << s[i] << " " << int(s[i]) << "\n";
	}
}

char shiftChar(char c, int rshift) {
	int shift = (isupper(c)) ? 65 : 97;
	char shifted_char = c - shift;
	shifted_char = (shifted_char + rshift) % 26;
	return shifted_char + shift;
}

string encryptCaesar(string plaintext, int rshift) {
	string s = "";
	for (int i = 0; i < plaintext.length(); i++) {
		if (isalpha(plaintext[i])) {
			s += shiftChar(plaintext[i], rshift);
		}
		else {
			s += plaintext[i];
		}
	}
	return s;
}

string encryptVigenere(string plaintext, string keyword) {
	string s = "";
	int counter = 0;
	for (int i = 0; i < plaintext.length(); i++) {
		if (isalpha(plaintext[i])) {
			s += shiftChar(plaintext[i], keyword[counter] - 97);
			counter = (counter < keyword.length()-1) ? (counter + 1) : 0;
		}
		else {
			s += plaintext[i];
		}
	}
	return s;
}

string decryptCaesar(string ciphertext, int rshift) {
	int shift = 26 - rshift;
	string s = "";
	for (int i = 0; i < ciphertext.length(); i++) {
		if (isalpha(ciphertext[i])) {
			s += shiftChar(ciphertext[i], shift);
		}
		else {
			s += ciphertext[i];
		}
	}
	return s;
}

string decryptVigenere(string ciphertext, string keyword) {
	string s = "";
	int counter = 0;
	for (int i = 0; i < ciphertext.length(); i++) {
		if (isalpha(ciphertext[i])) {
			int shift = 26 - (keyword[counter] - 97);
			s += shiftChar(ciphertext[i], shift);
			counter = (counter < keyword.length()-1) ? (counter + 1) : 0;
		}
		else {
			s += ciphertext[i];
		}
	}
	return s;
}