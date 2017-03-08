#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct weapon {
  string name;
  int atk;
  weapon() {}
  weapon(string w, int a = 0):name(w), atk(a) {}
  ~weapon() {}
};

class Warrior {
  int id;
  int number;//数量
  int health;//生命值
  string name;//姓名
  int atk; //攻击力
public:
  bool isDead;//标志是否死亡
  static weapon weaponBox[3];
  Warrior() {}
  Warrior(const Warrior & w) {
    this->health = w.health;
    this->name = w.name;
    this->number = w.number;
  }
  virtual inline int checkLoyalty() { return 0; }
  virtual inline void loseLoyalty() {}
  inline string getName() { return name; }
  inline int getId() { return id; }
  inline int getHealth() { return health; }
};

class dragon : public Warrior {
};

class ninjia : public Warrior {
};

class iceman : public Warrior {
};

class lion : public Warrior {
  int loyalty;
public:
  static int k;
  virtual inline int checkLoyalty() { return loyalty; }
  virtual inline void loseLoyalty() { loyalty -= k; }
};

class wolf : public Warrior {
};

class Headquarter {
  string color;
  int life;
  int * order;
  int enemy;
  int time;
  int nowmaking;//现在在做哪个士兵
public:
  vector<Warrior *> soldiers;
  static int timeOut;
  static int initatk[5];
  static int inithealth[5];
  Headquarter(string c, int l, int * o): color(c), life(l), order(o) { enemy = 0; time = 0; nowmaking = 0; }
  inline int printHealth() { return life; }
  inline int isLose() { return enemy < 2; }
  void fight(int T);
  void makeSoldiers() {};
};

void Headquarter::fight(int T) {
  if (time > T) timeOut = 1;
  else {
    switch (time % 60) {
      case 0:
        if(inithealth[order[nowmaking]] <= life) {
          makeSoldiers();
          life -= inithealth[order[nowmaking]];
          nowmaking++;
          if (nowmaking == 5) nowmaking = 0;
        }
        time += 5;
        break;
      case 5:
        for(int i = 0; i < soldiers.size(); i++) {
          if(soldiers[i]->getName() == "lion" && soldiers[i]->isDead == false) {
            if(soldiers[i]->checkLoyalty() <= 0) {
              soldiers[i]->isDead = true;
              cout << setw(3) << setfill('0') << time / 60 << ':' << 0 << 5 << ' ' << color << ' ' << soldiers[i]->getName() << ' ' << soldiers[i]->getId() << " ran away" << endl;
            }
            else soldiers[i]->loseLoyalty();
          }
        }
        time += 5;
        break;
      case 10:
        time += 25;
        break;
      case 35:
        time += 3;
        break;
      case 38:
        time += 2;
        break;
      case 40:
        time += 10;
        break;
      case 50:
        time += 5;
        break;
      case 55:
        time += 5;
        break;
    }
  }
}

struct City {
  string belong;
  Warrior a;
  Warrior b;
  City() {}
};

int Headquarter::timeOut = 0;
int Headquarter::initatk[5];
int Headquarter::inithealth[5];
int lion::k = 0;//K-->狮子每回合损失的忠诚度
weapon Warrior::weaponBox[3];

int main() {
  Warrior::weaponBox[0].name = "arrow";
  Warrior::weaponBox[1].name = "bomb";
  Warrior::weaponBox[2].name = "sword";
  int r[5] = { 2, 3, 4, 1, 0 };
  int b[5] = { 3, 0, 1, 2, 4 };
  int n;
  cin >> n;
  int n1 = n;
  while (n--) {
    int M, N, T;//M-->生命元,N-->城市数, T-->战斗持续时间
    cin >> M >> N >> Warrior::weaponBox[0].atk >> lion::k >> T;
    vector<City> citys;
    while(N--) {
      int i = 1;
      City c;
      if(i % 2 == 0) {
        c.belong = "blue";
        citys.push_back(c);
      } else {
        c.belong = "red";
        citys.push_back(c);
      }
      i++;
    }
    for(int i = 0; i < 5; i++) {
      cin >> Headquarter::inithealth[i];
    }
    for(int i = 0; i < 5; i++) {
      cin >> Headquarter::initatk[i];
    }
    Headquarter red("red", M, r);
    Headquarter blue("red", M, b);
    cout << "Case:" << n1 - n << endl;
    while(Headquarter::timeOut == 0 && red.isLose() == false && blue.isLose() == false) {
      red.fight(T);
      blue.fight(T);
    }
  }
  return 0;
}
