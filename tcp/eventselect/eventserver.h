#pragma once

#include<iostream>

#include"../socket/socketinit.h"
#include"threadrecv.h"
class eventserver
{
	socketinit init;
	SOCKET  m_slisten;
	int m_threadcount;
	HANDLE hlistentevent; int j = 0;
	threadrecv *threads;
	void AssignToThread(SOCKET s, sockaddr_in addr);
public:
	eventserver();
	eventserver(int m_threadcount);
	~eventserver();
	void Socket();
	
	void Bind(char*ip, unsigned short addr);
	void Binglisten();

	void accept();
};

