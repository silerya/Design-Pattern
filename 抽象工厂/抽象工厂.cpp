// ���󹤳�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//������ࣺ
//	1)ProductA,ProductB: �ֱ����ͬ���͵Ĳ�Ʒ, �����ǵ��������������ֲ�Ʒ��һ
//	��ʵ��.
//	2)AbstractFactory: ������һϵ�в�Ʒ��һ�����󹤳�,�����������ǲ�ͬ��ʵ��.
//	�ӿں�����
//	1)AbstractFactory::CreateProductA �� AbstractFactory::CreateProductB:
//�ֱ���������ͬ��Ʒ�Ĳ�ͬ��ʵ�֣� �ɸ������������ĳ��󹤳�ʵ��֮.
//	������
//	Abstract Factory ģʽ�� Factory ���Ĳ����ǳ��󹤳���������һϵ����صĶ���,
//	���д�����ʵ����ʵ���õľ��� Factory ģʽ�ķ���, ����ĳ��ʵ�ֵ���һ������������
//	���󹤳��� ��һ��ʵ������һ�����������Ĺ���,�ȵ�.
//	���Ծ�һ���򵥵��������������ģʽ�� ���磬 ͬ���Ǽ���(ProductA)�ͺ���(Prod
//	UctB),���Ƕ��������̵����(AbstractFactory),�����в�ͬ��ʵ�֣� �пϵ»�(C
//	OncreateFactoryl)������(ConcreateFactory2)�������������Ĳ�ͬ��ζ�ļ�
//	�Ⱥͺ���(Ҳ���� ProductA �� ProductB �Ĳ�ͬʵ��)�� ���������������ͼ��ȵ�
//	����֮ǰ����� Factory ģʽ��.
//	���󹤳���Ҫ�ر�ע��ĵط��������ֲ�ͬ���͵Ĳ�Ʒ����Щ��Ʒ�Ĳ�ͬʵ��.�Զ���
//	����, ����� n �ֲ�Ʒͬʱ�� m �в�ͬ��ʵ��,��ô���ݳ˷�ԭ���֪�� n*m ��
//	Factory ģʽ��ʹ��.
//	ʵ�֣�
//abstract_factory.cpp


#include<iostream>
using namespace std;


//�������AbstractProductA,�����ƷA�ĳ���
class AbstractProductA
{
public:
	AbstractProductA(){}
	virtual ~AbstractProductA(){}
};


//������ConcreateProductAl,�̳��� AbstractProductA,�����ƷA�ĵ�һ��ʵ��
class ConcreateProductA1:public AbstractProductA
{
public:
	ConcreateProductA1()
	{ cout<<"ConcreateProdcutA1"<<endl; }
	virtual ~ConcreateProductA1(){}
};


//������ConcreateProductA2,�̳��� AbstractProductA,�����ƷA�ĵڶ���ʵ��
class ConcreateProductA2:public AbstractProductA
{
public:
	ConcreateProductA2()
	{ cout<<"ConcreateProductA2"<<endl; }
	virtual ~ConcreateProductA2(){}
};


//�������AbstractProductB,�����ƷB�ĳ���
class AbstractProductB
{
public:
	AbstractProductB(){}
	virtual ~AbstractProductB(){}
};


//������ConcreateProductB1,�̳��� AbstractProductB,�����ƷB�ĵ�һ��ʵ��
class ConcreateProductB1:public AbstractProductB
{
public:
	ConcreateProductB1()
	{ cout<<"ConcreateProductB1"<<endl; }
	virtual ~ConcreateProductB1(){}
};


//������ConcreateProductB2,�̳��� AbstractProductB,�����ƷB�ĵڶ���ʵ��
class ConcreateProductB2:public AbstractProductB
{
public:
	ConcreateProductB2()
	{ cout<<"ConcreateProductB2"<<endl; }
	virtual ~ConcreateProductB2(){}
};


//�������AbstractFactory,�����ĳ����࣬ ������ƷA�Ͳ�ƷB
class AbstractFactory
{
public:
	AbstractFactory(){}
	virtual ~AbstractFactory(){}
	virtual AbstractProductA* CreateProductA()=0;
	virtual AbstractProductB* CreateProductB()=0;
};



// ������ ConcreateFactoryl,�̳��� AbstractFactory,������ƷA�Ͳ�ƷB�ĵ�һ��ʵ��class
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


 // ������ ConcreateFactory2,�̳��� AbstractFactory������ƷA�Ͳ�ƷB�ĵڶ���ʵ��class
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
	//������ƷA�ĵ�һ��ʵ��
	AbstractFactory *cf1 = new ConcreteFactory1();
	cf1 ->CreateProductA();
	//������ƷB�ĵڶ���ʵ��
	AbstractFactory *cf2 = new ConcreteFactory2();
	cf2->CreateProductB();
	delete cf1;
	delete cf2;
	return 0;
}
