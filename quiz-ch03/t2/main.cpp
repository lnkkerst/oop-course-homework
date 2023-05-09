#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

int maxOfThreeNum(int a, int b, int c = -1) {
  auto tmp = std::vector<int>{a, b, c};
  return *std::max_element(tmp.begin(), tmp.end());
}

int main() {
  std::vector<int> arr;
  std::cout << "Please input 2 or 3 numbers separated with spaces in one line."
            << std::endl;
  std::string s;
  getline(std::cin, s);
  std::stringstream ss(s);
  int x;
  while (ss >> x) {
    arr.emplace_back(x);
  }
  if (arr.size() <= 1) {
    std::cout << "Please input at least 2 numebrs!" << std::endl;
    return 1;
  }
  if (arr.size() > 3) {
    std::cout
        << "Input numbers amount is out of 3, only the first three are valid."
        << std::endl;
  }
  int ans = arr.size() == 3 ? maxOfThreeNum(arr[0], arr[1], arr[2])
                            : maxOfThreeNum(arr[0], arr[1]);
  std::cout << "The max number is: " << ans << std::endl;
  return 0;
}
