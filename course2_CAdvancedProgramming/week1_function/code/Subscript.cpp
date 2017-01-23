/*编程题＃1：寻找下标

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

已知一个整数数组x[],其中的元素彼此都不相同。找出给定的数组中是否有一个元素满足x[i]=i的关系，数组下标从0开始。

举例而言，如果x[]={-2,-1,7,3,0,8},则x[3] = 3,因此3就是答案。

输入

第一行包含一个整数n (0 < n < 100)，表示数组中元素的个数。<br />第二行包含n个整数，依次表示数组中的元素。

输出

输出为一个整数，即满足x[i]=i的元素，若有多个元素满足，输出第一个满足的元素。若没有元素满足，则输出“N”。*/
#include<iostream>
using namespace std;

int same(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == i)
			return i;
	}
	return 100;
}

int main() {
	int n, a[100] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int c = same(a, n);
	switch (c)
	{
	case 100:
		cout << 'N' << endl;
		break;
	default:
		cout << c << endl;
		break;
	}
	return 0;
}