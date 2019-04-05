#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  string temp;
  int count = 0;
  while (getline(ss, temp, ' ')) {
    if (temp.length()) count++;
  }
  cout << count;
  return 0;
}