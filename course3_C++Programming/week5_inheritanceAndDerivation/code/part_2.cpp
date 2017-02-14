/*编程题＃2： 魔兽世界之二：装备

来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述

魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。

dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。

lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。

wolf没特点。

请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

如果造出的是dragon，那么还要输出一行，例：

It has a arrow,and it's morale is 23.34

表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）

如果造出的是ninjia，那么还要输出一行，例：

It has a bomb and a arrow

表示该ninjia降生时得到了bomb和arrow。

如果造出的是iceman，那么还要输出一行，例：

It has a sword

表示该iceman降生时得到了sword。

如果造出的是lion，那么还要输出一行，例：

It's loyalty is 24

表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在 10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入

第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出

对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Warrior {
	int number;
	int health;
	string name;
public:
	static string WeaponBox[3];
	Warrior() {}
	Warrior(string na, int h, int n = 0);
	Warrior(const Warrior & w) {
		this->health = w.health;
		this->name = w.name;
		this->number = w.number;
	}
	virtual void printInfo(string color, int time, int life);
	int printHealth() { return health; }
	friend class Headquarter;
};

Warrior::Warrior(string na, int h, int n) {
	this->health = h;
	this->name = na;
	this->number = n;
}

void Warrior::printInfo(string color, int time, int life) {
	number++;
	cout << color << ' ' << name << ' ' << time
		<< " born with strength " << health << ',' << number
		<< " " << name << " in " << color << " headquarter" << endl;
}

class dragon : public Warrior {
public:
	dragon() {}
	dragon(string na, int h, int n = 0) :Warrior(na, h, n) {}
	virtual void printInfo(string color, int time, int life);
};

void dragon::printInfo(string color, int time, int life) {
	Warrior::printInfo(color, time, life);
	int h = printHealth();
	cout << "It has a " << Warrior::WeaponBox[time % 3]
		<< ",and it's morale is " << setprecision(3) << (double)life / h << endl;
}


class ninjia : public Warrior {
public:
	ninjia() {}
	ninjia(string na, int h, int n = 0) :Warrior(na, h, n) {}
	virtual void printInfo(string color, int time, int life);
};

void ninjia::printInfo(string color, int time, int life) {
	Warrior::printInfo(color, time, life);
	cout << "It has a " << WeaponBox[time % 3]
		<< " and a " << WeaponBox[(time + 1) % 3] << endl;
}

class iceman : public Warrior {
public:
	iceman() {}
	iceman(string na, int h, int n = 0) :Warrior(na, h, n) {}
	virtual void printInfo(string color, int time, int life);
};

void iceman::printInfo(string color, int time, int life) {
	Warrior::printInfo(color, time, life);
	cout << "It has a " << WeaponBox[time % 3] << endl;
}

class lion : public Warrior {
public:
	lion() {};
	lion(string na, int h, int n = 0) :Warrior(na, h, n) {}
	virtual void printInfo(string color, int time, int life);
};

void lion::printInfo(string color, int time, int life) {
	Warrior::printInfo(color, time, life);
	cout << "It's loyalty is " << life << endl;
}

class Headquarter {
	string color;
	int life;
	int * order;
	dragon d;
	ninjia n;
	iceman i;
	lion l;
	Warrior w;
	Warrior ** warrior;
	int nowno; // 现在正在做第几个
	int wno; // 当前在做哪一中兵
	int min; // 所造士兵中血量最低值
public:
	Headquarter(string c, int l, int * o, Warrior **  warrior, int min);
	int showlife() { return life; }
	void makeWarrior();
};

Headquarter::Headquarter(string color, int life, int * order, Warrior ** warrior, int min) {
	this->color = color;
	this->life = life;
	this->warrior = warrior;
	this->order = order;
	nowno = 0;
	wno = 0;
	this->min = min;
}

void Headquarter::makeWarrior() {
	if (life >= 0 && life < min) {
		cout << setw(3) << setfill('0') << nowno << ' ' << color <<
			" headquarter stops making warriors" << endl;
		life = -1;
	}
	else if (life >= min) {
		while (true) {
			if (life >= warrior[order[wno]]->printHealth()) {
				life -= warrior[order[wno]]->printHealth();
				cout << setw(3) << setfill('0') << nowno << ' ';
				warrior[order[wno]]->printInfo(color, nowno + 1, life);
				nowno++;
				wno++;
				if (wno == 5)
					wno = 0;
				break;
			}
			wno++;
			if (wno == 5)
				wno = 0;
		}
	}
}

string Warrior::WeaponBox[3] = { "sword", "bomb", "arrow" };

int main() {
	int n1 = 0, life = 0;
	int s[5], min = 0;
	int r[5] = { 2, 3, 4, 1, 0 };
	int b[5] = { 3, 0, 1, 2, 4 };
	cin >> n1;
	cin >> life;
	for (int i = 0; i < 5; i++) {
		cin >> s[i];
	}
	min = s[0];
	for (int i = 1; i < 5; i++) {
		if (s[i] < min) min = s[i];
	}
	dragon redD("dragon", s[0]); dragon blueD(redD);
	ninjia redN("ninjia", s[1]); ninjia blueN(redN);
	iceman redI("iceman", s[2]); iceman blueI(redI);
	lion redL("lion", s[3]); lion blueL(redL);
	Warrior redW("wolf", s[4]); Warrior blueW(redW);
	Warrior * redS[5] = { &redD, &redN, & redI, & redL, & redW};
	Warrior * blueS[5] = { &blueD, &blueN, &blueI, &blueL, &blueW };
	Headquarter red("red", life, r, redS, min);
	Headquarter blue("blue", life, b, blueS, min);
	cout << "Case " << n1 << endl;
	while (red.showlife() >= 0 || blue.showlife() >= 0) {
		red.makeWarrior();
		blue.makeWarrior();
	}
	return 0;
}