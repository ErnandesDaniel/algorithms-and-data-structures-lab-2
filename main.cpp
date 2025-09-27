#include <iostream>
#include <vector>
using namespace std;

const int MAX_BITS = 200200;

vector<char> bits(MAX_BITS, 0);
int count_ones = 0;

void do_add(int s) {
  int pos = s;
  while (bits[pos] == 1) {
    bits[pos] = 0;
    count_ones--;
    pos++;
  }
  bits[pos] = 1;
  count_ones++;
}

void do_sub(int s) {
  if (bits[s] == 1) {
    bits[s] = 0;
    count_ones--;
  } else {
    int pos = s + 1;
    while (bits[pos] == 0) {
      pos++;
    }
    bits[pos] = 0;
    count_ones--;
    for (int i = s; i < pos; i++) {
      bits[i] = 1;
      count_ones++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    char op;
    int s;
    cin >> op >> s;

    if (op == '+') {
      do_add(s);
    } else if (op == '-') {
      do_sub(s);
    }

    cout << count_ones << '\n';
  }

  return 0;
}