#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> arr;
  int n = 3;
  arr.resize(n);
  std::cout << "Please input 3 numbers separated with spaces." << std::endl;
  for (auto &i : arr) {
    std::cin >> i;
  }
  std::sort(arr.begin(), arr.end());
  for (auto i : arr) {
    std::cout << i << ' ';
  }
  return 0;
}
