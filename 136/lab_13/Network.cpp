#include <iostream>

#include "Network.h"

using namespace std;

int Network::findID (string usrn){
  for (int i = 0 ; i < MAX_USERS ; i ++){
	if (profiles[i].getUsername() == usrn){
	  return i;
	}
  }
  return -1;
}

bool check_valid(string username){
  for (int i = 0 ; i < username.length() ; i++){
	if (isalnum(username[i]) == false){
	  return false;
	}
  }
  return true;
}

Network::Network(){
  numUsers = 0;
}

bool Network::addUser(string usrn, string dspn){
  if (findID(usrn) == -1 && check_valid(usrn) == true && numUsers < 20){
	Profile p1(usrn, dspn);
	profiles[numUsers] = p1;
	numUsers += 1;
	return true;
  }
  else{
	return false;
  }
}