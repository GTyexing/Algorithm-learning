/*编程题＃4：Tomorrow never knows？

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。

读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。

输入

输入仅一行，格式为yyyy-mm-dd的日期。

输出

输出也仅一行，格式为yyyy-mm-dd的日期*/
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int year, month, day;
	char a, b;
	bool isLeap = false;

	cin >> year >> a >> month >> b >> day;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		isLeap = true;
	}

	switch (month)
	{
	case 1: 
	case 3: 
	case 5:
	case 7: 
	case 8:
	case 10:
	case 12:
		if (day == 31) {
			day = 1;
			if (month == 12) {
				month = 1;
				year++;
			}
			else {
				month++;
			}
		}
		else {
			day++;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day == 30) {
			day = 1;
			month++;
		}
		else {
			day++;
		}
		break;
	case 2:
		if (isLeap) {
			if(day == 29) {
				day = 1;
				month++;
			}
			else {
				day++;
			}
		}
		else {
			if (day == 28) {
				day = 1;
				month++;
			}
			else {
				day++;
			}
		}
	default:
		break;
	}

	cout << year
		<< '-' << setw(2) << setfill('0') << month
		<< '-' << setw(2) << setfill('0') << day;

	return 0;	
} 