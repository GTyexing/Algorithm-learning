/*编程题＃2： 滑雪

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

输入

输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

输出

输出最长区域的长度。

样例输入
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出
25
*/
#include <iostream>
#include <algorithm>
using namespace std;
struct dot {
  int row;
  int column;
  int height;
};
dot matrix[101*101], original[101][101];
int column, row;
int length[101][101];

bool compare(dot lhs, dot rhs) {
  return lhs.height<rhs.height;
}

int maxStep(int i)
{
  int maxStep = 1;
  for (int j = 0; j < i; ++j) {
    int r = matrix[j].row;
    int c = matrix[j].column;
    int h = matrix[j].height;
    if (r > 1 && original[r-1][c].height > h) {
      length[r-1][c] = max(length[r-1][c], length[r][c] + 1);
      if (length[r-1][c] > maxStep) {
        maxStep = length[r-1][c];
      }
    }
    if (r < row && original[r+1][c].height > h) {
      length[r+1][c] = max(length[r+1][c], length[r][c] + 1);
      if (length[r+1][c] > maxStep) {
        maxStep = length[r+1][c];
      }
    }
    if (c > 1 && original[r][c-1].height > h) {
      length[r][c-1] = max(length[r][c-1], length[r][c] + 1);
      if (length[r][c-1] > maxStep) {
        maxStep = length[r][c-1];
      }
    }
    if (c < column && original[r][c+1].height > h) {
      length[r][c+1] = max(length[r][c+1], length[r][c] + 1);
      if (length[r][c+1] > maxStep) {
        maxStep = length[r][c+1];
      }
    }
  }
  return maxStep;
}

int main()
{
  cin>>row>>column;
  int k = 0;
  for (int i = 1; i < row+1; ++i) {
    for (int j = 1; j < column+1; ++j) {
      matrix[k].row = i;
      matrix[k].column = j;
      cin>>matrix[k].height;
      original[i][j] = matrix[k];
      length[i][j] = 1; // 所有点的滑行距离先设为1
      k++;
    }
  }
  sort(matrix, matrix + k, compare);
  int maxLength = maxStep(k);
  cout<<maxLength;
  return 0;
}