#include <iostream>
using namespace std;
class A {
   public:
    virtual void func() { cout << "A::func();" << endl; }
    void func(int x) { cout << "A::func(int x);" << endl; }
};

class B : public A {
   public:
    virtual void func() { cout << "B::func();" << endl; }
};

int main() {
    A* a = new B();
    a->func();
    a->func(2);
    return 0;
}