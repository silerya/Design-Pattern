// Adapt������ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//


//������
//	Adapt ģʽ��ʵ���ǰ����ͬ����һ�����ܵ��ǽӿڲ��ܼ��ݵ����Ž���һ��ʹ֮��
//	����һ���������ģʽʹ�ø��þɵĽӿڳ�Ϊ����.
//	ʵ�֣�
//	Adapt ģʽ������ʵ�ְ취��һ���ǲ��ü̳�ԭ�нӿ���ķ�����һ���ǲ������ԭ
//	�нӿ���ķ���
//	���ü̳�ԭ�нӿ���ķ���


#include "stdafx.h"


#include<iostream>
using namespace std;
//��Ҫ��Adapt����
class Target
{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request()
	{ cout<<"Target::Request"<<endl; }
};
//�뱻Adapt�����ṩ�����ݽӿڵ���
class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecificRequest()
	{ cout<<"Adaptee::SpecificRequest"<<endl; }
};
//����Adapt����,���ü̳�ԭ�нӿ���ķ�ʽ
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
//�������ԭ�нӿ���ķ���
#include<iostream>
	using namespace std;
//��Ҫ��Adapt����
class Target
{
public:
	Target(){}
	virtual ~Target(){}
	virtual void Request()
	{ cout<<"Target::Request"<<endl; }
};
//�뱻Adapt�����ṩ�����ݽӿڵ���
class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecificRequest()
	{ cout<<"Adaptee::SpecificRequest"<<endl; }
};
//����Adapt����,���þۺ�ԭ�нӿ���ķ�ʽ
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

