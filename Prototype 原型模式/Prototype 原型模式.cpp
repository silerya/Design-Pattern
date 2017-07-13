// Prototype ԭ��ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//




//������ࣺ
//	l)Prototype:������࣬ ����ԭ�͵Ļ���,�ṩ Clone �ӿں���
//	�ӿں�����
//	1) Prototype::Clone ����: ���麯���� ���ݲ�ͬ����������ʵ������������.
//	������
//	Prototype ģʽ��ʵ���ǳ�˵��"���⹹�캯��"һ��ʵ��,C++��ʵ�ֻ����в�û��֧
//	���������, ����ͨ����ͬ������ʵ�ֵ� Clone �ӿں������������"���⹹�캯��"ͬ
//	����Ч��.��һ���������������ģʽ������ , ������һ�ҵ�������Կ�׵�, �������ṩ
//	����Կ�׵ķ���(�ṩ Clone �ӿں���),����Ҫ��ʲôԿ������֪��ֻ���ṩ���ַ���,
//	������Ҫ��ʲôԿ��ֻ�е�����������Կ�׵�ԭ�Ͳ������. Ҳ����˵, ��Ҫһ���ṩ
//	�������Ķ���, ͬʱ����Ҫһ��ԭ��(Prototype),��Ȼ��֪������ʲô����Կ��.


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
using namespace std;
//������࣬����ԭ�͵Ļ���,�ṩ Clone �ӿں���
class Prototype
{
public:
	Prototype(){}
	virtual ~Prototype(){}
	virtual Prototype* Clone()=0;
};


//������ Prototype��ʵ��Clone����
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
//������ Prototype��ʵ��Clone����
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
