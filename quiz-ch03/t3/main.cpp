#include <algorithm>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::reverse;
using std::string;

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  cout << s;
  return 0;
}
