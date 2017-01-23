/*编程题＃2：四大湖

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

我国有4大淡水湖。

A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。

B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。

C说：洪泽湖最小，洞庭湖第三。

D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。

已知这4个湖的大小均不相等，4个人每人仅答对一个，

请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。

输入

无。

输出

输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。*/

#include<iostream>
using namespace std;

int main() {
	int panyang, dongting, taihu, hongze;
	for (panyang = 1; panyang <= 4; panyang++) {
		for (dongting = 1; dongting <= 4; dongting++) {
			for (taihu = 1; taihu <= 4; taihu++) {
				for (hongze = 1; hongze <= 4; hongze++) {
					if ((panyang != dongting && dongting != taihu && taihu != hongze && panyang != taihu && panyang != hongze && dongting != hongze)
						&& ((dongting == 1) + (hongze == 4) + (panyang == 3) == 1)
						&& ((hongze == 1) + (dongting == 4) + (panyang == 2) + (taihu == 3) == 1)
						&& ((hongze == 4) + (dongting == 3) == 1)
						&& ((panyang == 1) + (taihu == 4) + (hongze == 2) + (dongting == 3) == 1))
					{
						cout << panyang << endl << dongting << endl << taihu << endl << hongze << endl;
					}
				}
			}
		}
	}
	return 0;
}