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
			printf("���ܵ�����:%s\n", buffer);
		}
	}
	closesocket(sclient);
	//5.recv/send ���ܷ�������
}

int main()
{
	socketinit init;
	//1.������������socket
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == SOCKET_ERROR)
	{
		printf("����ʧ��");
		
		
		return -1;
	}
	//2.�� bindsocket
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12306);//װ���ֽ���С�˴洢����ϴ洢��
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.0.128");
	if (bind(slisten, (const sockaddr*)&addr, sizeof(sockaddr_in)) != 0)
	{
		printf("socket error!\n");
		closesocket(slisten);
		return -1;
	}
	//3.���� listensocket
	listen(slisten, 10);
	//4.���� accept����
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
	


	


	
	//6. �ر��׽���
	
	closesocket(slisten);



	return 0;
}