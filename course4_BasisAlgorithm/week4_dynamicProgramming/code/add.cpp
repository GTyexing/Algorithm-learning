/*编程题＃1：集合加法

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 3000ms 内存限制: 65536kB

描述

给出2个正整数集合A = {pi | 1 <= i <= a}，B = {qj | 1 <= j <= b}和一个正整数s。问题是：使得pi + qj = s的不同的(i, j)对有多少个。

输入

第1行是测试数据的组数n，后面跟着n组测试数据。

每组测试数据占5行，第1行是和s (1 <= s <= 10000)，第2行是一个正整数a (1 <= a <= 10000)，表示A中元素的数目。第3行是a个正整数，每个正整数不超过10000，表示A中的元素。第4行是一个正整数b (1 <= b <= 10000)，表示B中元素的数目。第5行是b个正整数，每个正整数不超过10000，表示B中的元素。

注意：这里的集合和数学书上定义的集合有一点点区别——集合内可能包含相等的正整数。

输出

n行，每行输出对应一个输入。输出应是一个非负整数。
样例输入
2
99
2
49 49
2
50 50
11
9
1 2 3 4 5 6 7 8 9
10
10 9 8 7 6 5 4 3 2 1
样例输出
4
9
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
  // insert code here...
  int n, sum = 0, first = 0, second = 0, total = 0;
  int count[10000] = {0};
  cin >> n;
  int j = 0;
  while(n--) {
    priority_queue<int> b;
    priority_queue<int, vector<int>, greater<int> > a;
    cin >> sum >> first;
    for(int i = 0; i < first; i++) {
      cin >> j;
      a.push(j);
    }
    cin >> second;
    for (int i = 0; i< second; i++) {
      cin >> j;
      b.push(j);
    }
    while(a.size()) {
      int a1 = a.top();
      if(count[sum - a1] != 0) {
        total += count[sum - a1];
        a.pop();
        continue;
      }
      while(b.size()) {
        int b1 = b.top();
        if(a1 + b1 < sum) {
          a.pop();
          break;
        }
        if(a1 + b1 == sum) {
          total += 1;
          b.pop();
          count[b1]++;
        } else if (b1 + a1 > sum) b.pop();
      }
      if(b.size() == 0 && a.size() != 0) a.pop();
    }
    cout << total << endl;
    total = 0;
  }
  return 0;
}