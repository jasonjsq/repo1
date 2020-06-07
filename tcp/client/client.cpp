#include<iostream>
using namespace std;
#include"../socket/socketinit.h"
#include"clientdemo.h"
int main()
{
	socketinit init;
	//1.创建服务器的socket
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == SOCKET_ERROR)
	{
		printf("创建失败");
		return -1;
	}
	//2.connect
	
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12306);//装换字节序（小端存储，打断存储）
	addr.sin_addr.S_un.S_addr =inet_addr("192.168.0.175");
	if(connect(sclient,(const sockaddr*)&addr,sizeof(sockaddr_in))!=0)
	{
		printf("bind failed!\n");
		closesocket(sclient);
		
		return -1;
	}
	
	system("pause");
	//3.recv/send 接受发送数据

	//4. 关闭套接字
	/*char buffer[1000];
	while (1)
	{
		gets(buffer);
		send(sclient, buffer, strlen(buffer) + 1, 0);
	}
	closesocket(sclient);*/

	/*clientdemo sr[1];
	for (int i = 0; i < 1; i++)
	{
		sr[i].m_thcount(1);
	}
	for (int i = 0; i < 1; i++)
	{
		sr[i].m_socket();
		sr[i].m_connect("192.168.0.128",12306);
		sr[i].m_createth();
	}
*/

	return 0;
}