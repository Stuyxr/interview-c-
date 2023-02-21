#include <algorithm>
#include <iostream>
using namespace std;
class Person {
   public:
    Person() { cout << "Default constructor" << endl; }
    Person(int age) {
        this->age = age;
        cout << "age constructor" << endl;
    }
    Person(const Person& p) {
        this->age = p.age;
        cout << "Copy Constructor" << endl;
    }

    Person& operator=(const Person& p) {
        cout << "Copy Assign" << endl;
        this->age = p.age;
        return *this;
    }
    Person(Person&& p) {
        swap(p.age, age);
        cout << "Move Constructor" << endl;
    }

    Person& operator=(Person&& p) {
        cout << "Move Assign" << endl;
        swap(p.age, age);
        return *this;
    }
    ~Person() { cout << "Destructor" << endl; }

    int age;
};

void f(Person p) {
    return;
}
Person f1() {
    Person p;
    return p;
}

int main() {
    Person p;
    cout << endl;
    // Default constructor
    Person p1 = p;
    // Copy Constructor
    cout << endl;
    Person p2(p);
    // Copy Constructor
    cout << endl;
    p2 = p;
    // Copy Assign
    p2 = std::move(p);
    // Move Assign
    cout << endl;
    f(p2);
    // Copy Constructor
    // Destructor
    cout << endl;
    p2 = f1();
    // Default constructor
    // Move Assign
    // Destructor
    cout << endl;
    Person p3 = f1();
    cout << endl;

    return 0;
}
