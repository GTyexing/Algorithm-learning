/*编程题＃1： 画家问题

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

有一个正方形的墙，由N*N个正方形的砖组成，其中一些砖是白色的，另外一些砖是黄色的。Bob是个画家，想把全部的砖都涂成黄色。但他的画笔不好使。当他用画笔涂画第(i, j)个位置的砖时， 位置(i-1, j)、 (i+1, j)、 (i, j-1)、 (i, j+1)上的砖都会改变颜色。请你帮助Bob计算出最少需要涂画多少块砖，才能使所有砖的颜色都变成黄色。*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int puzzle[16][17] = { 0 }, press[16][17] = { 0 };

int guess(int n) {
	int c, r, count = 0;
	for (c = 1; c <= n; c++)
		if (press[1][c] == 1) count++;
	for (r = 1; r <= n; r++)
		for (c = 1; c <= n; c++) {
			press[r + 1][c] = (puzzle[r][c] + press[r][c] +	press[r - 1][c] + press[r][c - 1] + press[r][c + 1]) % 2;
			if (press[r + 1][c] == 1) count++;
		}
	for (c = 1; c <= n; c++)
		if ((press[n][c - 1] + press[n][c] + press[n][c + 1] + press[n - 1][c]) % 2 != puzzle[n][c])
			return -1;
	return count;

}

int enumerate(int n) {
	int c, min = -1, n1 = (int)pow(2, n);
	if (guess(n) != -1) {
		min = guess(n);
	}
	while (--n1) {
		press[1][1]++;
		c = 1;
		while (press[1][c] > 1) {
			press[1][c] = 0;
			c++;
			press[1][c]++;
		}
		int result = guess(n);
		if (result != -1) {
			if (min == -1)
				min = result;
			if (min > result)
				min = result;
		}
	}
	return min;
}

int main() {
	int k = 0, n = 0, m = 1, min = 0;
	char c;
	cin >> k;	
	while (m <= k){
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> c;
				switch (c)
				{
				case 'w':
					puzzle[i][j] = 1;
					break;
				case 'y':
					break;
				}
			}
		}
		int result = enumerate(n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (press[i][j] == 1) {
					press[i][j] = 0;
				}
			}
		}
		cout << result << endl;
		m++;
	}
	return 0;
}