#pragma once
#include<iostream>
using namespace std;
#include"socket.h"
class danli
{
protected:
	danli(){}
private:
	static danli* p;
public:
	static danli* getinstance()
	{
		if (p == NULL)
			p = new danli();
		return p;
	}
	string name;//��¼
	string pass;
	string zname;//ע��
	string zpass;
	char buffer[1024];
	SOCKET sclient;
	int createclient();
	bool dengluok = false;
	bool zhuce = false;
	socketinit init;
	static DWORD WINAPI s(LPVOID);
	HANDLE h;
	void createthread();

};
//class danli
//{
//private:
//	static danli* m_instance;
//	danli(){}
//public:
//	static danli* getInstance();
//};
//
//danli* danli::getInstance()
//{
//	if (NULL == m_instance)
//	{
//		Lock();//������������ʵ�֣���boost  
//		if (NULL == m_instance)
//		{
//			m_instance = new danli;
//		}
//		UnLock();
//	}
//	return m_instance;
//}



