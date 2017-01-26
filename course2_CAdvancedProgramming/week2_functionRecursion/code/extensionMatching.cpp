/*编程题＃4：扩号匹配问题

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.

输入

输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100

注意：cin.getline(str,100)最多只能输入99个字符！

输出

对每组输出数据，!!!输出两行，第一行包含原始输入字符!!!，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。*/
#include<iostream>
using namespace std;

int match(char a[], int i, int n = 0) {
	if (a[i] == '\0') {
		if (n != 0) {
			return 101;
		}
	} 
	else if (a[i] != '(' && a[i] != ')') {
		a[i] = ' ';
		match(a, i + 1, n);
	}
	else if (a[i] == '(') {
		int another = match(a, i + 1, n + 1);
		if (another == 101) {
			a[i] = '$';
			return another;
		}  
		else {
			a[i] = ' ';
			a[another] = ' ';
			match(a, another + 1, n);
		}
	}
	else if (a[i] == ')') {
		if (n == 0) {
			a[i] = '?';
			match(a, i + 1, n);
		}
		else {
			n -= 1;
			return i;
		}
	}
}

int main() {
	char n[101];
	while (cin.getline(n, 101)) {
		cout << n << endl;
		match(n, 0, 0);
		cout << n << endl;
	}
	return 0;
}