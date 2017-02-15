/*编程题＃2： 文件结构“图”

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

在计算机上看到文件系统的结构通常很有用。Microsoft Windows上面的"explorer"程序就是这样的一个例子。但是在有图形界面之前，没有图形化的表示方法的，那时候最好的方式是把目录和文件的结构显示成一个"图"的样子，而且使用缩排的形式来表示目录的结构。比如：
ROOT
|         dir1
|         |         file1
|         |         file2
|         |         file3
|         dir2
|         dir3
|         |         file1
file1
file2
这个图说明：ROOT目录包括两个文件和三个子目录。第一个子目录包含3个文件，第二个子目录是空的，第三个子目录包含一个文件。

输入

你的任务是写一个程序读取一些测试数据。每组测试数据表示一个计算机的文件结构。每组测试数据以'*'结尾，而所有合理的输入数据以'#'结尾。一组测试数据包括一些文件和目录的名字（虽然在输入中我们没有给出，但是我们总假设ROOT目录是最外层的目录）。在输入中,以']'表示一个目录的内容的结束。目录名字的第一个字母是'd'，文件名字的第一个字母是'f'。文件名可能有扩展名也可能没有（比如fmyfile.dat和fmyfile）。文件和目录的名字中都不包括空格。

输出

在显示一个目录中内容的时候，先显示其中的子目录（如果有的话），然后再显示文件（如果有的话）。文件要求按照名字的字母表的顺序显示（目录不用按照名字的字母表顺序显示，只需要按照目录出现的先后显示）。对每一组测试数据，我们要先输出"DATA SET x:"，这里x是测试数据的编号（从1开始）。在两组测试数据之间要输出一个空行来隔开。

你需要注意的是，我们使用一个'|'和5个空格来表示出缩排的层次。
样例输入
file1
file2
dir3
dir2
file1
file2
]
]
file4
dir1
]
file3
*
file2
file1
*
#
样例输出
DATA SET 1:
ROOT
|        dir3
|        |        dir2
|        |        file1
|        |        file2
|        dir1
file1
file2
file3
file4
DATA SET 2:
ROOT
file1
file2
提示

一个目录和它的子目录处于不同的层次

一个目录和它的里面的文件处于同一层次

*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct waitToP {
  string fn;
  int level;
  waitToP(string s, int i): fn(s), level(i) {}
};

stack<waitToP> wtp;

bool compare(const waitToP & s1, const waitToP & s2) {
  return s1.fn < s2.fn;
}

void printFileSystem(vector<string> s, int size, int set, int now = 0, int startFrom = 0, int level = 0) {
  if (s[now][0] == 'f' && now < size) {
    wtp.push(waitToP(s[now], level));
    printFileSystem(s, size, set, now + 1, startFrom, level);
  } else if (s[now][0] == 'd' && now < size) {
    level++;
    for(int i = 0; i < level; i++) cout << "|     ";
    cout << s[now] << endl;
    printFileSystem(s, size, set, now + 1, startFrom, level);
  } else if (s[now][0] == ']' && now < size) {
    waitToP w = wtp.top();
    vector<waitToP> v;
    while(w.level == level) {
      v.push_back(w);
      wtp.pop();
      if(wtp.size() != 0) w = wtp.top();
      else break;
    }
    sort(v.begin(), v.end(), compare);
    for(int j = 0; j < v.size(); j++) {
      for(int i = 0; i < level; i++) cout << "|     ";
      cout << v[j].fn << endl;
    }
    level--;
    printFileSystem(s, size, set, now + 1, startFrom, level);
  } else if (s[now][0] == '*' && now < size) {
    waitToP w = wtp.top();
    vector<waitToP> v;
    while(w.level == level) {
      v.push_back(w);
      wtp.pop();
      if(wtp.size() != 0) w = wtp.top();
      else break;
    }
    sort(v.begin(), v.end(), compare);
    for(int j = 0; j < v.size(); j++) {
      for(int i = 0; i < level; i++) cout << "|     ";
      cout << v[j].fn << endl;
    }
    if(now + 1 < size) {
      cout << endl;
      cout << "DATA SET " << set + 1 << ":" << endl;
      cout << "ROOT" << endl;
    }
    printFileSystem(s, size, set + 1, now + 1, now + 1, level);
  }
}

int main(int argc, const char * argv[]) {
  // insert code here...
  vector<string> s;
  string s1;
  int i = 0;
  cin >> s1;
  while(s1 != "#") {
    s.push_back(s1);
    i++;
    cin >> s1;
  }
  cout << "DATA SET 1:" << endl;
  cout << "ROOT" << endl;
  printFileSystem(s, (int)s.size(), 1);
  return 0;
}
