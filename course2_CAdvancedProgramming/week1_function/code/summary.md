#总结

##关于cin>>

在做**流感传染**的题目时，之前的代码是这样的

```c++
	int n = 0, day = 0, count = 0;
	char room[100][100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			room[i][j] = cin.get();
		}
	}
	cin >> day;
```

在测试输入时如
```
2
..
..
```
总是在未输入变量day之前就运行出了结果。

后来发现原因在于cin.get()是会读取**回车**的, 而当我敲入了第一个变量n时键入了回车。在c++中当我键入回车时，输入的内容会被放入**输入缓冲区**, **输入缓冲区**中存在一个**指针**用于标明哪些字符是已经被读取了的，cin读取了n之后，指针指向了n之后的回车，而cin.get()是会读取回车的，所以程序读入的四个char是 **[Enter] . . [Enter]**，而变量day因为类型不符合没有被成功赋值。

解决方案
```c++
	int n = 0, day = 0, count = 0;
	char room[100][100];
	cin >> n;
	cin.get();//读掉回车
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			room[i][j] = cin.get();
		}
		cin.get();//读掉回车
	}
	cin >> day;
```
or
```c++
	int n = 0, day = 0, count = 0;
	char room[100][100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> room[i][j];
		}
	}
	cin >> day;
```

###cin.get()和cin.getline()
```c++
#include<iostream>
using namespace std;

int main() {
	char ch[20];
	cin.getline(ch, 10, 'o');
	return 0;
}
```
输入示例
```
We are good friend.
```
输出示例
```
We are go
```
两者都可用于接收字符串，用法相似可以接受三个参数（变量名，接受长度，终止符），以上述代码为例变量为 **ch** , 最大接收长度为**10-1=9**，在读取到九个字符之前如果遇到了终止字符'o'，就会提前结束。

####不同点
此时在输入缓冲区中，指针指向**od friend.**，即终止字符之后

而如果是cin.get()的话，指针将指向**ood friend**，即终止字符之前



