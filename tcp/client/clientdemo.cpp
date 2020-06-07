#include "clientdemo.h"
#include<windows.h>
using namespace std;
#include<stdio.h>
#include"../msg/mshType.hpp"
clientdemo::clientdemo()
{

	
}


clientdemo::~clientdemo()
{
	WaitForSingleObject(h, INFINITE);
	for (int i = 0; i < m_clientcount; i++)
	{
closesocket(m_sclient[i]);
	}
	
	
}
void clientdemo::m_socket()
{
	for (int i = 0; i < m_clientcount; i++)
	{
		m_sclient[i] = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_sclient[i] == SOCKET_ERROR)
		{
			return;
		}
		printf("创建cheng\n");
	}
	
	return;

}
void clientdemo::m_connect(char *ip, unsigned short port)
{
	for (int i = 0; i < m_clientcount; i++)
	{
		sockaddr_in addr = { 0 };
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);//装换字节序（小端存储，打断存储）
		addr.sin_addr.S_un.S_addr = inet_addr(ip);
		printf("开始连接");
		if (connect(m_sclient[i], (const sockaddr*)&addr, sizeof(sockaddr_in)) != 0)
		{
			printf("connect failed!\n");
			//closesocket(m_sclient);
			return;
		}
		else
		{
			printf("连接成功");
		}
		printf("连接成功");
	}
	
}
void clientdemo::m_createth()

{

	h = CreateThread(0, 0,s, (LPVOID)this, 0, 0);
	h2 = CreateThread(0, 0, s1, (LPVOID)this, 0, 0);
	

}
 DWORD WINAPI clientdemo::s1(LPVOID r)
{
	 clientdemo *m = (clientdemo*)r;
	 char buffer[2048] = { "0" };

	 while (1)
	 {
		 
		 for (int i = 0; i < m->m_clientcount; i++)
		 {
			 recv(m->m_sclient[i], buffer, 2048, 0);
			
			 MsgHead *phead = (MsgHead*)buffer;
			 switch (phead->msgType)
			 {
			 case MSG_LOGIN_REPLY:
			 {
			 MsgLogin_reply *login = (MsgLogin_reply *)phead;
			 if (login->result)
			 {
				 printf("登录成功!\n");
			 }
			 else
			 {
				 printf("登录失败!\n");
			 }
				 break; 
			 }
			
			 default:
#ifdef _DEBUG
				 OutputDebugString(TEXT("有误"));
#endif
				 break;
			 }
			 return 0;


		 }

	 }


	 return 0;

}
void clientdemo::m_thcount(int n)
{
	m_clientcount = n;
	m_sclient = new SOCKET[n];

}
DWORD WINAPI clientdemo::s(LPVOID r)
{
	clientdemo *m = (clientdemo*)r;
	char buffer[1024] = { "msg" };
	
	while (1)
	{
		gets(buffer);
		for (int i = 0; i < m->m_clientcount; i++)
		{
			if (strcmp(buffer, "login") == 0)
			{
				char name[12];
				char pass[12];
				Msglogin msg;
				scanf("%s,%s", name, pass);
				msg.setPasswd(pass);
				msg.setUserName(name); 
				send(m->m_sclient[i], (const char*)&msg, msg.msgLength, 0);
			}
			else if (strcmp(buffer,"msg")==0)
			{
				
				Msgenter_talking msg1;
			
				msg1.msgLength = sizeof(Msgenter_talking);
				
			//	strncpy(msg1.buff,buffer,1024);
				send(m->m_sclient[i], (const char*)&msg1, msg1.msgLength, 0);
				Sleep(5);

			}
	

		}
		
	}
		
	
	return 0;

}