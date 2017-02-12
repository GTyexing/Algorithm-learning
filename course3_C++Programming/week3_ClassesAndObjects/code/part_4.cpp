#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Warrior {
	int number;
	int health;
	string name;
	friend class Headquarter;
public:
	Warrior() {};
	void init(int h, string name, int n = 0);
	Warrior(const Warrior & w);
};

void Warrior::init(int h, string name, int n) {
	this->health = h;
	this->name = name;
	this->number = n;
}

Warrior::Warrior(const Warrior & w) {
	this->health = w.health;
	this->name = w.name;
	this->number = w.number;
}

class Headquarter {
	string color;
	int * order;
	Warrior * warrior;
	int nowno; // 现在正在做第几个
	int wno; // 当前在做哪一中兵
	int min; // 所造士兵中血量最低值
public:
	int life;
	Headquarter(string color, int life, int * order, Warrior * warrior);
	void makeWarrior();
};

Headquarter::Headquarter(string color, int life, int * order, Warrior * warrior) {
	this -> color = color;
	this->life = life;
	this->warrior = warrior;
	this->order = order;
	nowno = 0;
	wno = 0;
	min = warrior[0].health;
	for (int i = 1; i < 5; i++) {
		if (warrior[i].health < min)
			min = warrior[i].health;
	}
}

void Headquarter::makeWarrior() {
	if (life >= 0 && life < min) {
		cout << setw(3) << setfill('0') << nowno << ' ' << color <<
			" headquarter stops making warriors" << endl;
		life = -1;
	}
	else if (life >= min) {
		while(true) {
			if (life >= warrior[order[wno]].health) {
				life -= warrior[order[wno]].health;
				warrior[order[wno]].number++;
				cout << setw(3) << setfill('0') << nowno << ' ' << color << ' '
					<< warrior[order[wno]].name << ' ' << nowno  + 1 <<
					" born with strength " << warrior[order[wno]].health << ','
					<< warrior[order[wno]].number << ' ' << warrior[order[wno]].name
					<< " in " << color << " headquater" << endl;
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

int main() {
	int n = 0, life = 0;
	int dragon = 0, ninja = 0, iceman = 0, lion = 0, wolf = 0;
	cin >> n;
	cin >> life;
	cin >> dragon >> ninja >> iceman >> lion >> wolf;
	Warrior rw[5];
	rw[0].init(dragon, "dragon");
	rw[1].init(ninja, "ninja");
	rw[2].init(iceman, "iceman");
	rw[3].init(lion, "lion");
	rw[4].init(wolf, "wolf");
	Warrior bw[5];
	for (int i = 0; i < 5; i++) {
		bw[i] = rw[i];
	}
	int r[5] = { 2, 3, 4, 1, 0 };
	int b[5] = { 3, 0, 1, 2, 4 };
	Headquarter red("red", life, r, rw);
	Headquarter blue("blue", life, b, bw);
	cout << "Case:" << n << endl;
	while(red.life >= 0 || blue.life >= 0) {
		red.makeWarrior();
		blue.makeWarrior();
	}
	return 0;
}