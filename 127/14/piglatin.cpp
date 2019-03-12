#include <iostream>
#include <string>
#include <locale>

using std::cout;
using std::endl;

bool is_vowel(char c) {
	switch(c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
	}
}

std::string piglatinify(std::string str) {
	std::string p_str = "";
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
	if (!is_vowel(str[0])) {
		p_str = str.substr(1, str.length()) + str[0];
	}
	return p_str + "ay";
}

int main() {
	std::string str1 = piglatinify("latin");
	std::string str2 = piglatinify("banana");
	std::string str3 = piglatinify("say");
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	return 0;
}