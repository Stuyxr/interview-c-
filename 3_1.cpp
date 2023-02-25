#include <iostream>
#include <string>
using namespace std;
template <typename T>
class MyList {
   private:
    class Node {
       public:
        T val;
        Node* next;
        Node* prev;
        Node(const T& v) {
            val = v;
            next = nullptr;
            prev = nullptr;
        }
        Node(T&& v) {
            std::swap(val, v);
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head;
    Node* tail;
    size_t sz;

   public:
    /*
    Define MyList iterator class
    */
    class MyIterator {
       public:
        Node* cur;
        MyIterator() { cur = nullptr; }
        MyIterator(Node* cur) { this->cur = cur; }
        MyIterator(MyIterator& other) { cur = other.cur; }
        MyIterator(MyIterator&& other) {
            cur = other.cur;
            other.cur = nullptr;
        }
        // Note: difference between ++it and it++
        MyIterator& operator++() {
            cur = cur->next;
            return *this;
        }
        const MyIterator operator++(int) {
            MyIterator old_it = *this;
            cur = cur->next;
            return old_it;
        }

        MyIterator& operator--() {
            cur = cur->prev;
            return *this;
        }
        bool operator==(const MyIterator& other) const {
            return other.cur == cur;
        }
        bool operator!=(const MyIterator& other) const {
            return other.cur != cur;
        }
        T operator*() { return cur->val; }
    };
    MyList() {
        head = nullptr;
        sz = 0;
    }
    // copy constructor
    MyList(const MyList<T>& o) {
        head = new Node(o.head->val);
        Node* cur = head;
        for (Node* o_cur = o.head; o_cur != nullptr; o_cur = o_cur->next) {
            if (o_cur->next) {
                cur->next = new Node(o_cur->next->val);
                cur->next->prev = cur;
            }
            cur = cur->next;
            tail = cur;
        }
        sz = o.sz;
    }

    // move constructor
    MyList(MyList<T>&& o) {
        head = o.head;
        tail = o.tail;
        o.head = nullptr;
        o.tail = nullptr;
        std::swap(sz, o.sz);
    }

    ~MyList() { clear(); }
    void push_back(T& x) {
        Node* new_node = new Node(x);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            sz = 1;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            sz++;
        }
    }
    void push_back(T&& x) {
        // move x into rvalue and construct a Node, using its content
        Node* new_node = new Node(std::move(x));
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            sz = 1;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            sz++;
        }
    }
    void push_front(T& x) {
        Node* new_node = new Node(x);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            sz = 1;
        } else {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
            sz++;
        }
    }
    void push_front(T&& x) {
        Node* new_node = new Node(std::move(x));
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            sz = 1;
        } else {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
            sz++;
        }
    }
    void pop_back() {
        if (tail != nullptr) {
            auto tmp = tail;
            tail = tail->prev;
            delete tmp;
            if (tail != nullptr)
                tail->next = nullptr;
            else
                head = nullptr;
            sz--;
        }
    }

    void pop_front() {
        if (head != nullptr) {
            auto tmp = head;
            head = head->next;
            delete tmp;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;
            sz--;
        }
    }

    void clear() {
        for (Node* cur = head; cur != nullptr;) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
    bool empty() const { return sz == 0; }
    size_t size() const { return sz; }

    void show() {
        for (Node* cur = head; cur != nullptr; cur = cur->next)
            cout << cur->val << " ";
        cout << endl;
    }

    MyIterator begin() { return MyIterator(head); }
    MyIterator end() { return MyIterator(nullptr); }
};
class Person {
   public:
    string name;
    int age;
    Person() {}
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << p.name << " " << p.age << ";";
        return os;
    }
};

int main() {
    MyList<Person> list;
    Person p1("John", 30);
    Person p2("Jane", 25);
    cout << "------Test easy functions of MyList------" << endl;
    list.push_front(p1);
    list.push_front(Person("stuyxr", 23));
    list.push_back(Person("stuzkb", 22));
    list.push_front(std::move(p2));
    cout << "size of list: " << list.size() << endl;
    list.show();
    list.pop_front();
    list.show();
    cout << endl;
    cout << "------Test use rvalue of Person to construct Node------" << endl;
    // p2 is moved
    cout << "p1: " << p1 << ", p2:" << p2 << endl;
    cout << endl;
    cout << "------Test copy constructor------" << endl;

    MyList<Person> copy_list = list;
    cout << "show copy list:" << endl;
    copy_list.show();
    cout << "show list:" << endl;
    list.show();
    cout << endl;
    cout << "------Test move constructor------" << endl;
    MyList<Person> move_list = std::move(list);
    cout << "show move list:" << endl;
    move_list.show();
    cout << "show list:" << endl;
    list.show();
    cout << endl;
    cout << "------Test iterator------" << endl;
    for (MyList<Person>::MyIterator it = move_list.begin();
         it != move_list.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}