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
#include <cmath>
#include <vector>
using namespace std;

class bignum {
	string s;
public:
	bignum()  {}
	bignum(string s1): s(s1) {}
	bignum & operator+(bignum & a);
	bignum & operator-(bignum & a);
	bignum & operator*(bignum & a);
	bignum & operator/(bignum & a);
	bool operator< (bignum & a);
	friend ostream & operator<<(ostream & os, const bignum & a);
	friend istream & operator>>(istream & is, bignum & a);
};

bool bignum::operator< (bignum & a) {
	int l1 = a.s.length();
	int l2 = s.length();
	if (l1 < l2) {
		return false;
	}
	else if (l1 > l2) {
		return true;
	}
	vector<int> array1(l1), array2(l2);
	for (int i = 1; i <= l1; i++) {
		array1[i - 1] = atoi((a.s.substr(l1 - i, 1)).c_str());
	}
	for (int i = 1; i <= l2; i++) {
		array2[i - 1] = atoi((s.substr(l2 - i, 1)).c_str());
	}
	for (int i = l1 - 1; i >= 0; i--) {
		if (array1[i] > array2[i]) {
			return true;
		}
		else if (array2[i] > array1[i]) {
			return false;
		}
		else if (i == 0) {
			return false;
		}
	}
}

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
	int d = bigger.length() - smaller.length();
	for (int i = 0; i < d; i++) {
		smaller = "0" + smaller;
	}
	int l = bigger.length();
	for (int i = 1; i <= l; i++) {
		string m = bigger.substr(l - i, 1);
		string n = smaller.substr(l - i, 1);
		int j = atoi(m.c_str()) + atoi(n.c_str()) + jw;
		jw = 0;
		if (j >= 10) {
			j -= 10;
			jw = 1;
		}
		char c[2];
		_itoa_s(j, c, 10);
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

	int l1 = a.s.length();
	int l2 = s.length();
	vector<int> array1(l1), array2(l2), bigger, smaller;
	int jw = 0, jg = 0, loca = 0;
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
	for (int i = bigger.size() - 1; i >= 0; i--) {
		if (bigger[i] != 0) {
			loca = i;
			break;
		}
	}
	for (int i = 0; i <= loca; i++) {
		char c[2];
		_itoa_s(bigger[i], c, 10);
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
	int l1 = a.s.length();
	int l2 = s.length();
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
		char c[2];
		_itoa_s(jg, c, 10);
		s1 = c + s1;
		if (i == l1 + l2 - 2 && jw != 0) {
			_itoa_s(jw, c, 10);
			s1 = c + s1;
		}
	}
	s = s1;
	// TODO: 在此处插入 return 语句
	return *this;
}

bignum & bignum::operator/(bignum & a)
{
	if (*this < a) {
		s = "0";
		return *this;
	}
	int l1 = s.length();
	int l2 = a.s.length();
	int la = l1 - l2 + 1;
	int max = pow(10, la) - 1;
	int min = pow(10, la - 2);
	if (min < 1) min = 1;
	int test = (max + min) / 2;
	string s1 = to_string(test);
	bignum b(s1);
	while (min != max - 1)
	{
		if (b * a < *this) {
			min = test;
		}
		else {
			max = test;
		}
		test = (max + min) / 2;
		s1 = to_string(test);
		b = s1;
	}
	s1 = to_string(min);
	s = s1;
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