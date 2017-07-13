// ����ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"



//������ࣺ
//	1) Product:���������Ķ���ĳ������.
//	2) Factory ��������Ĺ��������ĳ������.
//	�ӿں�����
//	l)Creator::FactoryMethod: ���麯��, ��������ʵ��,��������Ӧ�� Product.
//	������
//	�����ģʽ�У��������������, һ���� Product Ϊ���������Ķ���ĳ�����࣬һ��
//	�� Factory �ǹ����ĳ������, �ڻ���Э����ʱ��������Ӧ�� Factory ������������
//	Product ��������, Ҳ����˵���Ҫ����һ�� Product ��ôҲҪ��Ӧ������һ��
//	Factory, �����Ĺ���ί�и������ Factory. Ҳ����˵һ�� Factory ��һ��
//	Product ��һһ��Ӧ�Ĺ�ϵ.



//Factory.cpp
//factoryģʽ��ʾ
#include<iostream>
using namespace std;


//��Ʒ������
class Product
{
public:
	Product(){}
	virtual ~Product(){}
};


//����Ĳ�Ʒ
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

//������
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

