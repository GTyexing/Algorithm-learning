/*编程题＃3：发票统计

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

有一个小型的报账系统，它有如下功能：

（1）统计每个人所报发票的总钱数

（2）统计每类发票的总钱数

将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。

输入

系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。

输出

输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。*/
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	float sum[3] = { 0 }, sumA = 0, sumB = 0, sumC = 0;
	for (int i = 0; i < 3; i++) {
		int id = 0, count = 0;
		cin >> id >> count;
		for (int j = 0; j < count; j++) {
			char type;
			float num;
			cin >> type >> num;
			switch (type)
			{
			case 'A':
				sumA += num;
				break;
			case 'B':
				sumB += num;
				break;
			case 'C':
				sumC += num;
				break;
			default:
				break;
			}
			sum[id - 1] += num;
		}
	}

	cout << fixed <<setprecision(2)
		<< 1 << ' ' << sum[0] << endl
		<< 2 << ' ' << sum[1] << endl
		<< 3 << ' ' << sum[2] << endl
		<< 'A' << ' ' << sumA << endl
		<< 'B' << ' ' << sumB << endl
		<< 'C' << ' ' << sumC;

	return 0;
} 