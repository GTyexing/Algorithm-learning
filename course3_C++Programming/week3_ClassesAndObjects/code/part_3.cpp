/*描述

下面程序的输出结果是：

5,5

5,5*/
#include <iostream>
using namespace std;
class Base {
public:
	int k;
	Base(int n) :k(n) { }
};
class Big {
public:
	int v; 
	Base b;
	// 在此处补充你的代码
	Big(int n, int m = 5): b(n), v(m) { }
	Big(const Big & a): v(a.v), b(a.b) { }
};
int main() {
	Big a1(5);    
	Big a2 = a1;
	cout << a1.v << "," << a1.b.k << endl;
	cout << a2.v << "," << a2.b.k << endl;
	return 0;
}