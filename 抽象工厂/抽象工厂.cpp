// 抽象工厂.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//抽象基类：
//	1)ProductA,ProductB: 分别代表不同类型的产品, 而它们的派生类则是这种产品的一
//	个实现.
//	2)AbstractFactory: 生产这一系列产品的一个抽象工厂,它的派生类是不同的实现.
//	接口函数：
//	1)AbstractFactory::CreateProductA 和 AbstractFactory::CreateProductB:
//分别是生产不同产品的不同的实现， 由各个派生出来的抽象工厂实现之.
//	解析：
//	Abstract Factory 模式和 Factory 最大的差别就是抽象工厂创建的是一系列相关的对象,
//	其中创建的实现其实采用的就是 Factory 模式的方法, 对于某个实现的有一个派生出来的
//	抽象工厂， 另一个实现有另一个派生出来的工厂,等等.
//	可以举一个简单的例子来解释这个模式： 比如， 同样是鸡腿(ProductA)和汉堡(Prod
//	UctB),它们都可以有商店出售(AbstractFactory),但是有不同的实现， 有肯德基(C
//	OncreateFactoryl)和麦当劳(ConcreateFactory2)两家生产出来的不同风味的鸡
//	腿和汉堡(也就是 ProductA 和 ProductB 的不同实现)， 而负责生产汉堡和鸡腿的
//	就是之前提过的 Factory 模式了.
//	抽象工厂需要特别注意的地方就是区分不同类型的产品和这些产品的不同实现.显而易
//	见的, 如果有 n 种产品同时有 m 中不同的实现,那么根据乘法原理可知有 n*m 个
//	Factory 模式的使用.
//	实现：
//abstract_factory.cpp


#include<iostream>
using namespace std;


//抽象基类AbstractProductA,代表产品A的抽象
class AbstractProductA
{
public:
	AbstractProductA(){}
	virtual ~AbstractProductA(){}
};


//派生类ConcreateProductAl,继承自 AbstractProductA,代表产品A的第一种实现
class ConcreateProductA1:public AbstractProductA
{
public:
	ConcreateProductA1()
	{ cout<<"ConcreateProdcutA1"<<endl; }
	virtual ~ConcreateProductA1(){}
};


//派生类ConcreateProductA2,继承自 AbstractProductA,代表产品A的第二种实现
class ConcreateProductA2:public AbstractProductA
{
public:
	ConcreateProductA2()
	{ cout<<"ConcreateProductA2"<<endl; }
	virtual ~ConcreateProductA2(){}
};


//抽象基类AbstractProductB,代表产品B的抽象
class AbstractProductB
{
public:
	AbstractProductB(){}
	virtual ~AbstractProductB(){}
};


//派生类ConcreateProductB1,继承自 AbstractProductB,代表产品B的第一种实现
class ConcreateProductB1:public AbstractProductB
{
public:
	ConcreateProductB1()
	{ cout<<"ConcreateProductB1"<<endl; }
	virtual ~ConcreateProductB1(){}
};


//派生类ConcreateProductB2,继承自 AbstractProductB,代表产品B的第二种实现
class ConcreateProductB2:public AbstractProductB
{
public:
	ConcreateProductB2()
	{ cout<<"ConcreateProductB2"<<endl; }
	virtual ~ConcreateProductB2(){}
};


//抽象基类AbstractFactory,工厂的抽象类， 生产产品A和产品B
class AbstractFactory
{
public:
	AbstractFactory(){}
	virtual ~AbstractFactory(){}
	virtual AbstractProductA* CreateProductA()=0;
	virtual AbstractProductB* CreateProductB()=0;
};



// 派生类 ConcreateFactoryl,继承自 AbstractFactory,生产产品A和产品B的第一种实现class
class ConcreteFactory1:public AbstractFactory
 {
	public:
		ConcreteFactory1()
		{ cout<<"ConcreteFactory1"<<endl; }
		virtual ~ConcreteFactory1(){}
		virtual AbstractProductA* CreateProductA()
		{ return new ConcreateProductA1(); }
		virtual AbstractProductB* CreateProductB()
		{ return new ConcreateProductB1(); }
 };


 // 派生类 ConcreateFactory2,继承自 AbstractFactory生产产品A和产品B的第二种实现class
class ConcreteFactory2:public AbstractFactory
{
public:
	ConcreteFactory2()
	{ cout<<"ConcreteFactory2"<<endl; }
	virtual ~ConcreteFactory2(){}
	virtual AbstractProductA* CreateProductA()
	{ return new ConcreateProductA2(); }
	virtual AbstractProductB* CreateProductB()
	{ return new ConcreateProductB2(); }

};



int main()
{
	//生产产品A的第一种实现
	AbstractFactory *cf1 = new ConcreteFactory1();
	cf1 ->CreateProductA();
	//生产产品B的第二种实现
	AbstractFactory *cf2 = new ConcreteFactory2();
	cf2->CreateProductB();
	delete cf1;
	delete cf2;
	return 0;
}
