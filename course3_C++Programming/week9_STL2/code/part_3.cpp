#include <iostream>
#include <string>
#include <set>
#include <iterator>
using namespace std;

int main() {
  multiset<int> a;
  set<int> b;
  multiset<int>::iterator has;
  int n, k;
  string s;
  cin >> n;
  while (n--) {
    cin >> s >> k;
    switch (s.at(1)) {
      case 'd':
        a.insert(k);
        b.insert(k);
        cout << a.count(k) << endl;
        break;
      case 'e':
        cout << a.count(k) << endl;
        a.erase(k);
        break;
      case 's':
        has = b.find(k);
        if(has != b.end())
          cout << 1 << ' ';
        else
          cout << 0 << ' ';
        cout << a.count(k) << endl;
        break;
    }
  }
  return 0;
}