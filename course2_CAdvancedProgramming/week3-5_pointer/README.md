#指针

##指针：变量的地址

```C++
int a = 0;
cout << &a << endl; // 打印a在内存中的地址
cout << *&a << endl; //打印地址内的资源即变量**a**
```

##指针变量：用于存放指针的变量。

```C++
int a = 0;
int *pointer;
pointer = &a;
cout << *pointer << endl; //打印pointer所指向的储存单元的内容即**变量c**
// pointer => 变量的名字
// * => 指针运算符，标识变量的类型
// int => 指针变量基类型，即指针变量指向的变量的类型
```

##数组与指针

```C++
int a[4] = {1, 2, 3, 4};
int *pointer;
pointer = a; // a => 数组名**相当于**指向数组第一个元素的指针，即指向a[0]的指针, a是地址常量，不能赋值

cout << a << endl; //a[0]的地址
cout << &a << endl; //同样时a[0]的地址，但&a相当于指向整个数组的指针
cout << *a << endl; //a[0]的值，即a[0]的地址里存放的值
//因此可以看作 & 为a提升了管辖范围，*缩小了a的管辖范围

cout << a + i << pointer + i << endl; // &a[i], a[i]的地址
cout << *(a + 1) << *pointer++ << endl; // a[1]的值，++，--优先级比*高， 因为a是地址常量, a++没有意义
```

##字符串与指针

与数组十分相似
```C++
int *p;
pc = "hello"; //可以直接赋值，不同与字符数组只能在初始化时赋值，但是不同通过pc去修改'hello'的值
```

##函数与指针

- 做参数
    ```C++
    void Rank(int *q1, int *q2) {
        int temp;
        if(*q1 < *q2) {
            temp = *q1;
            *q1 = *q2;
            *q2 = temp;
        }
    }
    int main() {
        int a, b, *p1, *p2;
        cin >> a >> b;
        p1 = &a; p2 = &b;
        Rank(p1, p2);
        cout << a << " " << b << endl;
    } //因为传去的是地址，所以a, b会互换，所以用指针变量做实参是比较危险的，必要时可以使用void Rank( const int *q1, const int *q2){ ... }来保证实参不可变化
    ```
    -数组名做参数
    ```C++
    int sum(int array[], int n) {
        for (int i = 0; i < 10 - 1; i++) {
            *(array + 1) = *array + *(array + 1);
            array++;
        } 
    }
    int main() {
        int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        cout << sum(a, 10);
        return 0;
    } //前面提到过数组名不可以做++运算，但在此处C++编译器会将形参数组名作为指针变量来处理，所以实际上是可以运行的
    ```
- 做返回值
    ```C++
    int *getInt1() {
        int value1 = 20; //static int value1 = 20
        return &value1;
    }
    int main() {
        int *p;
        *p = getInt1();
        cout << *p << endl;
        return 0;
    } //当主函数调用完getInt1后，getInt1即在内存中被销毁，变量value1也随之销毁，所以结果是无法确定的,可以通过定义静态局部变量来解决这个问题
    ```

    - **静态局部变量**，即函数调用后，函数中的局部变量仍占有其储存单元，并保持原值