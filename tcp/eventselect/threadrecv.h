#pragma once
#include<vector>
#include <iostream>
#pragma comment(lib,"C:\\Program Files\\MySQL\\MySQL Server 5.7\\lib\\libmysql.lib")
#include"../socket/socketinit.h"

#include <winsock2.h>
#include <windows.h>
#include <Windows.h>
#include <mysql.h>
#include <string>


struct clientobj
{
	SOCKET m_socket;
	sockaddr_in m_addr;
	WSAEVENT m_event;
	char buffer[2048];
	
};

class threadrecv
{ 
#define EVENT_SIZE 64
	HANDLE m_handle;
	CRITICAL_SECTION m_sec;
	WSAEVENT m_events[EVENT_SIZE];//添加一个重置事件
	std::vector<clientobj*>m_clients;
	std::vector<clientobj*>m_clientsbuffer;//创建缓存区
	
public:
	//00000000000000000000000000000000000000000000000000000000000000000000000000
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	int mysql=0;
	threadrecv();
	~threadrecv();
	void pushclient(SOCKET m_socket,sockaddr_in m_addr);
	int getclientsize();
	static DWORD WINAPI threadpro(LPVOID lp);
	int msgproc(SOCKET s,char*buff);
};

