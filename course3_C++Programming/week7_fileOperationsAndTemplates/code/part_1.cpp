/*编程题＃1

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

实现一个三维数组模版CArray3D，可以用来生成元素为任意类型变量的三维数组，使得下面程序输出结果是：

0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,

注意，只能写一个类模版，不能写多个。*/
#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T3>
class CArray3D {
  template <class T2>
  class CArray2D {
    template <class T1>
    class CArray {
      T1 * a;
    public:
      CArray() {
        a = NULL;
      }
      CArray(int i) {
        a = new T1[i];
      }
      T1 & operator[](int i) {
        return a[i];
      }
      ~CArray() {
        if(a != NULL) delete []a;
      }
    };
    CArray<T2> ** b;
    int i;
  public:
    CArray2D() {
      b = NULL;
    }
    CArray2D(int x, int y): i(x) {
      b = new CArray<T2>*[x];
      for (int i = 0; i < x; i++)
        b[i] = new CArray<T2>(y);
    }
    CArray<T2> & operator[](int i) {
      return *b[i];
    }
    ~CArray2D() {
      if(b != NULL) delete []b;
    }
  };
  CArray2D<T3> ** c;
public:
  CArray3D(int x, int y, int z) {
    c = new CArray2D<T3>*[x];
    for (int i = 0; i < x; i++)
      c[i] = new CArray2D<T3>(y, z);
  }
  CArray2D<T3> &operator[](int x) {
    return *c[x];
  }
  ~CArray3D() {
    if(c != NULL) delete []c;
  }
};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}