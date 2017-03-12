#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct s{
  int num; //数
  int pf; //质因子数
  s(int a, int b): num(a), pf(b) {}
  friend bool operator<(s s1, s a) {
    if(s1.pf < a.pf)
      return true;
    else if(s1.pf == a.pf)
      return s1.num < a.num;
    else
      return false;
  }
  friend class MyLess;
};

struct Myless{
  bool operator()(s s1, s s2) {
    if(s1.pf > s2.pf)
      return true;
    else if(s1.pf == s2.pf)
      return s1.num > s2.num;
    else
      return false;
  }
};

typedef priority_queue<s> pqLess;
typedef priority_queue<s, vector<s>, Myless> pqMax;

int main()
{
  int n, a, d = 0, size = 0;
  set<int> S;
  pqLess pl;
  pqMax pm;
  cin >> n;
  while (n--) {
    for(int j = 0; j < 10; j++) {
      cin >> a;
      d = a;
      for(int i = 2; i <= a; i++ ) {
        while(i != a) {
          if(a % i == 0) {
            S.insert(i);
            a = a / i;
          }
          else
            break;
        }
      }
      S.insert(a);
      size = (int)S.size();
      pl.push(s(d, size));
      pm.push(s(d, size));
      S.clear();
    }
    cout << pl.top().num << ' ' << pm.top().num << endl;
    pl.pop();
    pm.pop();
  }
}















