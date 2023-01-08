#include <iostream>

using namespace std;
class A {
public:
    A() {
        cout << "Constructing A" << '\n';
    }
    virtual ~A() {
         cout << "Deleting A" << '\n';
    }
};

class B : public A {
public:
    B() {
        cout << "Constructing B" << '\n';
    }
    ~B() {
         cout << "Deleting B" << '\n';
    }
};

class C : public B {
public:
    C() {
        cout << "constructing C" << '\n';
    }
    ~C() {
        cout << "deleting C" << '\n';
    }
};

class Dummy {
private:
    int a;
    int x;
    int c;
public:
    Dummy(int i = 0) : c(++i), a(++i), x(++i){}
    int getX() {
        return x;
    }
    int getC() {
        return c;
    }
};


int main() {
    //A a;
    // A* a = new C();
    // delete a;
    Dummy* d = new Dummy();
    cout << d->getX() << '\n';
    cout << d->getC() << '\n';
}