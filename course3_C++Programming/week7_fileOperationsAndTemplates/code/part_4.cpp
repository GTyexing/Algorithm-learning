/*编程题＃4： 字符串操作

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1-500，现有如下若干操作：

copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。

add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，若不是，则作字符串加法，返回的值为一字符串。

find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。

rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，若没有找到，返回字符串的长度。

insert S N X：在第N个字符串的第X个字符位置中插入S字符串。

reset S N：将第N个字符串变为S。

print N：打印输出第N个字符串。

printall：打印输出所有字符串。

over：结束操作。

其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。

输入

第一行为一个整数n（n在1-20之间）

接下来n行为n个字符串，字符串不包含空格及操作命令等。

接下来若干行为一系列操作，直到over结束。

输出

根据操作提示输出对应字符串。

样例输入
3
329strjvc
Opadfk48
Ifjoqwoqejr
insert copy 1 find 2 1 2 2 2
print 2
reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
print 3
insert a 3 2
printall
over

样例输出
Op29adfk48
358
329strjvc
Op29adfk48
35a8*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
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