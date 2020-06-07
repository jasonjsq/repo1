#include"socketinit.h"
#pragma comment(lib,"Ws2_32.lib")

socketinit::socketinit()
{
	WORD version = MAKEWORD(2, 2);
	WSADATA data;
	WSAStartup(version,&data);
}
socketinit::~socketinit()
{
	WSACleanup();
}