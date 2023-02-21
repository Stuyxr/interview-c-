#include <iostream>
#include <cstdio>
using namespace std;
class Base1 {
public:
	virtual void A() { cout << "Base1 A()" << endl; }
	virtual void B() { cout << "Base1 B()" << endl; }
	virtual void C() { cout << "Base1 C()" << endl; }
};

class Derive : public Base1{
public:
    int x;
	virtual void MyA() { cout << "Derive MyA()" << endl; }
};


int main() {
    printf("%d\n", sizeof(Base1)); // 16
    printf("%d\n", sizeof(Derive)); // 16
    return 0;
}