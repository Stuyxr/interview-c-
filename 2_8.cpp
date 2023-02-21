#include <iostream>
using namespace std;

class Base1 {
public:
    Base1() {
        cout << "Base1 constructor" << endl;
    }
    ~Base1() {
        cout << "Base1 destructor" << endl;
    }
	virtual void A() { cout << "Base1 A()" << endl; }
	virtual void B() { cout << "Base1 B()" << endl; }
	virtual void C() { cout << "Base1 C()" << endl; }
};

class Derive : public Base1{
public:
    int x;
    Derive() {
        cout << "Derive constructor" << endl;
    }
    ~Derive() {
        cout << "Derive constructor" << endl;
    }
	virtual void MyA() { cout << "Derive MyA()" << endl; }
};

int main(int argc, char * argv[])
{
    Derive a;
    Base1& base1 = a;
}
