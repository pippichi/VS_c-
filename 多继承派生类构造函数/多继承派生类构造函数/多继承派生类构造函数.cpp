// 多继承派生类构造函数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

class A {
public:
	A(int i) { cout << "constructor called" << i << endl; }
	~A() { cout << "deconstructor called" << endl; }
};
class B{
public:
	B(int i) { cout << "constructor called" << i << endl; }
	~B() { cout << "deconstructor called" << endl; }
};
class C {
public:
	C() { cout << "constructor called" << endl; }
	~C() { cout << "deconstructor called" << endl; }
};
class D :public B, public A, public C {
public:
	D(int i, int j, int c,int d):A(i),member2(j),member1(c),B(d) {	
	}
private:
	A member1;
	B member2;
	C member3;
};
int main()
{
	D(1, 2, 3, 4);
    return 0;
}

