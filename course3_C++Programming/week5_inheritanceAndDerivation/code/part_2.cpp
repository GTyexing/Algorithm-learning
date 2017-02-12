#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// 在此处补充你的代码
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
	void printInfo(string color, int time, int life);
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
	dragon(string na, int h, int n = 0):Warrior(na, h, n) {}
	void printInfo(string color, int time, int life);
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
	void printInfo(string color, int time, int life);
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
	void printInfo(string color, int time, int life);
};

void iceman::printInfo(string color, int time, int life) {
	Warrior::printInfo(color, time, life);
	cout << "It has a " << WeaponBox[time % 3] << endl;
}

class lion : public Warrior {
public:
	lion() {};
	lion(string na, int h, int n = 0) :Warrior(na, h, n) {}
	void printInfo(string color, int time, int life);
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
	int nowno; // 现在正在做第几个
	int wno; // 当前在做哪一中兵
	int min; // 所造士兵中血量最低值
public:
	Headquarter(string c, int l, int * o, const dragon & d, ninjia n, iceman i, lion lion, Warrior w, int min);
	int showlife() {return life;}
	void makeWarrior();
};

Headquarter::Headquarter(string color, int life, int * order, const dragon & d, ninjia n, iceman i, lion lion, Warrior w, int min) {
	this->color = color;
	this->life = life;
	this->d = d;
	this->n = n;
	this->i = i;
	this->l = lion;
	this->w = w;
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
			bool printed = false;
			switch (order[wno])
			{
			case 1:
				if(life >= n.printHealth()) {
					life -= n.printHealth();
					cout << setw(3) << setfill('0') << nowno << ' ';
					n.printInfo(color, nowno + 1, life);
					nowno++;
					wno++;
					printed = true;
					if (wno == 5)
						wno = 0;
				}
				break;
			case 2:
				if (life >= i.printHealth()) {
					life -= i.printHealth();
					cout << setw(3) << setfill('0') << nowno << ' ';
					i.printInfo(color, nowno + 1, life);
					printed = true;
					nowno++;
					wno++;
					if (wno == 5)
						wno = 0;
				}
				break;
			case 3:
				if (life >= l.printHealth()) {
					life -= l.printHealth();
					cout << setw(3) << setfill('0') << nowno << ' ';
					l.printInfo(color, nowno + 1, life);
					printed = true;
					nowno++;
					wno++;
					if (wno == 5)
						wno = 0;
				}
				break;
			case 4:
				if (life >= w.printHealth()) {
					life -= w.printHealth();
					cout << setw(3) << setfill('0') << nowno << ' ';
					w.printInfo(color, nowno + 1, life);
					printed = true;
					nowno++;
					wno++;
					if (wno == 5)
						wno = 0;
				}
				break;
			case 0:
				if (life >= d.printHealth()) {
					life -= d.printHealth();
					cout << setw(3) << setfill('0') << nowno << ' ';
					d.printInfo(color, nowno + 1, life);
					printed = true;
					nowno++;
					wno++;
					if (wno == 5)
						wno = 0;
				}
				break;
			}
			if (printed == true)
				break;
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
	Headquarter red("red", life, r, redD, redN, redI, redL, redW, min);
	Headquarter blue("blue", life, b, blueD, blueN, blueI, blueL, blueW, min);
	cout << "Case" << n1 << endl;
	while (red.showlife() >= 0 || blue.showlife() >= 0) {
		red.makeWarrior();
		blue.makeWarrior();
	}
	return 0;
}