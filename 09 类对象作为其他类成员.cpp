#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>


//�ֻ���
class Phone
{
public:

	Phone()
	{
		cout << "Phone��Ĭ�Ϲ��캯������" << endl;
	}

	Phone(string pName)
	{
		cout << "Phone���вι��캯������" << endl;
		m_PhoneName = pName;
	}

	~Phone()
	{
		cout << "Phone��������������" << endl;
	}

	string m_PhoneName;
};

//��Ϸ��
class Game
{
public:

	Game()
	{
		cout << "Game��Ĭ�Ϲ��캯������" << endl;
	}

	Game(string gName)
	{
		cout << "Game���вι��캯������" << endl;
		m_GameName = gName;
	}

	~Game()
	{
		cout << "Game��������������" << endl;
	}

	string m_GameName;
};



//����
class Person
{
public:

	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	//��ʼ���б�ʵ�����Գ�ʼ��
	Person(string name, string pName, string gName) :m_Name(name), m_Phone(pName), m_Game(gName)
	{
		cout << "Person���вι��캯������" << endl;
	}

	void playGame()
	{
		cout << m_Name << " ���� << " << m_Phone.m_PhoneName << " >>���ֻ� ���ţ� " << m_Game.m_GameName << endl;
	}

	~Person()
	{
		cout << "Person��������������" << endl;
	}

	//����
	string m_Name;
	//�ֻ�
	Phone m_Phone;
	//��Ϸ
	Game m_Game;

	
};

void test01()
{
	//����������� ��Ϊ�����еĳ�Ա�������˳���ǣ��ȵ������������Ĺ��죬�ٵ��ñ��๹�죬����˳���빹���෴
	Person p1("Tom","ƻ��","�Լ�");
	p1.playGame();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}