#include<iostream>  
using namespace std;

int main() {  
  int row, col;  
  cin >> row >> col;  
  int shuzu[100][100];  
  for (int j = 0; j < row; j++) {  
    for (int o = 0; o < col; o++) {  
      cin >> shuzu[j][o];  
    }  
  }  
  int k = col + row - 1;
  for (int i = 0; i <= k; i++) { 
    int c = i;
    for (int r = 0; r < row; r++) {  
        if (r + c == i&&r < row&&c < col&&c>=0) {  
          cout << *(*(shuzu + r) + c) << endl; 
        }  
        c--; 
      }  
        
  }  
  return 0;  
}  