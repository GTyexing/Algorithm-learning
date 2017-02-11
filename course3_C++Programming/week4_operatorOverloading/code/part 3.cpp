#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2 {
    int row;
    int col;
    int ** array;
public:
    Array2():array(NULL), row(0), col(0) {}
    Array2(int n, int m) {
        row = n;
        col = m;
        array = new int *[n];
        for (int i = 0; i < n; i++) {
            array[i] = new int[m];
        }
    }
    int operator()(int i, int j) {
        return array[i][j];
    }
    int * operator[](int i) {
        return array[i];
    }
    ~Array2() { if(array) delete [] array; }
    Array2 & operator=(const Array2 & n);
};

Array2 & Array2::operator=(const Array2 & n) {
    if (array == n.array) {
        return *this;
    }
    if (n.array == NULL) {
        array = NULL;
        return *this;
    }
    if (array) delete[] array;
    row = n.row;
    col = n.col;
    array = new int*[row];
    for (int i = 0; i < row; i++) {
        array[i] = new int[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = n.array[i][j];
        }
    }
    return *this;
}

int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     
    b = a;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            int c = b[i][j];
            cout << c << ",";
        }
        cout << endl;
    }
    return 0;
}