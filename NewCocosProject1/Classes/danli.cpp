#include"danli.h"
#include"mshType.hpp"

int danli::createclient()
{
	danli::getinstance()->sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (danli::getinstance()->sclient == SOCKET_ERROR)
	{
		printf("´´½¨Ê§°Ü");
		return -1;
	}
	//2.connect

	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12306);//×°»»×Ö½ÚÐò£¨Ð¡¶Ë´æ´¢£¬´ò¶Ï´æ´¢£©
	addr.sin_addr.S_un.S_addr = inet_addr("192.168.101.4");
	if (connect(danli::getinstance()->sclient, (const sockaddr*)&addr, sizeof(sockaddr_in)) != 0)
	{
		printf("bind failed!\n");
		closesocket(danli::getinstance()->sclient);
		return -1;
	}
	return 0;
}
DWORD WINAPI danli::s(LPVOID)
{
	while (1)
	{

		char buffer[1000];
		recv(danli::getinstance()->sclient, buffer, 800, 0);
		MsgHead *phead = (MsgHead*)buffer;
		switch (phead->msgType)
		{
		case MSG_LOGIN_REPLY:
		{
				MsgLogin_reply *login = (MsgLogin_reply *)phead;
				if (login->result)
				{
					danli::getinstance()->dengluok = true;
					danli::getinstance()->zhuce = true;
					//memset(danli::getinstance()->buffer,0, sizeof(char)*2048);
				}

								break;
		}
			break;
		}

	}
}
void danli::createthread()
{
  h = CreateThread(0, 0, s, (LPVOID)this, 0, 0);
}

danli* danli::p = NULL;