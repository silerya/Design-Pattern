// 工厂模式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



//抽象基类：
//	1) Product:创建出来的对象的抽象基类.
//	2) Factory 创建对象的工厂方法的抽象基类.
//	接口函数：
//	l)Creator::FactoryMethod: 纯虚函数, 由派生类实现,创建出对应的 Product.
//	解析：
//	在这个模式中，有两个抽象基类, 一个是 Product 为创建出来的对象的抽象基类，一个
//	是 Factory 是工厂的抽象基类, 在互相协作的时候都是由相应的 Factory 派生类来生成
//	Product 的派生类, 也就是说如果要新增一种 Product 那么也要对应的新增一个
//	Factory, 创建的过程委托给了这个 Factory. 也就是说一个 Factory 和一个
//	Product 是一一对应的关系.



//Factory.cpp
//factory模式演示
#include<iostream>
using namespace std;


//产品抽象类
class Product
{
public:
	Product(){}
	virtual ~Product(){}
};


//具体的产品
class ConcreteProduct:public Product
{
public:
	ConcreteProduct()
	{ 
		cout<<"construction of ConcreteProduct"<<endl; 
	}
	virtual ~ConcreteProduct()
	{ 
		cout<<"destruction of ConcreteProduct"<<endl;
	}
};

//工厂类
class Creator
{
public:
	Creator(){}
	virtual ~Creator(){}
	void AnOperation()
	{
		Product* p = FactoryMethod();
		cout<<"an operation of product"<<endl;
	}
protected:
	virtual Product* FactoryMethod()=0;
};


class ConcreteCreator:public Creator
{
public:
	ConcreteCreator()
	{ 
		cout<<"construction of ConcreteCreator"<<endl; 
	}
	virtual ~ConcreteCreator()
	{ 
		cout<<"destruction of ConcreteCreator"<<endl; 
	}
protected:
	virtual Product* FactoryMethod()
	{ 
		return new ConcreteProduct();
	}
};
int main()
{
	Creator *p = new ConcreteCreator();
	p->AnOperation();
	delete p;
	return 0;
}

