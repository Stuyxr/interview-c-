#include <iostream>
using namespace std;
class Base {
   public:
    void print() { cout << "Base1" << endl; }
};
class Base1 {
   public:
    int x;
    void print() { cout << "Base1" << endl; }
};
class Base2 {
   public:
    int x;
    void print() { cout << "Base2" << endl; }
};
class Base3 {
   public:
    int x;
    void print() { cout << "Base3" << endl; }
};

class Derive : public Base1, public Base2, public Base3 {
   public:
    int x;
    void print() { cout << "Derive" << endl; }
};

int main(int argc, char const* argv[]) {
    Derive d;
    d.Base1::print();
    return 0;
}