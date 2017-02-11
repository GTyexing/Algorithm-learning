#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
	double r, i;
public:
	void Print() {
		cout << r << "+" << i << "i" << endl;
	}
	// 在此处补充你的代码
	Complex & operator=(string s);
};

Complex & Complex::operator=(string s) {
	int pos1 = s.find('+', 0);
	string s1 = s.substr(0, pos1);
	string s2 = s.substr(pos1 + 1,  s.length()-pos1-2);
	r = atof(s1.c_str());
	i = atof(s2.c_str());
	return *this;
}

int main() {
	Complex a;
	a = "3+4i"; a.Print();
	a = "5+6i"; a.Print();
	return 0;
}
