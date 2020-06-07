#include "eventserver.h"


eventserver::eventserver()
{
	m_slisten = SOCKET_ERROR;
	m_threadcount = 1;
	hlistentevent = WSACreateEvent();
	threads = new threadrecv[m_threadcount];
}
void eventserver::AssignToThread(SOCKET s, sockaddr_in addr)
{
	int min = threads[0].getclientsize();
	int index = 0;
	for (int i = 1; i < m_threadcount; i++)
	{
		if (min>threads[i].getclientsize())
		{
			min = threads[i].getclientsize();
			index = i;
		}
	}
	if (threads[index].getclientsize() >= 64)
	{
		printf("超过客户端链接上限!\n");
	}
	threads[index].pushclient(s, addr);
}


eventserver::~eventserver()
{
	WaitForSingleObject(hlistentevent, INFINITE);
	closesocket(m_slisten);
	delete[]threads;
}
eventserver::eventserver(int threadcount)
{
	m_slisten = SOCKET_ERROR;
	m_threadcount =threadcount;
	hlistentevent = WSACreateEvent();
	threads = new threadrecv[m_threadcount];
}
void eventserver::Binglisten()
{
	WSAEventSelect(m_slisten, hlistentevent, FD_ACCEPT | FD_CLOSE);

}
void eventserver::accept()
{
	while (1)
	{
		DWORD dw = WaitForSingleObject(hlistentevent, INFINITE);

		if (dw == WAIT_OBJECT_0)
		{		
			ResetEvent(hlistentevent);//进入一次就给他制成无信号等待
			sockaddr_in clientaddr = { 0 };
			int nlen = sizeof(sockaddr_in);

			SOCKET sclient = ::accept(m_slisten, (sockaddr*)&clientaddr, &nlen);
			if (sclient == SOCKET_ERROR)
			{
				printf("%s:%daccept failed!\n",inet_ntoa(clientaddr.sin_addr),(int)(clientaddr.sin_port));
				closesocket(sclient);
				continue;
			}else

			printf("客户端连接成功：%s\n", inet_ntoa(clientaddr.sin_addr));
		//	j++; printf("%d\n", j);
			//HANDLE h = CreateThread(0, 0, threadproc, (LPVOID)sclient, 0, 0);
			AssignToThread(sclient, clientaddr);
			
		}
		else
		{
			printf("wait fail! %d\n", WSAGetLastError());
		}



	}
}

void eventserver::Socket()
{
	
	//1.创建服务器的socket
	 m_slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_slisten == SOCKET_ERROR)
	{
		printf("创建失败");
		return ;
	}
	else
	{
		printf("服务器创建成功：");
	}
	//2.绑定 bindsocket
	
}
void eventserver::Bind(char*ip, unsigned short addr_)
{
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(addr_);//装换字节序（小端存储，打断存储）
	addr.sin_addr.S_un.S_addr = inet_addr(ip);
	if (bind(m_slisten, (const sockaddr*)&addr, sizeof(sockaddr_in)) != 0)
	{
		printf("socket error!\n");
		closesocket(m_slisten);
		//	return -1;
	}
	else
	{
		printf("bind succes  绑定成功");
	}

	//3.监听 listensocket
	listen(m_slisten, 10);
}