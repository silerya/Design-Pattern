// Builderģʽ(������).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


//�������������:
//1)���������Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ�䷽ʽʱ��
//	2)��������̱�����������Ķ����в�ͬ�ı�ʾʱ��
//	������ࣺ
//	1)Builder:���������ȫ������������̵ĳ����ṩ������ͬ��ɲ��ֵĽӿں���
//	�ӿڣ�

//	1)Builder::BuildPartA,Builder::BuildPartB: �Ƕ�һ������ͬ���ֵĹ�������
//	�ӿ� , Builder ��������������ʵ��.

//	���⻹��һ����Ҫע��ĺ���, ���� Director::Construct ����, �����������ͨ����
//	������������ӿں�����ɶ���Ĺ���--Ҳ����˵������ͬ����װ��Ĺ��̶���һ�µ�
//	��ͬ���ĵ��õ� Construct ����), ���ǲ�ͬ�Ĺ�����ʽ���в�ͬ�ı�ʾ(���� Builder
//	��ʵ��������������ι���,Ҳ���Ƕ�̬��

//	������
//	Builder ģʽ�ǻ���������һ�����:һ����������в�ͬ����ɲ���, �⼸�����ֵĲ�
//	ͬ�Ĵ���������в�ͬ�ı�ʾ, ���Ǹ�������֮��װ��ķ�ʽ��һ�µ�. �ȷ�˵һ����
//	���������ɳ��ֳ����ȵȵĹ��ɵ�(һ������ͬ����ɲ���),��ͬ��Ʒ������������Ҳ
//	��һ��(��ͬ�Ĺ�����ʽ).��Ȼ��ͬ��Ʒ�ƹ��������ĵ�����ͬ,���ǹ����Ĺ��̻���һ
//	����(Ŷ, ��������ֳ��ڳ����ϵ�ô�� ).Ҳ����˵, Director::Construct �����й̶�
//	�˸�����ɲ��ֵ�װ�䷽ʽ, ��������װ����������ɲ����� Builder ��������ʵ��.
//	ʵ�֣�

//	Builder ģʽ��ʵ�ֻ������¼��������������ԭ��:
//1)�ѱ仯�Ĳ�����ȡ�����γ�һ������Ͷ�Ӧ�Ľӿں���,�����ﲻ��仯���Ƕ���
//	���� PartA �� PartB,�仯�����ǲ�ͬ�Ĵ�������,���Ǿͳ�ȡ������� Builder ��
//	��� BuildPartA,BuildPartB �ӿں���
//	2)���þۺϵķ�ʽ�ۺ��˻ᷢ���仯�Ļ���,�������� Director �ۺ��� Builder ���ָ
//	��.


#include<iostream>
using namespace std;
//�������,������Builder�Ļ��࣬ �ṩ��ͬ���ֵĹ����ӿں���
class Builder   //���糵 
{
public:
	Builder(){}
	virtual ~Builder(){}
	//II���麯��,�ṩ������ͬ���ֵĹ����ӿں���
	virtual void BuilderPartA()=0;
	virtual void BuilderPartB()=0;
};


//ʹ�� Builder������Ʒ��������Ʒ�Ĺ��̶�һ�£����ǲ�ͬ��builder�в�ͬ��ʵ�������ͬ
//��ʵ��ͨ����ͬ��Builder��������ʵ�֣�����һ��Builder��ָ�룬ͨ�������ʵ�ֶ�̬����
class Director   //��������һ��
{
public:
	Director(Builder* pBuilder):m_pBuilder(pBuilder){}
	~Director()
	{
		delete m_pBuilder;
		m_pBuilder = NULL;
	}
	// Construct������ʾһ������������������̣���ͬ�Ĳ���֮���װ�䷽ʽ����һ�µ�,
	//���ȹ���PartA�����PartB,ֻ�Ǹ��ݲ�ͬ�Ĺ����߻��в�ͬ�ı�ʾ
		void Construct()
	{
		m_pBuilder->BuilderPartA();
		m_pBuilder->BuilderPartB();
	}
private:
	Builder* m_pBuilder;
};


//Builder�������࣬ʵ��BuilderPartA��BuilderPartB�ӿں���
class ConcreteBuilder1:public Builder
{
public:
	ConcreteBuilder1(){}
	virtual ~ConcreteBuilder1(){}
	virtual void BuilderPartA()
	{ cout<<"BuilderPartA by ConcreteBuilder1"<<endl; }
	virtual void BuilderPartB()
	{ cout<<"BuilderPartB by ConcreteBuilder1"<<endl; }
};


//Builder�������࣬ʵ��BuilderPartA��BuilderPartB�ӿں���
class ConcreteBuilder2:public Builder
{
public:
	ConcreteBuilder2(){}
	virtual ~ConcreteBuilder2(){}
	virtual void BuilderPartA()
	{ cout<<"BuilderPartA by ConcreteBuilder2"<<endl; }
	virtual void BuilderPartB()
	{ cout<<"BuilderPartB by ConcreteBuilder2"<<endl; }
};
int main()
{
	Builder* pBuilder1 = new ConcreteBuilder1;
	Director* pDirector1 = new Director(pBuilder1);
	pDirector1 ->Construct();
	Builder* pBuilder2 = new ConcreteBuilder2;
	Director* pDirector2 = new Director(pBuilder2);
	pDirector2->Construct();
	delete pDirector1;
	delete pDirector2;
	return 0;
}