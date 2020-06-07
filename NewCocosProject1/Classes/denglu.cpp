//#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include "denglu.h"
#include<iostream>
#include"mshType.hpp"
using namespace std;
#include"socket.h"
#include"changjing.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* denglu::createScene()
{
	//    // 'scene' is an autorelease object
	auto scene = Scene::create();


	// 'layer' is an autorelease object
	auto layer = denglu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}


// on "init" you need to initialize your instance
bool denglu::init()
{
	
	if (!Layer::init())
	{
		return false;
	}
	
	danli::getinstance()->createclient();
	danli::getinstance()->createthread();
	auto m = CSLoader::createNode("Scene2.csb");
	addChild(m);
	auto tishi1 = m->getChildByName("ts_2");
	auto tishi2 = m->getChildByName("Text_3");
	auto ok = m->getChildByName("Button_1");
	auto ok1 = (ui::Button*)ok;
	auto no = m->getChildByName("Button_2");
	auto no1 = (ui::Button*)no;
	auto denglu = m->getChildByName("Button_5");
	auto denglu1 = (ui::Button*)denglu;
	ok1->addClickEventListener([=](Ref*){
		tishi1->setOpacity(0);
		tishi2->setOpacity(0);
	});
	
	denglu1->addClickEventListener([=](Ref*){
	
		auto x = (ui::TextField*)m->getChildByName("TextField_2");
		auto l = x->getString();
		danli::getinstance()->name=l;
		auto x1 = (ui::TextField*)m->getChildByName("TextField_1");
		auto l1 = x1->getString();
		danli::getinstance()->pass = l1;
		strcpy(danli::getinstance()->buffer,"login") ;
	
	});
	auto zhuce = m->getChildByName("Button_5_0");
	auto zhuce1 = (ui::Button*)zhuce;
	zhuce1->addClickEventListener([=](Ref*){
		auto x = (ui::TextField*)m->getChildByName("TextField_2");
		auto l = x->getString();
		danli::getinstance()->name = l;
		auto x1 = (ui::TextField*)m->getChildByName("TextField_1");
		auto l1 = x1->getString();
		danli::getinstance()->pass = l1;
		strcpy(danli::getinstance()->buffer, "zhuce");
		

	});
	/*auto money_hero = Label::create("", "", 50);
	addChild(money_hero);
	char b[500];
	auto d = itoa(i, b, 10);
	money_hero->setString(d);
	money_hero->setPosition(500, 500);
	Sleep(10000);*/
	schedule([=](float){
		if (strcmp(danli::getinstance()->buffer, "login") == 0)
		{

			Msglogin msg;
			msg.setPasswd(danli::getinstance()->pass.c_str());
			msg.setUserName(danli::getinstance()->name.c_str());
			send(danli::getinstance()->sclient, (const char*)&msg, msg.msgLength, 0);
		}
		else if (strcmp(danli::getinstance()->buffer, "msg") == 0)
		{

			Msgenter_talking msg1;

			msg1.msgLength = sizeof(Msgenter_talking);

			//	strncpy(msg1.buff,buffer,1024);
			send(danli::getinstance()->sclient, (const char*)&msg1, msg1.msgLength, 0);
		}
		else if (strcmp(danli::getinstance()->buffer, "zhuce") == 0)
		{

			Msgzhuce msg;
			msg.setPasswd(danli::getinstance()->pass.c_str());
			msg.setUserName(danli::getinstance()->name.c_str());
			send(danli::getinstance()->sclient, (const char*)&msg, msg.msgLength, 0);
		}

	}, 0.1, "fasong");//技能冷却
	schedule([=](float){
		if (danli::getinstance()->dengluok)
		{
			Director::getInstance()->pushScene(changjing::createScene());
		}
		if (danli::getinstance()->zhuce)
		{
			tishi1->setOpacity(255);
			tishi2->setOpacity(255);
			danli::getinstance()->zhuce = false;
		}

	}, 0.01, "huanchangjing");//技能冷却


	return true;
}
