// Singleton 模式(单例).cpp : 定义控制台应用程序的入口点。
//


//解析：
//	Singleton 模式其实是对全局静态变量的一个取代策略, 上面提到的 Singleton 模式的
//	两个作用在 C++中是通过如下的机制实现的:
//1) 仅有一个实例，提供一个类的静态成员变量，大家知道类的静态成员变量对于一个类
//	的所有对象而言是惟一的
//	2) 提供一个访问它的全局访问点, 也就是提供对应的访问这个静态成员变量的静态成员
//	函数, 对类的所有对象而言也是惟一的. 在 C++中， 可以直接使用类域进行访问而不必初
//	始化一个类的对象.
//	下面的实现其实是 Singleton 的一个简单实现,并不是特别的通用, 一般的，如果一个项
//	目中需要使用到 Singleton 模式比较多的话, 那么一般会实现一个 Singleton 的模
//	板类，模板类的模板参数是需要采用 Singleton 模式的类, 比如这样实现：


#include "stdafx.h"


//Template<typename T>
//class Singleton
//{
//	// . . .类的声明
//} ;
////需要采用 singleton 模式的类
//class Test:publicSingleton<Test>
// {
//			  // …类的声明};
//}


#include<iostream>
#include <string>
using namespace std;
class Singleton
{

public: 
	int m_Num1;
	string  m_str;
public:
	static Singleton* Instance()
	{
		if(_instance == 0)
		{
			_instance = new Singleton(1,"nihao");
		}
		return _instance;
	}
private:
	Singleton()
	{ 
		cout<<"Singleton..."<<endl; 

	}
private:
	//静态成员变量，提供全局唯一的一个实例
	static Singleton* _instance;


};
//类的静态成员变量要在类体外进行定义
Singleton* Singleton::_instance = 0;


int main()
{
	Singleton* sgn = Singleton::Instance();
	Singleton* sgn2 = Singleton::Instance();
	Singleton* sgn3 = Singleton::Instance();
	return 0;
}
