#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;

void mySort(vector<int> &a) { sort(a.begin(), a.end()); }
void mySort(vector<float> &a) { sort(a.begin(), a.end()); }
void mySort(vector<double> &a) { sort(a.begin(), a.end()); }

template <typename T> void solve() {
  cout << "请输入数据数量: ";
  int n;
  cin >> n;
  vector<T> arr(n);
  cout << "请输入数据：" << endl;
  for (auto &i : arr) {
    cin >> i;
  }
  mySort(arr);
  for (auto i : arr) {
    cout << i << ' ';
  }
  cout << endl;
  return;
}

int main() {
  cout << "请输入数据类型(输入括号里的数)：" << endl;
  cout << "int(0)\nfloat(1)\ndouble(2)" << endl;
  int type;
  cin >> type;
  if (type == 0) {
    solve<int>();
  } else if (type == 1) {
    solve<float>();
  } else if (type == 2) {
    solve<double>();
  } else {
    cout << "Input error!" << endl;
    return 1;
  }
  return 0;
}
