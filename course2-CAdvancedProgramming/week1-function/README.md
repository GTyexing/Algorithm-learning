#C程序中的函数

##函数的定义和声明

```c++
int f(int n) {
  return n;
}
```
 
- int 代表函数返回值的类型，可以是其他类型，如果函数不需要返回值，使用viod
 
- f 函数的名称
 
- (int n) 函数接收的形参
 
***

##数组做参数
 
```c++
#include<iostream>
using namespace std;
 
void change(int a, int b) {
  a = 30;
  b = 50;
}
 
int main() {
  int a = 3， b =  5；
  change(a, b);
  cout << a << " " << b << endl;
  return 0;
} // 输出: 3 5
```
 

- 实参与形参具有**不同的储存单元**，实参与形参变量的数据传递是“值传递”
- 函数调用时， 系统给形参分配储存单元，并将实参对应的**值**传递给形参
 
```c++
#include<iostream>
using namespace std;
 
void change(int a[]) {
  a[0] = 30;
  a[1] = 50;
}
 
int main() {
  int a[2] = {3， 5}；
  change(a);
  cout << a << " " << b << endl;
  return 0;
} // 输出: 30 50
```
 
但数组名做参数的情况下，传入的是数组在**内存中的地址**，所以会真正的改变数组。
