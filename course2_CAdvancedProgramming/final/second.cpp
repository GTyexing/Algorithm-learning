/*编程题＃2：字符串中次数第2多的字母

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数（如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。

例 ab&dcAab&c9defgb

这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为

D+d:2

(假定在字符串中，次数第2多的字母总存在)

输入

一个字符串

输出

大写字母+小写字母:个数*/
#include<iostream>
using namespace std;

struct s
{
	char letter;
	int count;
};

void compare(char c, int & l, s List[]) {
	bool appear = false;
	for (int j = 0; j < l + 1; j++) {
		if (List[j].letter == c) {
			List[j].count++;
			appear = true;
			break;
		}
	}
	if (appear == false) {
		List[l].letter = c;
		List[l].count = 1;
		l++;
	}
}

int main() {
	char c[501] = { '\0' };
	cin.getline(c, 501);
	int l = 0;
	s Count[26];
	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] >= 'a' && c[i] <= 'z') {
			compare(c[i], l, Count);
		}
		else if (c[i] >= 'A' && c[i] <= 'Z') {
			c[i] += 32;
			compare(c[i], l, Count);
		}
	}

	s larggest = { ' ',0 };
	s second = { ' ',0 };
	for (int i = 0; i < l - 1; i++) {
		if (Count[i].count > larggest.count) {
			second = larggest;
			larggest = Count[i];
		}
		else if (Count[i].count > second.count&& Count[i].count < larggest.count) {
			second = Count[i];
		}
	}

	char temp = second.letter - 32;
	cout << temp << '+' << second.letter << ':' << second.count << endl;
	return 0;
}