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
	string name;//登录
	string pass;
	string zname;//注册
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
//		Lock();//借用其它类来实现，如boost  
//		if (NULL == m_instance)
//		{
//			m_instance = new danli;
//		}
//		UnLock();
//	}
//	return m_instance;
//}



