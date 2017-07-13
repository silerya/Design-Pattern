// Bridge 模式.cpp : 定义控制台应用程序的入口点。
//


//作用：
//	将抽象部分与它的实现部分分离， 使它们都可以独立地变化。

//生活中的一个例子:
//就拿汽车在路上行驶的来说。即有小汽车又有公共汽车，它们都不但能在市区中的公路上行驶，也能在高速公路上行驶。这你会发现，对于交通工具（汽车）有不同的类型，然而它们所行驶的环境（路）也在变化，在软件系统中就要适应两个方面的变化？怎样实现才能应对这种变化呢？
//概述:
//在软件系统中，某些类型由于自身的逻辑，它具有两个或多个维度的变化，那么如何应对这种“多维度的变化”？如何利用面向对象的技术来使得该类型能够轻松的沿着多个方向进行变化，而又不引入额外的复杂度？这就要使用Bridge模式。
//意图:
//　　　将抽象部分与实现部分分离，使它们都可以独立的变化。



//抽象基类：
//	1) Abstraction:某个抽象类, 它的实现方式由 Implementor 完成.
//	2) Implementor:实现类的抽象基类, 定义了实现 Abastraction 的基本操作, 而它的派
//	生类实现这些接口.
//	接口函数：
//	l)Implementor::OperationImpl: 定义了为实现 Abstraction 需要的基本操作，
//	由 Implementor的派生类实现之, 而在 Abstraction::Operation 函数中根据不同的
//	指针多态调用这个函数.
//	解析：
//	Bridge 用于将表示和实现解耦, 两者可以独立的变化. 在 Abstraction 类中维护一
//	个 Implementor 类指针， 需要采用不同的实现方式的时候只需要传入不同的
//	Implementor 派生类就可以了 .
//	Bridge 的实现方式其实和 Builde 十分的相近, 可以这么说:本质上是一样的， 只是
//	封装的东西不一样罢了 . 两者的实现都有如下的共同点: 抽象出来一个基类, 这个基类
//	里面定义了共有的一些行为,形成接口函数(对接口编程而不是对实现编程),这个接口
//	函数在 Buildier 中是 BuildePart 函数在 Bridge 中是 OperationImpl 函数;
//其次, 聚合一个基类的指针,如 Builder 模式中 Director 类聚合了一个 Builder 基类
//	的指针, 而 Brige 模式中 Abstraction 类聚合了一个 Implementor 基类的指针
//	(优先采用聚合而不是继承);而在使用的时候， 都把对这个类的使用封装在一个函数
//	中， 在 Bridge 中是封装在 Director::Construct 函数中， 因为装配不同部分的过
//	程是一致的 , 而在 Bridge 模式中则是封装在 Abstraction:: Operation 函数中，
//	在这个函数中调用对应的 Implementor::OperationImp 函数 . 就两个模式而
//	言, Builder 封装了不同的生成组成部分的方式， 而 Bridge 封装了不同的实现方式.

#include "stdafx.h"

 
#include<iostream>
using namespace std;
//为实现Abstraction定义的抽象基类， 定义了实现的接口函数
class Implementor
{
public:
	Implementor(){}
	virtual ~Implementor(){}
	virtual void OperationImp()=0;
};
//继承自 Implementor,是Implementor的不同实现之一
class ConcreteImplementorA:public Implementor
{
public:
	ConcreteImplementorA(){}
	virtual ~ConcreteImplementorA(){}
	virtual void OperationImp()
	{ cout<<"Implementation by ConcreteImplementorA"<<endl; }
};
//继承自 Implementor,是Implementor的不同实现之一
class ConcreteImplementorB:public Implementor
{
public:
	ConcreteImplementorB(){}
	virtual ~ConcreteImplementorB(){}
	virtual void OperationImp()
	{ cout<<"Implementation by ConcreteImplementorB"<<endl; }
};
//维护一个Implementor类的指针
class Abstraction
{
public:
	Abstraction(Implementor* pImplementor):m_pImplementor(pImplementor){}
	virtual ~Abstraction()
	{
		delete m_pImplementor;
		m_pImplementor = NULL;
	}
	void Operation()
	{ m_pImplementor->OperationImp(); }
protected:
	Implementor* m_pImplementor;
};
int main()
{
	Implementor* pImpA = new ConcreteImplementorA();
	Abstraction* pAbstraction1 = new Abstraction(pImpA);
	pAbstraction1 ->Operation();
	Implementor* pImpB = new ConcreteImplementorB();
	Abstraction* pAbstraction2 = new Abstraction(pImpB);
	pAbstraction2->Operation();
	delete pAbstraction1;
	delete pAbstraction2;
	return 0;
}
