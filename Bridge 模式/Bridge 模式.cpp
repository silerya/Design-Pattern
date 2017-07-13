// Bridge ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//


//���ã�
//	�����󲿷�������ʵ�ֲ��ַ��룬 ʹ���Ƕ����Զ����ر仯��

//�����е�һ������:
//����������·����ʻ����˵������С�������й������������Ƕ��������������еĹ�·����ʻ��Ҳ���ڸ��ٹ�·����ʻ������ᷢ�֣����ڽ�ͨ���ߣ��������в�ͬ�����ͣ�Ȼ����������ʻ�Ļ�����·��Ҳ�ڱ仯�������ϵͳ�о�Ҫ��Ӧ��������ı仯������ʵ�ֲ���Ӧ�����ֱ仯�أ�
//����:
//�����ϵͳ�У�ĳЩ��������������߼�����������������ά�ȵı仯����ô���Ӧ�����֡���ά�ȵı仯������������������ļ�����ʹ�ø������ܹ����ɵ����Ŷ��������б仯�����ֲ��������ĸ��Ӷȣ����Ҫʹ��Bridgeģʽ��
//��ͼ:
//�����������󲿷���ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ı仯��



//������ࣺ
//	1) Abstraction:ĳ��������, ����ʵ�ַ�ʽ�� Implementor ���.
//	2) Implementor:ʵ����ĳ������, ������ʵ�� Abastraction �Ļ�������, ��������
//	����ʵ����Щ�ӿ�.
//	�ӿں�����
//	l)Implementor::OperationImpl: ������Ϊʵ�� Abstraction ��Ҫ�Ļ���������
//	�� Implementor��������ʵ��֮, ���� Abstraction::Operation �����и��ݲ�ͬ��
//	ָ���̬�����������.
//	������
//	Bridge ���ڽ���ʾ��ʵ�ֽ���, ���߿��Զ����ı仯. �� Abstraction ����ά��һ
//	�� Implementor ��ָ�룬 ��Ҫ���ò�ͬ��ʵ�ַ�ʽ��ʱ��ֻ��Ҫ���벻ͬ��
//	Implementor ������Ϳ����� .
//	Bridge ��ʵ�ַ�ʽ��ʵ�� Builde ʮ�ֵ����, ������ô˵:��������һ���ģ� ֻ��
//	��װ�Ķ�����һ������ . ���ߵ�ʵ�ֶ������µĹ�ͬ��: �������һ������, �������
//	���涨���˹��е�һЩ��Ϊ,�γɽӿں���(�Խӿڱ�̶����Ƕ�ʵ�ֱ��),����ӿ�
//	������ Buildier ���� BuildePart ������ Bridge ���� OperationImpl ����;
//���, �ۺ�һ�������ָ��,�� Builder ģʽ�� Director ��ۺ���һ�� Builder ����
//	��ָ��, �� Brige ģʽ�� Abstraction ��ۺ���һ�� Implementor �����ָ��
//	(���Ȳ��þۺ϶����Ǽ̳�);����ʹ�õ�ʱ�� ���Ѷ�������ʹ�÷�װ��һ������
//	�У� �� Bridge ���Ƿ�װ�� Director::Construct �����У� ��Ϊװ�䲻ͬ���ֵĹ�
//	����һ�µ� , ���� Bridge ģʽ�����Ƿ�װ�� Abstraction:: Operation �����У�
//	����������е��ö�Ӧ�� Implementor::OperationImp ���� . ������ģʽ��
//	��, Builder ��װ�˲�ͬ��������ɲ��ֵķ�ʽ�� �� Bridge ��װ�˲�ͬ��ʵ�ַ�ʽ.

#include "stdafx.h"

 
#include<iostream>
using namespace std;
//Ϊʵ��Abstraction����ĳ�����࣬ ������ʵ�ֵĽӿں���
class Implementor
{
public:
	Implementor(){}
	virtual ~Implementor(){}
	virtual void OperationImp()=0;
};
//�̳��� Implementor,��Implementor�Ĳ�ͬʵ��֮һ
class ConcreteImplementorA:public Implementor
{
public:
	ConcreteImplementorA(){}
	virtual ~ConcreteImplementorA(){}
	virtual void OperationImp()
	{ cout<<"Implementation by ConcreteImplementorA"<<endl; }
};
//�̳��� Implementor,��Implementor�Ĳ�ͬʵ��֮һ
class ConcreteImplementorB:public Implementor
{
public:
	ConcreteImplementorB(){}
	virtual ~ConcreteImplementorB(){}
	virtual void OperationImp()
	{ cout<<"Implementation by ConcreteImplementorB"<<endl; }
};
//ά��һ��Implementor���ָ��
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
