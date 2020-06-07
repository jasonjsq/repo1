#include<iostream>
using namespace std;
#include"../socket/socketinit.h"
DWORD WINAPI s(LPVOID r)
{
	char buffer[1000];
	SOCKET sclient = (SOCKET)r;
	while (1)
	{
		int n = recv(sclient, buffer, 1000, 0);
		if (n > 0)
		{
			printf("接受到数据:%s\n", buffer);
		}
	}
	closesocket(sclient);
	//5.recv/send 接受发送数据
}

int main()
{
	socketinit init;
	//1.创建服务器的socket
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == SOCKET_ERROR)
	{
		printf("创建失败");
		
		
		return -1;
	}
	//2.绑定 bindsocket
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12306);//装换字节序（小端存储，打断存储）
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.128");
	if (bind(slisten, (const sockaddr*)&addr, sizeof(sockaddr_in)) != 0)
	{
		printf("socket error!\n");
		closesocket(slisten);
		return -1;
	}
	//3.监听 listensocket
	listen(slisten, 10);
	//4.接受 accept连接
	sockaddr_in clientaddr = { 0 };
	int nlen = sizeof(sockaddr_in);
	while (1)
	{
		SOCKET sclient = accept(slisten, (sockaddr*)&clientaddr, &nlen);
		if (sclient == SOCKET_ERROR)
		{
			printf("accept failed!\n");

			closesocket(slisten);
			return -1;
		}

		printf("scusece");

		HANDLE h = CreateThread(0, 0, s, LPVOID(sclient), 0, 0);
	}
	


	


	
	//6. 关闭套接字
	
	closesocket(slisten);



	return 0;
}