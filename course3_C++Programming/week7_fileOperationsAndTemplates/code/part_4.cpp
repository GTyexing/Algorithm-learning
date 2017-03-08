#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> a;
string Mycopy();
string Myadd();
int Myfind();
int Myrfind();

string Mycopy() {//取出第N个字符串第X个字符开始的长度为L的字符串
  string n, x, l;
  int N, X, L;
  cin >> n;
  if(n == "find")
    N = Myfind();
  else if(n == "rfind")
    N = Myrfind();
  else
    N = atoi(n.c_str());
  cin >> x;
  if(x == "find")
    X = Myfind();
  else if(x == "rfind")
    X = Myrfind();
  else
    X = atoi(x.c_str());
  cin >> l;
  if(l == "find")
    L = Myfind();
  else if(l == "rfind")
    L = Myrfind();
  else
    L = atoi(l.c_str());
  return a[N - 1].substr(X, L);
}

string Myadd(){//判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。
  string s1, s2, S;
  cin >> s1;
  if(s1 == "copy")
    s1 = Mycopy();
  else if(s1 == "add")
    s1 = Myadd();
  cin >> s2;
  if(s2 == "copy")
    s2 = Mycopy();
  else if(s2 == "add")
    s2 = Myadd();
  bool isNum = 1;
  for(int i = 0; i < s1.size(); i++) {
    if(s1[i] < '0' || s1[i] > '9') {
      isNum = 0;
      break;
    }
  }
  for(int i = 0; i < s2.size(); i++) {
    if(s1[i] < '0' || s1[i] > '9') {
      isNum = 0;
      break;
    }
  }
  if(isNum == 1) {
    int i = atoi(s1.c_str()) + atoi(s2.c_str());
    S = to_string(i);
  } else
    S = s1 + s2;
  return S;
}

int Myfind() {//在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
  string s, n;
  int N;
  cin >> s;
  if(s == "add")
    s = Myadd();
  else if (s == "copy")
    s = Mycopy();
  cin >> n;
  if(n == "find")
    N = Myfind();
  else if(n == "rfind")
    N = Myrfind();
  else
    N = atoi(n.c_str());
  return (int)a[N - 1].find(s);
}

int Myrfind() {//在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。
  string s, n;
  int N;
  cin >> s;
  if(s == "add")
    s = Myadd();
  else if (s == "copy")
    s = Mycopy();
  cin >> n;
  if(n == "find")
    N = Myfind();
  else if(n == "rfind")
    N = Myrfind();
  else
    N = atoi(n.c_str());
  return (int)a[N - 1].rfind(s);
}

void getString(string & s) {
  cin >> s;
  if(s == "copy")
    s = Mycopy();
  else if(s == "add")
    s = Myadd();
}

void getInt(int & i) {
  string s;
  cin >> s;
  if(s == "find")
    i = Myfind();
  else if(s == "rfind")
    i = Myrfind();
  else
    i = atoi(s.c_str());
}

void insert() {//在第N个字符串的第X个字符位置中插入S字符串
  string s;
  int n, x;
  getString(s);
  getInt(n);
  getInt(x);
  a[n - 1].insert(x, s);
}

void reset() {//将第N个字符串变为S
  string s;
  int n;
  getString(s);
  getInt(n);
  a[n - 1] = s;
}

int main()
{
  int n;
  cin >> n;
  cin.get();
  string s;
  for(int i = 0; i < n; i++) {
    getline(cin, s);
    a.push_back(s);
  }
  string commend;
  while(cin >> commend) {
    if(commend == "over")
      break;
    switch (commend.at(0)) {
      case 'p':
        if(commend == "print") {
          int n;
          cin >> n;
          cout << a[n - 1] << endl;
        }
        else {
          for(int i = 0; i < a.size(); i++)
            cout << a[i] << endl;
        }
        break;
      case 'i':
        insert();
        break;
      case 'r':
        reset();
        break;
    }
  }
  return 0;
}