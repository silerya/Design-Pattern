// Singleton ģʽ(����).cpp : �������̨Ӧ�ó������ڵ㡣
//


//������
//	Singleton ģʽ��ʵ�Ƕ�ȫ�־�̬������һ��ȡ������, �����ᵽ�� Singleton ģʽ��
//	���������� C++����ͨ�����µĻ���ʵ�ֵ�:
//1) ����һ��ʵ�����ṩһ����ľ�̬��Ա���������֪����ľ�̬��Ա��������һ����
//	�����ж��������Ωһ��
//	2) �ṩһ����������ȫ�ַ��ʵ�, Ҳ�����ṩ��Ӧ�ķ��������̬��Ա�����ľ�̬��Ա
//	����, ��������ж������Ҳ��Ωһ��. �� C++�У� ����ֱ��ʹ��������з��ʶ����س�
//	ʼ��һ����Ķ���.
//	�����ʵ����ʵ�� Singleton ��һ����ʵ��,�������ر��ͨ��, һ��ģ����һ����
//	Ŀ����Ҫʹ�õ� Singleton ģʽ�Ƚ϶�Ļ�, ��ôһ���ʵ��һ�� Singleton ��ģ
//	���࣬ģ�����ģ���������Ҫ���� Singleton ģʽ����, ��������ʵ�֣�


#include "stdafx.h"


//Template<typename T>
//class Singleton
//{
//	// . . .�������
//} ;
////��Ҫ���� singleton ģʽ����
//class Test:publicSingleton<Test>
// {
//			  // ���������};
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
	//��̬��Ա�������ṩȫ��Ψһ��һ��ʵ��
	static Singleton* _instance;


};
//��ľ�̬��Ա����Ҫ����������ж���
Singleton* Singleton::_instance = 0;


int main()
{
	Singleton* sgn = Singleton::Instance();
	Singleton* sgn2 = Singleton::Instance();
	Singleton* sgn3 = Singleton::Instance();
	return 0;
}
