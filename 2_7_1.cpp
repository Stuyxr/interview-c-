#include <iostream>
using namespace std;
class A {
   public:
    A() { x = new int(1); }
    // };
    ~A() { delete x; }
    int* x;
};

A func() {
    A temp;
    cout << &temp << endl;
    return temp;
}

A a = func();
class T {
   public:
    T() { cout << "default constructor" << endl; }
    // ~T() { cout << "default destructor" << endl; }
};
// T f() {return T();}
// T x = T(T(f()));
int main() {
    cout << &a << endl;
    cout << *a.x;
    return 0;
}
/*
0x407030
0x407030
*/