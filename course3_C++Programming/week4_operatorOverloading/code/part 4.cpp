/*编程题＃4：大整数的加减乘除

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

输入

第一行：正整数a，长度不超过100

第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个

第三行：正整数b，长度不超过100

保证输入不含多余的空格或其它字符

输出

一行：表达式“a o b”的值。

补充说明：

1. 减法结果有可能为负数

2. 除法结果向下取整

3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class bignum {
  string s;
  int compare(string s1, string s2) {
    if(s1.size() < s2.size())
      return -1;
    else if(s1.size() > s2.size())
      return 1;
    else
      return s1.compare(s2);
  }
public:
  bignum()  {}
  bignum(string s1): s(s1) {}
  bignum & operator+(bignum & a);
  bignum & operator-(bignum & a);
  bignum & operator*(bignum & a);
  bignum & operator/(bignum & a);
  friend ostream & operator<<(ostream & os, const bignum & a);
  friend istream & operator>>(istream & is, bignum & a);
};

bignum & bignum::operator+(bignum & a)
{
  int jw = 0;//jw 标志是否有进位
  string bigger, smaller;
  if (a.s.length() >= s.length()) {
    bigger = a.s;
    smaller = s;
  }
  else {
    bigger = s;
    smaller = a.s;
  }
  int d = (int)bigger.length() - (int)smaller.length();
  for (int i = 0; i < d; i++) {
    smaller = "0" + smaller;
  }
  int l = (int)bigger.length();
  for (int i = 1; i <= l; i++) {
    string m = bigger.substr(l - i, 1);
    string n = smaller.substr(l - i, 1);
    int j = atoi(m.c_str()) + atoi(n.c_str()) + jw;
    jw = 0;
    if (j >= 10) {
      j -= 10;
      jw = 1;
    }
    string c;
    c = to_string(j);
    bigger.replace(l - i, 1, c);
    if (i == l && jw == 1) {
      bigger = "1" + bigger;
    }
  }
  s = bigger;
  return *this;
}

bignum & bignum::operator-(bignum & a)
{
  
  int l1 = (int)a.s.length();
  int l2 = (int)s.length();
  vector<int> array1(l1), array2(l2), bigger, smaller;
  int jw = 0, loca = 0;
  bool f = false;
  string s1;
  for (int i = 1; i <= l1; i++) {
    array1[i - 1] = atoi((a.s.substr(l1 - i, 1)).c_str());
  }
  for (int i = 1; i <= l2; i++) {
    array2[i - 1] = atoi((s.substr(l2 - i, 1)).c_str());
  }
  if (l1 > l2) {
    bigger = array1;
    smaller = array2;
    f = true;
  }
  else if (l2 > l1) {
    smaller = array1;
    bigger = array2;
  }
  else if (l2 == l1) {
    for (int i = l1 - 1; i >= 0; i--) {
      if (array1[i] > array2[i]) {
        bigger = array1;
        smaller = array2;
        f = true;
        break;
      }
      else if (array2[i] > array1[i]) {
        smaller = array1;
        bigger = array2;
        break;
      }
      else if (i == 0) {
        s = "0";
        return *this;
      }
    }
  }
  for (int i = 0; i < smaller.size(); i++) {
    bigger[i] = bigger[i] - smaller[i] + jw;
    jw = 0;
    if (bigger[i] < 0) {
      bigger[i] += 10;
      jw = -1;
    }
    if (i == smaller.size() - 1 && jw == -1) {
      bigger[i + 1] -= 1;
    }
  }
  for (int i = (int)bigger.size() - 1; i >= 0; i--) {
    if (bigger[i] != 0) {
      loca = i;
      break;
    }
  }
  for (int i = 0; i <= loca; i++) {
    string c;
    c = to_string(bigger[i]);
    s1 = c + s1;
  }
  if (f) {
    s1 = "-" + s1;
  }
  s = s1;
  // TODO: 在此处插入 return 语句
  return *this;
}

bignum & bignum::operator*(bignum & a)
{
  if (s == "0" || a.s == "0") {
    s = "0";
    return *this;
  }
  int l1 = (int)a.s.length();
  int l2 = (int)s.length();
  int jw = 0, jg = 0;
  string s1;
  vector<int> array1(l1), array2(l2);//乘数，被乘数
  for (int i = 1; i <= l1; i++) {
    array1[i - 1] = atoi((a.s.substr(l1 - i, 1)).c_str());
  }
  for (int i = 1; i <= l2; i++) {
    array2[i - 1] = atoi((s.substr(l2 - i, 1)).c_str());
  }
  for (int i = 0; i < l1 + l2 - 1; i++) {
    jg = 0;
    for (int j = 0; j < l1; j++) {
      if (j > i)
        break;
      for (int k = 0; k < l2; k++) {
        if (k + j == i) {
          jg = jg + array1[j] * array2[k];
        }
      }
    }
    jg += jw;
    jw = 0;
    if (jg >= 10) {
      while (jg >= 10) {
        jg -= 10;
        jw++;
      }
    }
    string c;
    c = to_string(jg);
    s1 = c + s1;
    if (i == l1 + l2 - 2 && jw != 0) {
      c = to_string(jw);
      s1 = c + s1;
    }
  }
  s = s1;
  // TODO: 在此处插入 return 语句
  return *this;
}

bignum & bignum::operator/(bignum & a)
{
  if(a.s == "0") {
    s = "error";
    return *this;
  }
  else if(s == "0") {
    return *this;
  }
  else if(compare(s, a.s) < 0) {
    s = "0";
    return *this;
  }
  else if (compare(s, a.s) == 0) {
    s = "1";
    return *this;
  }
  else {
    string temp, q;
    int lsize, rsize;
    lsize = (int)s.size();
    rsize = (int)a.s.size();
    int i;
    if(rsize > 1) temp.append(s, 0, rsize - 1);
    for(i = rsize - 1; i < lsize; i++) {
      temp = temp + s[i];
      for(char c = '9'; c >= '0'; c--) {
        string c1(1, c);
        bignum c2(c1);
        bignum t1(temp);
        bignum a1(a);
        bignum t = a1 * c2;
        bignum s1 = t1 - t;
        if(s1.s[0] != '-') {
          temp = s1.s;
          q = q + c;
          break;
        }
      }
    }
    q.erase(0, q.find_first_not_of('0'));
    s = q;
  }
  // TODO: 在此处插入 return 语句
  return *this;
}

ostream & operator<<(ostream & os, const bignum & a)
{
  // TODO: 在此处插入 return 语句
  cout << a.s << endl;
  return os;
}

istream & operator >> (istream & is, bignum & a)
{
  // TODO: 在此处插入 return 语句
  string s1;
  is >> s1;
  a.s = s1;
  return is;
}

int main()
{
  bignum a, b;
  char c;
  cin >> a >> c >> b;
  switch (c)
  {
    case '+':
      cout << a + b;
      break;
    case '-':
      cout << a - b;
      break;
    case '*':
      cout << a * b;
      break;
    case '/':
      cout << a / b;
      break;
    default:
      cout << "wrong operator" << endl;
      break;
  }
  return 0;
}