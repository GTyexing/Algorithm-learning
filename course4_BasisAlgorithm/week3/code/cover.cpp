/*
编程题＃1： 完美覆盖

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

一张普通的国际象棋棋盘，它被分成 8 乘 8 (8 行 8 列) 的 64 个方格。设有形状一样的多米诺牌，每张牌恰好覆盖棋盘上相邻的两个方格，即一张多米诺牌是一张 1 行 2 列或者 2 行 1 列的牌。那么，是否能够把 32 张多米诺牌摆放到棋盘上，使得任何两张多米诺牌均不重叠，每张多米诺牌覆盖两个方格，并且棋盘上所有的方格都被覆盖住？我们把这样一种排列称为棋盘被多米诺牌完美覆盖。这是一个简单的排列问题，同学们能够很快构造出许多不同的完美覆盖。但是，计算不同的完美覆盖的总数就不是一件容易的事情了。不过，同学们 发挥自己的聪明才智，还是有可能做到的。

现在我们通过计算机编程对 3 乘 n 棋盘的不同的完美覆盖的总数进行计算。


任务

对 3 乘 n 棋盘的不同的完美覆盖的总数进行计算。

输入

一次输入可能包含多行，每一行分别给出不同的 n 值 ( 即 3 乘 n 棋盘的列数 )。当输入 -1 的时候结束。

n 的值最大不超过 30.

输出

针对每一行的 n 值，输出 3 乘 n 棋盘的不同的完美覆盖的总数。*/
#include <iostream>
using namespace std;

int record[2][30] = { 0 };

int count(int type, int n) {
  switch (type) {
    case 1:
      if(record[1][n] != 0) return record[1][n];
      if(n == 0) return 1;
      if(n == 1) return 0;
      else {
        int result = 2 * count( -1 * type, n - 1) + count(type, n - 2);
        record[1][n] = result;
        return result;
      }
    break;
    default:
      if(record[0][n] != 0) return record[0][n];
      if(n == 1) return 1;
      if(n == 0) return 0;
      else {
        int result = count(-1 * type, n - 1) + count(type, n - 2);
        record[0][n] = result;
        return result;
      }
    break;
  }
}

int main(int argc, const char * argv[]) {
  // insert code here...
  int col = 0;
  cin >> col;
  while (col != -1) {
    if(col % 2 != 0) cout << 0 << endl;
    else cout << count(1, col) + count(-1, col) << endl;
    cin >> col;
  }
  return 0;
}