#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

std::string line(int l, std::string c){
  std::string str = "";
  for (int i = 0; i < l; i++) {
    str += c;
  }
  return (str + "\n");
}

std::string rect(int w, int h) {
  std::string str = "";
  for (int i = 0; i < h; i++) {
    str += line(w, "*");
  }
  return str;
}

std::string tri1(int h) {
  string str = "";
  for (int i = 0; i < h; i++) {
    str += line(i, "*");
  }
  return str;
}

std::string tri2(int h) {
  std::string str = "";
  int spaces = h;
  int start = 1;
  for (int i = 0; i < h ; i++){
    for (int j = 0; j < spaces ; j++){
      str += " ";
    }
    str += line(start,"*");
    spaces -= 1;
    start += 2;
  }
  return str;
}

std::string tri3(int h) {
  string str = "";
  for (int i = 1; i <= h; i++) {
    for (int j = h; j >= i; j--) {
      str += " ";
    }
    for (int j = 1; j <= i; j++) {
      str += "*";
    }
    str += "\n";
  }
  return str;
}

int main(){
  string s="hello";
  string l = line(5, s);
  string r = rect(7, 4);
  string t1 = tri1(9);
  string t2 = tri2(5);
  string t3 = tri3(5);
  cout<<s<<endl;
  cout<<l<<endl;
  cout<<r<<endl;
  cout<<t1<<endl;
  cout<<t2<<endl;
  cout<<t3<<endl;
}

