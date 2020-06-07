#pragma once
#include<string.h>
#include<stdio.h>
#include<windows.h>
enum  MSG_TYPE
{
	MSG_LOGIN,//��¼
	MSG_ZHUCE,
	MSG_LOGIN_REPLY,
	MSG_SIGN,
	MSG_SIGN_REPLY,
	MSG_EXIT,
	MSG_ENTER_TALKING,
	MSG_MSGTALKING_INFO,
	MSG_EXIT_TALKING,


};
struct MsgHead//��Ϣͷ  ��Ϣ����+��Ϣ����
{
	unsigned short msgType;
	unsigned short msgLength;

};
struct Msglogin :public MsgHead
{
	
	Msglogin()
	{
		msgType = MSG_LOGIN;
		msgLength = sizeof(Msglogin);
	}
	void setUserName(const char*n)
	{
		if (n == NULL || strlen(n) + 1 > 12)
		{
#ifdef _DEBUG
			OutputDebugString(TEXT("�û�����������"));
#endif
			return;
		}

		strcpy(userName, n);
	
	}
	void setPasswd(const char*n)
	{
		if (n == NULL || strlen(n) + 1 > 12)
		{
#ifdef _DEBUG
			OutputDebugString(TEXT("�����������"));
#endif
			return;
		}

		strcpy(passWord, n);

	}
	char* getname()
	{ return userName;
	}
	char* getpass()
	{
		return passWord;
	}
private:
	char userName[12];
	char passWord[12];

};
struct Msgzhuce :public MsgHead
{

	Msgzhuce()
	{
		msgType = MSG_ZHUCE;
		msgLength = sizeof(Msgzhuce);
	}
	void setUserName(const char*n)
	{
		if (n == NULL || strlen(n) + 1 > 12)
		{
#ifdef _DEBUG
			OutputDebugString(TEXT("�û�����������"));
#endif
			return;
		}

		strcpy(userName, n);

	}
	void setPasswd(const char*n)
	{
		if (n == NULL || strlen(n) + 1 > 12)
		{
#ifdef _DEBUG
			OutputDebugString(TEXT("�����������"));
#endif
			return;
		}

		strcpy(passWord, n);

	}
	char* getname()
	{
		return userName;
	}
	char* getpass()
	{
		return passWord;
	}
private:
	char userName[12];
	char passWord[12];

};
struct MsgLogin_reply :public MsgHead
{

	MsgLogin_reply()
	{
		msgType = MSG_LOGIN_REPLY;
		msgLength = sizeof(MsgLogin_reply);
	}

	int result;
};
struct Msgsign :public MsgHead
{

	Msgsign()
	{
		msgType = MSG_SIGN;
		msgLength = sizeof(Msgsign);
	}

};
struct Msgsign_reply :public MsgHead
{

	Msgsign_reply()
	{
		msgType = MSG_SIGN_REPLY;
		msgLength = sizeof(Msgsign_reply);
	}
	unsigned int result;

};
struct MsgExit :public MsgHead
{

	MsgExit()
	{
		msgType = MSG_EXIT;
		msgLength = sizeof(MsgExit);
	}
	

};
struct Msgenter_talking :public MsgHead
{
	char buff[2048];
	Msgenter_talking()
	{
		msgType = MSG_ENTER_TALKING ;
		msgLength = sizeof(Msgenter_talking);
		
	
	}
	


};
struct Msginfo :public MsgHead
{

	Msginfo()
	{
		msgType = MSG_MSGTALKING_INFO ;
		msgLength = sizeof(Msginfo);
	}
	char buffer[1024];


};