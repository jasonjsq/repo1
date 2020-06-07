#pragma once
#include"../socket/socketinit.h"
class clientdemo
{
	socketinit init;
	SOCKET *m_sclient;
	int m_clientcount;
	HANDLE h;
	HANDLE h2;
	
public:
	clientdemo();
	
	~clientdemo();
	void m_socket();
	void m_connect(char *ip,unsigned short port);
	void m_createth();
	void m_thcount(int n);
	static DWORD WINAPI s(LPVOID r);
	static DWORD WINAPI s1(LPVOID r);


};

