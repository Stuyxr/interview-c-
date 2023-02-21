# include <iostream>
# include <memory>
using namespace std;
weak_ptr<int> p0;
struct Node
{
	std::shared_ptr<Node> Parent;
	std::weak_ptr<Node> LeftChild;
	std::weak_ptr<Node> RightChild;
	int Data;

	//
	Node(int d) : Data(d) {
        cout << "Ctor" << endl;
    }
	~Node()
	{
		std::cout << "~Node() called" << std::endl;
	}
};

void dfs(shared_ptr<Node> a) {
    cout << a->Data << endl;
    shared_ptr<Node> left = a->LeftChild.lock();
    if (left != nullptr)
        dfs(left);
    shared_ptr<Node> right = a->RightChild.lock();
    if (right != nullptr)
        dfs(right);
}
void Tree()
{
	std::shared_ptr<Node> a = std::make_shared<Node>(1);
	std::shared_ptr<Node> b = std::make_shared<Node>(2);
	std::shared_ptr<Node> c = std::make_shared<Node>(3);
	std::shared_ptr<Node> d = std::make_shared<Node>(4);
	std::shared_ptr<Node> e = std::make_shared<Node>(5);
	std::shared_ptr<Node> f = std::make_shared<Node>(6);
    a->LeftChild = b;
    a->RightChild = c;
    b->LeftChild = d;
    c->RightChild = e;
    c->LeftChild = f;
    dfs(a);
}
void test() {
    shared_ptr<int> p(new int(10));
    shared_ptr<int> p2 = p;
    p0 = p;
    cout << p2.use_count() << endl;
    cout << *p2 << endl;
    cout << p0.lock() << endl;
}
int main() {
    // test();
    // cout << p0.lock() << endl;
    // Tree();
    return 0;
}