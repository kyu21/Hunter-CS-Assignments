#include <iostream>

#include "Network2.h"

using namespace std;

int Network::findID (string usrn) {
	for (int i = 0 ; i < MAX_USERS ; i ++) {
		if (profiles[i].getUsername() == usrn) {
			return i;
		}
	}
	return -1;
}

bool check_valid(string username) {
	for (int i = 0 ; i < username.length() ; i++) {
		if (isalnum(username[i]) == false) {
			return false;
		}
	}
	return true;
}

Network::Network() {
	numUsers = 0;
	for (int i = 0 ; i < MAX_USERS ; i++) {
		for (int j = 0; j < MAX_USERS ; j++) {
			following[i][j] = false;
		}
	}
}

bool Network::addUser(string usrn, string dspn) {
	if (findID(usrn) == -1 && check_valid(usrn) == true && numUsers < 20) {
		Profile p1(usrn, dspn);
		profiles[numUsers] = p1;
		numUsers += 1;
		return true;
	}
	else {
		return false;
	}
}

bool Network::follow(string usrn1, string usrn2) {
	int one = findID(usrn1);
	int two = findID(usrn2);
	following[one][two] = true;
}

void Network::printDot() {
	for (int i = 0 ; i < numUsers ; i ++) {
		cout << "@" << profiles[i].getUsername() << endl;
	}
	cout << endl;
	for (int i = 0 ; i < numUsers ; i ++) {
		for (int j = 0 ; j < numUsers ; j ++) {
			if (following[i][j] == true) {
				cout << "@" << profiles[i].getUsername() << " -> " << "@" << profiles[j].getUsername() << endl;
			}
		}
	}
}
