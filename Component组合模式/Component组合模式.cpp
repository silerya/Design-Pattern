// Component���ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//


//������ࣺ
//	l)Component:Ϊ����еĶ��������ӿڣ� �������๲�нӿڵ�ȱʡ��Ϊ(�������
//	Add,Remove,GetChild ����),����һ���ӿں������Է��� Component ������
//	��.
//	�ӿں�����
//	1)Component:: Operatation:�����˸���������е���Ϊ�ӿڣ� �ɸ����������ʵ��.
//	2)Component::Add ���һ�������
//	3)Component::Remove:: ɾ��һ�������.
//	4)Component::GetChild: ����������ָ��
//	������
//	Component ģʽ��Ϊ������֮��ĵݹ�����ṩ�˽���İ취������Ҫ��Ϊ����
//	������, ���е� 
//	Leaf ��Ҷ�ӽ��, Ҳ���ǲ�����������Ľ��
//	Composite �Ǻ������������. 
//	��һ��������˵�����ģʽ���� UI �������, ������Ŀؼ�������
//	Button,Edit �����Ŀؼ�, �൱��������� Leaf���, ���Ƚϸ��ӵĿؼ����� List ���
//	Ҳ����������Щ�����������������Ŀؼ�,�൱������� Composite,����֮����
//	һЩ��Ϊ��������ͬ��,�����ڿؼ�����һ�����, �ƶ������ȵȵ�, ��Щ�����Զ���Ϊ
//	��������еĽӿ��麯�����ɸ���������ȥʵ��֮, ��Щ�����е���Ϊ���������
//	Operation ����, �����,ɾ���Ƚ��������ϵĲ���ֻ�з�Ҷ�ӽ��ſ�����, ������
//	�������ֻ���ṩ�ӿڶ���Ĭ�ϵ�ʵ����ʲô������.
//	ʵ�֣�

#include "stdafx.h"
#include <algorithm>

#include<iostream>
#include<list>
using namespace std;
//����еĳ������
class Component
{
public:
	Component(){}
	virtual ~Component(){}
	//II���麯���� ֻ�ṩ�ӿ� �� û��Ĭ�ϵ�ʵ��
		virtual void Operation()=0;
	//I II�麯���� �ṩ�ӿ� �� ��Ĭ�ϵ�ʵ�־���ʲô������
		virtual void Add(Component* pChild){}
	virtual void Remove(Component* pChild){}
	virtual Component* GetChild(int nIndex)
	{ return NULL; }
};
//������ Component�������е�Ҷ������Ļ���
class Leaf:public Component
{
public:
	Leaf(){}
	virtual ~Leaf(){}
	virtual void Operation()
	{ 
		cout<<"Operation by Leaf"<<endl; 
	}
};
//������ Component�������к����Ӽ������Ļ���
class Composite:public Component
{
public:
	Composite(){}
	virtual ~Composite()
	{
		list<Component*>::iterator iter1,iter2,temp;
		for(iter1=m_ListOfComponent.begin(),iter2=m_ListOfComponent.end();iter1!=iter2;)
		{
			temp = iter1;
			++iter1;
			delete(*temp);
		}
	}
	virtual void Operation()
	{
		cout<<"Operation by Conposite"<<endl;
		list<Component*>::iterator iter1,iter2;
		for(iter1=m_ListOfComponent.begin(),iter2=m_ListOfComponent.end();iter1!=iter2;++iter1)
		{
			(*iter1)->Operation();

		}
			
	}
	virtual void Add(Component* pChild)
	{
		m_ListOfComponent.push_back(pChild);
	}
	virtual void Remove(Component* pChild)
	{
		list<Component*>::iterator iter;
	
		iter = find(m_ListOfComponent.begin(),m_ListOfComponent.end(),pChild);
		

		if(m_ListOfComponent.end()!=iter)
		{
			m_ListOfComponent.erase(iter); 
		}
	}

	virtual Component* GetChild(int nIndex)
	{
		if(nIndex<=0||nIndex>m_ListOfComponent.size())
			return NULL;
		list<Component*>::iterator iter1,iter2;
		int i;
		for(i=1,iter1=m_ListOfComponent.begin(),iter2=m_ListOfComponent.end();
			iter1!=iter2;++iter1,++i)
		{
			if(i==nIndex)
				break;
		}
		return *iter1;
	}
private:

	//���� list����ȥ���������
	list<Component*> m_ListOfComponent;
};
int main()
{
	Leaf* pLeaf1 = new Leaf();
	Leaf* pLeaf2 = new Leaf();
	Composite* pComposite = new Composite;
	pComposite->Add(pLeaf1);
	pComposite->Add(pLeaf2);
	pComposite->Operation();
	pComposite->GetChild(2)->Operation();
	pComposite->Remove(pLeaf2);
	delete pComposite;
	return 0;
}

