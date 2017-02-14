/*编程题＃2：拨钟问题

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

有9个时钟，排成一个3*3的矩阵。
 |-------|    |-------|    |-------|
 |       |    |       |    |   |   |
 |---O   |    |---O   |    |   O   |
 |       |    |       |    |       |
 |-------|    |-------|    |-------|    
     A            B            C    
 |-------|    |-------|    |-------|
 |       |    |       |    |       |
 |   O   |    |   O   |    |   O   |
 |   |   |    |   |   |    |   |   |
 |-------|    |-------|    |-------|    
     D            E            F    
 |-------|    |-------|    |-------|
 |       |    |       |    |       |
 |   O   |    |   O---|    |   O   |
 |   |   |    |       |    |   |   |
 |-------|    |-------|    |-------|    
     G            H            I    
现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。


移动    影响的时钟  
 1        ABDE 
 2        ABC 
 3        BCEF 
 4        ADG 
 5        BDEFH 
 6        CFI 
 7        DEGH 
 8        GHI 
 9        EFHI 
输入

从标准输入设备读入9个整数，表示各时钟指针的起始位置。0=12点、1=3点、2=6点、3=9点。

输出

输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号大小，输出结果。

样例输入*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int a[9] = { 0 }, a2[9] = { 0 }, action[9] = { 0 }, min = 28, Min[9] = { 0 };
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		a2[i] = a[i];
	}
	for (action[0] = 0; action[0] < 4; action[0]++) {
		for (action[1] = 0; action[1] < 4; action[1]++) {
			for (action[2] = 0; action[2] < 4; action[2]++) {
				a[0] = (action[0] + action[1] + a2[0]) % 4;
				a[1] = (action[0] + action[1] + action[2] + a2[1]) % 4;
				a[2] = (action[1] + action[2] + a2[2]) % 4;
				a[3] = (action[0] + a2[3]) % 4;
				a[4] = (action[0] + action[2] + a2[4]) % 4;
				a[5] = (action[2] + a2[5]) % 4;
				action[3] = (4 - a[0]) % 4; 
				action[4] = (4 - a[1]) % 4; 
				action[5] = (4 - a[2]) % 4;
				a[3] = (a[3] + action[3] + action[4]) % 4;
				action[6] = (4 - a[3]) % 4;
				a[5] = (a[5] + action[4]) % 4;
				action[8] = (4 - a[5]) % 4;
				a[6] = (a2[6] + action[6] + action[3]) % 4;
				a[7] = (a2[7] + action[4] + action[6] + action[8]) % 4;
				if (a[6] == a[7]) {
					a[8] = (a2[8] + action[5] + action[8]) % 4;
					if (a[7] == a[8]) {
						action[7] = (4 - a[8]) % 4;
						int total = action[0] + action[1] + action[2] + action[3] + action[4] + action[5] + action[6] + action[7] + action[8];
						if (total < min) {
							cout << total << endl;
							min = total;
							for (int i = 0; i < 9; i++) {
								Min[i] = action[i];
								a[i] = a2[i];
								if (i > 2) action[i] = 0;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		int j = Min[i];
		while (j--)
			cout << i + 1 << ' ';
	}
	cout << endl;
 	return 0;
}