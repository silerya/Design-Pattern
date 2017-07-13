// Adapt适配器模式.cpp : 定义控制台应用程序的入口点。
//


//解析：
//	Adapt 模式其实就是把完成同样的一个功能但是接口不能兼容的类桥接在一起使之可
//	以在一起工作，这个模式使得复用旧的接口成为可能.
//	实现：
//	Adapt 模式有两种实现办法，一种是采用继承原有接口类的方法，一种是采用组合原
//	有接口类的方法
//	采用继承原有接口类的方法


#include "stdafx.h"


#include<iostream>
using namespace std;
//需要被Adapt的类
class Target
{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request()
	{ cout<<"Target::Request"<<endl; }
};
//与被Adapt对象提供不兼容接口的类
class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecificRequest()
	{ cout<<"Adaptee::SpecificRequest"<<endl; }
};
//进行Adapt的类,采用继承原有接口类的方式
class Adapter:public Target,private Adaptee
{
public:
	Adapter(){}
	~Adapter(){}
	void Request()
	{ this->SpecificRequest(); }
};
int main()
{
	Target* adt = new Adapter();
	adt->Request();
	return 0;
}
//采用组合原有接口类的方法
#include<iostream>
	using namespace std;
//需要被Adapt的类
class Target
{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request()
	{ cout<<"Target::Request"<<endl; }
};
//与被Adapt对象提供不兼容接口的类
class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecificRequest()
	{ cout<<"Adaptee::SpecificRequest"<<endl; }
};
//进行Adapt的类,采用聚合原有接口类的方式
class Adapter:public Target
{
public:
	Adapter(Adaptee* ade)
	{ this->_ade = ade; }
	~Adapter(){}
	void Request()
	{ _ade->SpecificRequest(); }
private:
	Adaptee* _ade;
};
int main()
{
	Adaptee *ade = new Adaptee();
	Target* adt = new Adapter(ade);
	adt->Request();
	return 0;
}

