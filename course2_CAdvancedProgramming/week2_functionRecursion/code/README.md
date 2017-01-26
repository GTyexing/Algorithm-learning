#总结

##关于字符串————字符翻转

当定义了一个字符串时，例如
```c++
char a[501] = "hello world";
char b[501] = {'\0'};
char c[501];
cin.getline(c, 501);// enter "hello world"
bool A = a[200] == '\0';
bool B = b[200] == '\0';
bool C = c[200] == '\0';
cout << A << endl;// 1
cout << B << endl; // 1
cout << C << endl; // 0
```
a:字符串初始化时赋值的情况下，最后一个字母后任意位都等于'\0'。

b:如果对字符串进行了如 b 的初始化，则任意位都为'\0'。

c:未进行初始化，后采用cin.getline()赋值这只有最后一个字母后一位等于'\0'.