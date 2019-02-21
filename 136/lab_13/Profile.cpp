#include "Profile.h"

using namespace std;

Profile::Profile(string usrn, string dspn){
  username = usrn;
  displayname = dspn;
}
// Default Profile constructor (username="", displayname="")
Profile::Profile(){
  username = "";
  displayname = "";
}
// Return username
string Profile::getUsername(){
  return username;
}
// Return name in the format: "displayname (@username)"
string Profile::getFullName(){
  return (displayname + " " + "(@" + username + ")");
}
// Change display name
void Profile::setDisplayName(string dspn){
  displayname = dspn;
}