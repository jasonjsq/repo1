#pragma once
#include "threadrecv.h"
#include"../msg/mshtype.hpp"

#include<string>
using namespace std;
threadrecv::threadrecv()
{
	InitializeCriticalSection(&m_sec);
	m_events[0] = WSACreateEvent();
	m_handle = CreateThread(0, 0, threadpro, this, 0, 0);
}


threadrecv::~threadrecv()
{
	WaitForSingleObject(m_handle, INFINITE);
	CloseHandle(m_handle);
	CloseHandle(m_events[0]);
	DeleteCriticalSection(&m_sec);
	int s = m_clients.size();
	for (int i = 0; i < s; i++)
	{
		closesocket(m_clients[i]->m_socket);
		CloseHandle(m_clients[i]->m_event);
		delete m_clients[i];
	}
	m_clients.clear();

	

}
int threadrecv::getclientsize()
{
	return m_clients.size();
}

void threadrecv::pushclient(SOCKET m_socket, sockaddr_in m_addr)
{
	clientobj *c = new clientobj;
	c->m_socket = m_socket;
	c->m_addr = m_addr;
	c->m_event = WSACreateEvent();
	//m_events[m_clients.size()]= c->m_event;
	WSAEventSelect(c->m_socket, c->m_event, FD_READ | FD_CLOSE);
	EnterCriticalSection(&m_sec);
	m_clientsbuffer.push_back(c);
	LeaveCriticalSection(&m_sec);
	SetEvent(m_events[0]);


}
int threadrecv::msgproc(SOCKET s, char*buffer)
{
	
	const char user[] = "root";
	const char pswd[] = "123456";
	const char host[] = "localhost";
	const char table[] = "user";
	unsigned int port = 3306;
	if (mysql == 0)
	{
		mysql = 1;
		mysql_init(&myCont);
		if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
		{
			printf("数据库连接成功！！！\n");
		}
		else
		{
			printf("数据库连接失败！！！\n");
		}
	}
	MsgHead *phead = (MsgHead*)buffer;
	switch (phead->msgType)
	{
	case MSG_LOGIN:
	{
	  
	 Msglogin *login = (Msglogin *)phead;
	 char* m = login->getname();
	 char* n = login->getpass();
	 string q1 = "select * from users where username = '";
	 string q2 = m;
	 string q3 = "'and pass = '";
	 string q4 = n;
	 string q5 = "'";
	 string cc = q1 + q2 + q3 + q4 + q5;
	 const char *pp = cc.c_str();
	 cout << pp<<endl;
	// Sleep(1000);
	 //数据库查询登录信息
	 int res;
	 res = mysql_query(&myCont, pp);
	 if (!res)
	 {
		 result = mysql_store_result(&myCont);
		 if (result)
		 {
			 MsgLogin_reply reply;
			 int aa = 0;
			 if (sql_row = mysql_fetch_row(result))//获取具体的数据
			 {
				 printf("可以登录\n");
				 reply.result = 1;
				 send(s, (const char*)&reply, reply.msgLength, 0);
				 aa = 1;
			 }
			
		 }
	 }
	 else
	 {
		 printf("查询失败！！\n");
	 }

	 break;	
	} 
		break;
	case MSG_ENTER_TALKING:
	{
	 Msgenter_talking *f = (Msgenter_talking*)phead;
	 printf("接受到数据：%s\n",f->buff);
	// printf("接受到数据:%s\n", f->buff);
	 break;
	}
	case MSG_ZHUCE:
	{
					  Msgzhuce *login = (Msgzhuce *)phead;
					  char* m = login->getname();
					  char* n = login->getpass();
					  string q11 = "select * from users where username = '";
					  string q21 = m;
					  string q31 = "'and pass = '";
					  string q41 = n;
					  string q51 = "'";
					  string cc1 = q11 + q21 + q31 + q41 + q51;
					  const char *pp1 = cc1.c_str();
					 
					  //cout << pp1 << endl;
					  //数据库查询登录信息
					  int res1;
					  res1 = mysql_query(&myCont, pp1);
					  if (!res1)
					  {
						  cout << "1" << endl;
						  result = mysql_store_result(&myCont);
						  if (result)
						  {
							  cout << '2'<<endl;
							  MsgLogin_reply reply;
						     int aa = 0;
							  if (sql_row = mysql_fetch_row(result))//获取具体的数据
							  {
								  cout << "asda" << endl;
							  }
							  else
							  {	
								  string q1 = "insert into users values ('";
								  string q2 = m;
								  string q3 = "','";
								  string q4 = n;
								  string q5 = "')";
								  string cc = q1 + q2 + q3 + q4 + q5;
								  const char *pp = cc.c_str();

								  cout << '4' << endl;
								  //数据库查询登录信息
								  int res;
								  res = mysql_query(&myCont, pp);
								  if (!res)
								  {
									  cout << pp << endl;
									  result = mysql_store_result(&myCont);
									  if (result)
									  {
										  MsgLogin_reply reply;
										  int aa = 0;
										  if (sql_row = mysql_fetch_row(result))//获取具体的数据
										  {
											  printf("注册成功\n");
											  reply.result = 1;
											  send(s, (const char*)&reply, reply.msgLength, 0);

										  }
									  }
								  }
								  else
								  {
									  printf("查询失败！！\n");
								  }
							  }

						  }
					  }
					  else
					  {
						  printf("查询失败！！\n");
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
DWORD WINAPI threadrecv::threadpro(LPVOID lp)
{
	threadrecv *pthread  = (threadrecv*)lp;
	
	while (1)
	{
		int t = pthread->m_clients.size();
		DWORD index = WSAWaitForMultipleEvents(t+1, pthread->m_events, false, INFINITE, 0);
		for (int i = index; i<t+1; i++)
		{			
		DWORD dw = WSAWaitForMultipleEvents(1, &(pthread->m_events[i]), true, 0, 0);
			if (dw == WAIT_OBJECT_0)
			{
				if (i == 0)
				{
					int size = pthread->m_clientsbuffer.size();					
					EnterCriticalSection(&pthread->m_sec);
					if (size != 0)
					{
						
						for (int i = 0; i < size; i++)
						{
							pthread->m_clients.push_back(pthread->m_clientsbuffer[i]);
						}
						pthread->m_clientsbuffer.clear();
						
					}
					LeaveCriticalSection(&pthread->m_sec);
					size = pthread->m_clients.size();

					if (size != 0)
					{
						for (int i = 0; i < size; i++)
						{
							
							pthread->m_events[i + 1] = pthread->m_clients[i]->m_event;
						}
					}
					//重置事件有信号了；
					ResetEvent(pthread->m_events[i]);	
					
					//printf("%d", size);
					break;
				}

				ResetEvent(pthread->m_events[i]);
				WSANETWORKEVENTS networkEvents;
				int ret = WSAEnumNetworkEvents(pthread->m_clients[i-1]->m_socket, pthread->m_events[i], &networkEvents);
				if (ret == 0)
				{
					if (networkEvents.iErrorCode[FD_READ] == 0)
					{
						
						continue;
					}
					if (networkEvents.lNetworkEvents&FD_READ)
					{
						clientobj  *client;
						
						client= pthread->m_clients[i - 1];
					
						int n = recv(client->m_socket, client->buffer, 1024, 0);
						
						if (n > 0)
						{	printf("接受到数据:%s\n", client->buffer);
							pthread->msgproc(client->m_socket, client->buffer);
							
						}
						else
						{
							printf("客户端关闭!\n");
							closesocket(pthread->m_clients[i - 1]->m_socket);
							CloseHandle(pthread->m_clients[i - 1]->m_event);
							delete pthread->m_clients[i - 1];
							pthread->m_clients.erase(pthread->m_clients.begin() + i - 1);
							SetEvent(pthread->m_events);
							break;

						}
					}
					if (networkEvents.lNetworkEvents&FD_CLOSE)
					{
						if (networkEvents.iErrorCode[FD_CLOSE_BIT] != 0)
						{

							printf("FD_CLOSE %d\n", networkEvents.iErrorCode[FD_CLOSE]);
						}
						printf("客户端关闭!\n");
						closesocket(pthread->m_clients[i-1]->m_socket);
						CloseHandle(pthread->m_clients[i - 1]->m_event);
						delete pthread->m_clients[i - 1];
						pthread->m_clients.erase(pthread->m_clients.begin() + i - 1);
						SetEvent(pthread->m_events);
						//break;
					}
						
				}
				else
				{
					printf("recv fail %d\n", WSAGetLastError());
				}
				
				
			}
		}
	}

		return 0;
}