/*编程题＃5：走出迷宫

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。

假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。

输入

第一行是两个整数n和m(1 <= n,m <= 100)，表示迷宫的行数和列数。

接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。

输出

输出从起点到出口最少需要走的步数。(你不能起出迷宫外)*/
#include<iostream>
using namespace std;

int had[100][100] = { 0 },
	history[100][100] = { 0 },
	row, col, ex, ey;
char c[100][100];

int find(int sx, int sy) {
	if (sx == ex && sy == ey) {
		return 0;
	}
	if (history[sx][sy] != 0) {
		return history[sx][sy];
	}
	int min = 10000;
	if (sx > 0 && had[sx - 1][sy] == 0 && c[sx -1][sy] != '#') {
		had[sx - 1][sy] = 1;
		int result = find(sx - 1, sy) + 1;
		if (result < min) {
			min = result;
		}
		had[sx - 1][sy] = 0;
	}
	if (sx + 1 < row && had[sx + 1][sy] == 0 && c[sx + 1][sy] != '#') {
		had[sx + 1][sy] = 1;
		int result = find(sx + 1, sy) + 1;
		if (result < min) {
			min = result;
		}
		had[sx + 1][sy] = 0;
	}
	if (sy > 0 && had[sx][sy - 1] == 0 && c[sx][sy - 1] != '#') {
		had[sx][sy - 1] = 1;
		int result = find(sx, sy - 1) + 1;
		if (result < min) {
			min = result;
		}
		had[sx][sy - 1] = 0;
	}
	if (sy + 1 < col && had[sx][sy + 1] == 0 && c[sx][sy + 1] != '#') {
		had[sx][sy + 1] = 1;
		int result = find(sx, sy + 1) + 1;
		if (result < min) {
			min = result;
		}
		had[sx][sy + 1] = 0;
	}
	if (min != 10000)
		history[sx][sy] = min;
	return min;
}

int main() {
	int sx, sy;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> c[i][j];
			if (c[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (c[i][j] == 'T') {
				ex = i;
				ey = j;
			}
		}
	}
	cout << find(sx, sy) << endl;
	return 0; 
} 