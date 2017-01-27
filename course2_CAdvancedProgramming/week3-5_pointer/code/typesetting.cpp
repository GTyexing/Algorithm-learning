#include<iostream>
#inclide<cstring>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	char c[1000][41] = { '\0' };
	cin.get();
	for (int i = 0; i < n; i++) {
		char a;
		for (int j = 0; j <= 40; j++) {
			cin.get(a);
			if (a != ' ' && a != '\n') {
				c[i][j] = a;
			}
			else {
				break;
			}
		}
	}

	int length = strlen(*c);
	cout << *c;
	for (int i = 1; i < n; i++) {
		if (length + 1 + strlen(*(c + i)) <= 80) {
			length = length + 1 + strlen(*(c + i));
			cout << ' ' << *(c + i);
		}
		else {
			cout << endl;
			length = strlen(*(c + i));
			cout << *(c + i);
		}
	}
	return 0;
}