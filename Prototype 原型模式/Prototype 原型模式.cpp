// Prototype 原型模式.cpp : 定义控制台应用程序的入口点。
//




//抽象基类：
//	l)Prototype:虚拟基类， 所有原型的基类,提供 Clone 接口函数
//	接口函数：
//	1) Prototype::Clone 函数: 纯虚函数， 根据不同的派生类来实例化创建对象.
//	解析：
//	Prototype 模式其实就是常说的"虚拟构造函数"一个实现,C++的实现机制中并没有支
//	持这个特性, 但是通过不同派生类实现的 Clone 接口函数可以完成与"虚拟构造函数"同
//	样的效果.举一个例子来解释这个模式的作用 , 假设有一家店铺是配钥匙的, 他对外提供
//	配制钥匙的服务(提供 Clone 接口函数),你需要配什么钥匙它不知道只是提供这种服务,
//	具体需要配什么钥匙只有到了真正看到钥匙的原型才能配好. 也就是说, 需要一个提供
//	这个服务的对象, 同时还需要一个原型(Prototype),不然不知道该配什么样的钥匙.


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
//虚拟基类，所有原型的基类,提供 Clone 接口函数
class Prototype
{
public:
	Prototype(){}
	virtual ~Prototype(){}
	virtual Prototype* Clone()=0;
};


//派生自 Prototype，实现Clone方法
class ConcretePrototype1:public Prototype
{
public:
	ConcretePrototype1()
	{ 
		cout<<"ConcretePrototype1"<<endl;
	}
	ConcretePrototype1(const ConcretePrototype1& p)
	{ 
		cout<<"ConcretePrototype1 copy..."<<endl;
	}
	virtual ~ConcretePrototype1(){}
	virtual Prototype* Clone()
	{
		return new ConcretePrototype1(*this);
	}
};
//派生自 Prototype，实现Clone方法
class ConcretePrototype2:public Prototype
{
public:
	ConcretePrototype2()
	{ 
		cout<<"ConcretePrototype2"<<endl;
	}
	ConcretePrototype2(const ConcretePrototype2& p)
	{ 
		cout<<"ConcretePrototype2 copy..."<<endl; 
	}
	virtual ~ConcretePrototype2(){}

	virtual Prototype* Clone()
	{ 
		return new ConcretePrototype2(*this); 
	}
};
int main()
{
	Prototype* p1 = new ConcretePrototype1();
	Prototype* p2 = p1 ->Clone();
	Prototype* p3 = new ConcretePrototype2();
	Prototype* p4 = p3->Clone();
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	return 0;
}
