#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

string removeLeadingSpaces(string line) {
	int index = 0;
	while (isspace(line[index])) {
		index++;
		continue;
	}
	return line.substr(index);
}

int main() {
	string line = "";
	while (getline(cin, line)) {
		cout << removeLeadingSpaces(line) << "\n";
		line = "";
	}
	return 0;
}