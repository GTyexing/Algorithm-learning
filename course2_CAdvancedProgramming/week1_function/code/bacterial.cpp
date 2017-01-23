/*编程题＃5：细菌实验分组

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，仅仅在繁殖能力上有显著差别，A亚种繁殖能力非常强，B亚种的繁殖能力很弱。在一次为时一个 小时的细菌繁殖实验中，实验员由于疏忽把细菌培养皿搞乱了，请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分成两组。

输入

输入有多行，第一行为整数n（n≤100），表示有n个培养皿。

其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。

输出

输出有多行：

第一行输出A亚种培养皿的数量，其后每行输出A亚种培养皿的编号，按繁殖率升序排列。

然后一行输出B亚种培养皿的数量，其后每行输出B亚种培养皿的编号，也按繁殖率升序排列。*/
#include<iostream>
using namespace std;

int main() {
	int n, id[100], before, after, index;
	double array[100], diff = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id[i] >> before >> after;
		array[i] = (double)after / before;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[i] > array[j]) {
				double temp = array[j];
				int tem = id[j];
				array[j] = array[i];
				id[j] = id[i];
				array[i] = temp;
				id[i] = tem;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		if (array[i + 1] - array[i] > diff) {
			diff = array[i + 1];
			index = i + 1;
		}
	}

	cout << n - index << endl;
	for (int i = index; i < n; i++) {
		cout << array[i] << endl;
	}
	cout << index << endl;
	for (int i = 0; i < index; i++) {
		cout << array[i] << endl;
	}
	return 0;
}