#include<iostream>
using namespace std;

int main() {
	int n = 0, day = 0, count = 0;
	char room[100][100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//room[i][j] = cin.get();
			cin >> room[i][j];
		}
	}
	cin >> day;

	for (int i = 1; i < day; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				switch (room[j][k])
				{
				case '1':
					room[j][k] = '@';
					break;
				default:
					break;
				}
			}
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				switch (room[j][k])
				{
				case '@':
					if (room[j - 1][k] == '@' || room[j + 1][k] == '@' || room[j][k - 1] == '@' || room[j][k + 1] == '@')
						room[j][k] = '1';
					break;
				default:
					break;
				}
			}
		}
	}

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			switch (room[j][k])
			{
			case '@':
			case '1':
				count++;
				break;
			default:
				break;
			}
		}
	}

	cout << count <<endl;

	return 0;
}