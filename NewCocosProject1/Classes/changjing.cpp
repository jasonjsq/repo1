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
	


	nandu = 0;
	auto m = CSLoader::createNode("Scene.csb");
	addChild(m);
	auto tishi1 = m->getChildByName("ts_14");
	auto tishi2 = m->getChildByName("jg_15");
	auto tishi3 = m->getChildByName("Text_2");
	auto denglu = m->getChildByName("Button_1");
	auto qd = m->getChildByName("Text_3");
	auto denglu1 = (ui::Button*)denglu;
	denglu1->addClickEventListener([=](Ref*){
		if (nandu == 0)
		{
			tishi1->setOpacity(180);
			qd->setOpacity(180);
			auto ok = m->getChildByName("Button_6");
			auto ok1 = (ui::Button*)ok;
			ok1->addClickEventListener([=](Ref*){
				tishi1->setOpacity(0);
				tishi2->setOpacity(0);
				tishi3->setOpacity(0);
				qd->setOpacity(0);

			});
			auto no = m->getChildByName("Button_7");
			auto no1 = (ui::Button*)no;
			no1->addClickEventListener([=](Ref*){
				tishi1->setOpacity(0);
				tishi2->setOpacity(0);
				tishi3->setOpacity(0);
				qd->setOpacity(0);
			});
		}
		else
		{
			
			Director::getInstance()->pushScene(TransitionFade::create(3, HelloWorld::createScene()));
		}
	});
	auto jiandan = m->getChildByName("Button_2");
	auto jiandan1 = (ui::Button*)jiandan;
	jiandan1->addClickEventListener([=](Ref*){
		tishi1->setOpacity(0);
		tishi2->setOpacity(0);
		tishi3->setOpacity(0);
		qd->setOpacity(0);
		nandu = 1;
	});
	auto putong = m->getChildByName("Button_3");
	auto putong1 = (ui::Button*)putong;
	putong1->addClickEventListener([=](Ref*){
		tishi1->setOpacity(0);
		tishi2->setOpacity(0);
		tishi3->setOpacity(0);
		qd->setOpacity(0);
		nandu = 2;
	});
	auto kunnan = m->getChildByName("Button_5");
	auto kunnan1 = (ui::Button*)kunnan;
	kunnan1->addClickEventListener([=](Ref*){
		tishi1->setOpacity(0);
		tishi2->setOpacity(0);
		tishi3->setOpacity(0);
		qd->setOpacity(0);	
		tishi1->setOpacity(180);
		tishi2->setOpacity(255);
		tishi3->setOpacity(255);
		auto ok = m->getChildByName("Button_6");
		auto ok1 = (ui::Button*)ok;
		ok1->addClickEventListener([=](Ref*){
			tishi1->setOpacity(0);
			tishi2->setOpacity(0);
			tishi3->setOpacity(0);
			nandu = 3;
		});
		auto no = m->getChildByName("Button_7");
		auto no1 = (ui::Button*)no;
		no1->addClickEventListener([=](Ref*){
			tishi1->setOpacity(0);
			tishi2->setOpacity(0);
			tishi3->setOpacity(0);
			nandu = 0;
		});		
	});
	return true;
}
