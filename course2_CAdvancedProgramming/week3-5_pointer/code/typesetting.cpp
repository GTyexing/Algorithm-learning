/*编程题＃3：文字排版

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

给一段英文短文，单词之间以空格分隔（每个单词包括其前后紧邻的标点符号）。请将短文重新排版，要求如下：

每行不超过80个字符；每个单词居于同一行上；在同一行的单词之间以一个空格分隔；行首和行尾都没有空格。

输入

第一行是一个整数n，表示英文短文中单词的数目. 其后是n个以空格分隔的英文单词（单词包括其前后紧邻的标点符号，且每个单词长度都不大于40个字母）。

输出

排版后的多行文本，每行文本字符数最多80个字符，单词之间以一个空格分隔，每行文本首尾都没有空格。*/
#include<iostream>
#inclide<cstring>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	char c[1000][41] = { '\0' };
	cin.get();
	for (int i = 0; i < n; i++) {
		char a;
		for (int j = 0; j <= 40; j++) {
			cin.get(a);
			if (a != ' ' && a != '\n') {
				c[i][j] = a;
			}
			else {
				break;
			}
		}
	}

	int length = strlen(*c);
	cout << *c;
	for (int i = 1; i < n; i++) {
		if (length + 1 + strlen(*(c + i)) <= 80) {
			length = length + 1 + strlen(*(c + i));
			cout << ' ' << *(c + i);
		}
		else {
			cout << endl;
			length = strlen(*(c + i));
			cout << *(c + i);
		}
	}
	return 0;
}