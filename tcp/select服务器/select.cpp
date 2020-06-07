#include<iostream>
using namespace std;
#include"../socket/socketinit.h"
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
	//	return -1;
	}
	
	//3.监听 listensocket
	listen(slisten, 10);
	fd_set st;
	
	FD_ZERO(&st);
	FD_SET(slisten,&st);
	timeval tv = {1,0};
	fd_set st1=st;
	
	while (1)
	{
		st = st1;
	
		int t = select(0, &st, 0, 0, &tv);
		//cout << t;
		if (t == 0)
		{
			continue;
		}
		else if (t > 0)
		{
			for (int i = 0; i < t; i++)
			{
				if (st.fd_array[i] == slisten)
				{
					sockaddr_in clientaddr = { 0 };
					int nlen = sizeof(sockaddr_in);

					SOCKET sclient = accept(slisten, (sockaddr*)&clientaddr, &nlen);
					if (sclient == SOCKET_ERROR)
					{
						printf("accept failed!\n");
						closesocket(sclient);
						continue;
					}

					printf("客户端连接成功：%s\n", inet_ntoa(clientaddr.sin_addr));
					FD_SET(sclient, &st1);
				}
				else
				{
					char buffer[1024] = {0};
					
				
						int n = recv(st.fd_array[i], buffer, 1024, 0);
						if (n > 0)
						{
							printf("接受到数据:%s\n", buffer);
						}
						else
						{
							closesocket(st.fd_array[i]);
							printf("服务器关闭\n");
							FD_CLR(st.fd_array[i], &st1);
							break;
						}
					
						
				}
			}

		}
		else
		{
			printf("select error");
		}
	
	

	
	
	}
	closesocket(slisten);
	return 0;
}