/*编程题＃3：寻找山顶

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

在一个m×n的山地上，已知每个地块的平均高程，请求出所有山顶所在的地块（所谓山顶，就是其地块平均高程不比其上下左右相邻的四个地块每个地块的平均高程小的地方)。

输入

第一行是两个整数，表示山地的长m（5≤m≤20）和宽n（5≤n≤20）。

其后m行为一个m×n的整数矩阵，表示每个地块的平均高程。每行的整数间用一个空格分隔。

输出

输出所有上顶所在地块的位置。每行一个。按先m值从小到大，再n值从小到大的顺序输出。*/
#include<iostream>
using namespace std;

int main() {
	int m, n, mountain[20][20] = {0};
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> *(*(mountain + i) + j);
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ((*(*(mountain + i - 1) + j) <= *(*(mountain + i) + j) || i == 0)
			 && (*(*(mountain + i + 1) + j) <= *(*(mountain + i) + j) || i == m - 1)
			 && (*(*(mountain + i) + j - 1) <= *(*(mountain + i) + j) || j == 0)
			 && (*(*(mountain + i) + j + 1) <= *(*(mountain + i) + j) || j == n - 1)) {
				cout << i << ' ' << j << endl;
			}
		}
	}
	return 0;
}