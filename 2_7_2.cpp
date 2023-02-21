#include <iostream>
#include <vector>
using namespace std;
class Data {
   public:
    int x;
    Data() {
        cout << "default constructor" << endl;
        x = 0;
    }
    Data(int x) {
        cout << "parameter constructor" << endl;
        this->x = x;
    }
    Data(Data& d) {
        cout << "copy constructor" << endl;
        this->x = d.x;
    }
    Data(Data&& d) {
        cout << "move constructor" << endl;
        this->x = d.x;
        d.x = -1;
    }
    Data& operator=(Data& d) {
        x = d.x;
        cout << "copy assignment operator" << endl;
        return *this;
    }
    Data& operator=(Data&& d) {
        x = d.x;
        d.x = -2;
        cout << "move assignment operator" << endl;
        return *this;
    }
    ~Data() { cout << "destructor" << endl; }
};
Data&& getData(Data&& data) {
    cout << &data << endl;
    return std::move(data);
}

int main() {
    Data temp = Data();
    cout << &temp << endl;
    auto&& data = getData(move(temp));
    int x;
    cout << &temp << " " << &data << endl;
    cout << "data.x:  " << data.x << endl;
    cout << "temp.x:  " << temp.x << endl;
    return 0;
}
