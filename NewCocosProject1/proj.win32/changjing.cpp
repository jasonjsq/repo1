#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include"SimpleAudioEngine.h"
#include "changjing.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* changjing::createScene()
{
	//    // 'scene' is an autorelease object
	auto scene = Scene::create();


	// 'layer' is an autorelease object
	auto layer = changjing::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool changjing::init()
{

	if (!Layer::init())
	{
		return false;
	}

	auto m = CSLoader::createNode("Scene.csb");
	addChild(m);
	auto y = m->getChildByName("button1_8");
	auto y1 = (ui::Button*)y;
	y1->addClickEventListener([](Ref*){
		Director::getInstance()->pushScene(HelloWorld::createScene());

	});





	return true;
}
