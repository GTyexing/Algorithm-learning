/*编程题＃1 List

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 4000ms 内存限制: 65536kB

描述

写一个程序完成以下命令：

new id ——新建一个指定编号为id的序列(id<10000)

add id num——向编号为id的序列加入整数num

merge id1 id2——合并序列id1和id2中的数，并将id2清空

unique id——去掉序列id中重复的元素

out id ——从小到大输出编号为id的序列中的元素，以空格隔开

输入

第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。

输出

按题目要求输出。*/
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<list<int> > a(10000);
  while(n--) {
    string s;
    cin >> s;
    int x, y;
    list<int> b;
    switch (s.at(0)) {
      case 'n':
        cin >> x;
        a[x - 1] = b;
        break;
      case 'a':
        cin >> x >> y;
        a[x - 1].push_front(y);
        a[x - 1].sort();
        break;
      case 'm':
        cin >> x >> y;
        a[x -1].merge(a[y - 1]);
        break;
      case 'u':
        cin >> x;
        a[x - 1].unique();
        break;
      case 'o':
        cin >> x;
        a[x - 1].sort();
        list<int>::const_iterator i;
        i = a[x - 1].begin();
        for(i = a[x -1].begin(); i != a[x -1].end(); i++)
          cout << *i << ' ';
        cout << endl;
        break;
    }
  }
  return 0;
}