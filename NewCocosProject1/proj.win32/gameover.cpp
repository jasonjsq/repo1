#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include "gameover.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* gameover::createScene()
{
	//    // 'scene' is an autorelease object
	auto scene = Scene::create();


	// 'layer' is an autorelease object
	auto layer = gameover::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool gameover::init()
{

	if (!Layer::init())
	{
		return false;
	}

	
	return true;
}
