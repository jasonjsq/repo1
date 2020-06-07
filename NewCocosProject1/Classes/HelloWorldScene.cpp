#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "changjing.h"
#include<windows.h>
USING_NS_CC;



using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
bool xiaoguai::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	ok_move = true;
	xuetiao= LayerColor::create(Color4B::RED, 30, 6);
	return true;
}

bool hero::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	jin = 0;
	Grade = 1;
	attack = 40 ;
	attack_sudu = 100 ;
	attack_double = 10;
	attack_double_double = 1 ;
	jineng_1 = false;
    jineng_1_ok=false;
	return true;

}
int hero::attack_value()
{
	int x=this->attack + rand() % 9;

	int y = 1;
	if (this->attack_double > rand() % 100)
	{
		y = 2 * attack_double_double;
	}
	return x * y;

}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
   
    if ( !Layer::init() )
    {
        return false;
    }
	count = 0;
	this->jn = false;	
	h = CreateThread(0, 0, threadcreate, this, 0, 0);
	//unschedule("jinengshanghai");
	hero_ = hero::create();
	auto x = changjing::create();
	addChild(x);
	addChild(hero_);
	money_hero = 0;
	hero_create = false;
	num = 0;
	auto money_lable = Label::create("0","0", 20);
	money_lable->setPosition(830, 23);
	money_lable->setZOrder(2);
	addChild(money_lable);
	auto attck_lable = Label::create("0", "0", 20);
	attck_lable->setPosition(900, 114);
	attck_lable->setZOrder(2);
	addChild(attck_lable);
	auto attck_sudu_lable = Label::create("0", "0", 20);
	attck_sudu_lable->setPosition(837, 83);
	attck_sudu_lable->setZOrder(2);
	addChild(attck_sudu_lable);
	auto attck_double_lable = Label::create("0", "0", 20);
	attck_double_lable->setPosition(820, 54);
	attck_double_lable->setZOrder(2);
	addChild(attck_double_lable);
	auto level_lable = Label::create("0", "0", 20);
	level_lable->setPosition(811, 144);
	level_lable->setZOrder(2);
	addChild(level_lable);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("hero1.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("tx.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("v1.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("n2.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("hero1level.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("jineng1.plist");
	auto hero1level = Animation::create();
	auto jineng1 = Animation::create();
	auto hero_actck = Animation::create();
	auto tx = Animation::create();
	auto v_rzuo = Animation::create();
	auto v_ryou = Animation::create();
	auto v_rshang = Animation::create();
	auto v_rxia = Animation::create();
	auto n2_shang = Animation::create();
	auto n2_xia = Animation::create();
	auto n2_zuo = Animation::create();
	auto n2_you = Animation::create();
	auto stand = Animation::create();
	stand->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero (1).png"));
	jineng1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("jineng1 (1).png"));
	jineng1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("jineng1 (2).png"));
	jineng1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("jineng1 (3).png"));
	jineng1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("jineng1 (4).png"));
	jineng1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("jineng1 (5).png"));
	jineng1->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("jineng1 (6).png"));
	hero1level->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("level (6).png"));
	hero1level->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("level (9).png"));
	hero1level->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("level (4).png"));
	hero_actck->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero (1).png"));
	hero_actck->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero (2).png"));
	hero_actck->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero (3).png"));
	hero_actck->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("hero (4).png"));
	tx->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tx (1).png"));
	tx->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tx (3).png"));
	tx->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tx (4).png"));
	tx->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tx (5).png"));	
	tx->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("tx (7).png"));
	v_rzuo->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (6).png"));
	v_rzuo->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (7).png"));
	v_rzuo->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (8).png"));
	v_rzuo->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (9).png"));
	v_ryou->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (10).png"));
	v_ryou->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (11).png"));
	v_ryou->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (12).png"));
	v_ryou->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (13).png"));
	v_rshang->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (1).png"));
	v_rshang->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (14).png"));
	v_rshang->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (15).png"));
	v_rshang->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (16).png"));
	v_rxia->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (2).png"));
	v_rxia->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (3).png"));
	v_rxia->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (4).png"));
	v_rxia->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("v1 (5).png"));
	n2_shang->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("0.png"));
	n2_shang->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("1.png"));
	n2_shang->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("2.png"));
	n2_shang->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("3.png"));
	n2_xia->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("12.png"));
	n2_xia->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("13.png"));
	n2_xia->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("14.png"));
	n2_xia->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("15.png"));
	n2_zuo->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("8.png"));
	n2_zuo->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("9.png"));
	n2_zuo->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("10.png"));
	n2_zuo->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("11.png"));
	n2_you->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("4.png"));
	n2_you->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("5.png"));
	n2_you->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("6.png"));
	n2_you->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("7.png"));
	hero1level->setDelayPerUnit(0.2);
	hero1level->setLoops(1);
	jineng1->setDelayPerUnit(0.2);
	jineng1->setLoops(1);
	hero_actck->setLoops(1);
	float a = 0.1;
	hero_actck->setDelayPerUnit(a);
	stand->setDelayPerUnit(1);
	stand->setLoops(-1);
	tx->setLoops(1);
	tx->setDelayPerUnit(0.2);
	v_rzuo->setLoops(-1);
	v_rzuo->setDelayPerUnit(0.01);
	v_ryou->setLoops(-1);
	v_ryou->setDelayPerUnit(0.01);
	v_rshang->setLoops(-1);
	v_rshang->setDelayPerUnit(0.01);
	v_rxia->setLoops(-1);
	v_rxia->setDelayPerUnit(0.01);
	n2_shang->setDelayPerUnit(0.3);
	n2_shang->setLoops(1);
	n2_xia->setDelayPerUnit(0.3);
	n2_xia->setLoops(1);
	n2_zuo->setDelayPerUnit(0.3);
	n2_zuo->setLoops(1);
	n2_you->setDelayPerUnit(0.3);
	n2_you->setLoops(1);
	AnimationCache::getInstance()->addAnimation(hero_actck,"hero_actck");
	AnimationCache::getInstance()->addAnimation(tx, "tx");
	AnimationCache::getInstance()->addAnimation(v_rzuo, "v_rzuo");
	AnimationCache::getInstance()->addAnimation(v_ryou, "v_ryou");
	AnimationCache::getInstance()->addAnimation(v_rshang, "v_rshang");
	AnimationCache::getInstance()->addAnimation(v_rxia, "v_rxia");
	AnimationCache::getInstance()->addAnimation(n2_shang, "n2_shang");
	AnimationCache::getInstance()->addAnimation(n2_xia, "n2_xia");
	AnimationCache::getInstance()->addAnimation(n2_zuo, "n2_zuo");
	AnimationCache::getInstance()->addAnimation(n2_you, "n2_you");
	AnimationCache::getInstance()->addAnimation(stand, "stand");
	AnimationCache::getInstance()->addAnimation(hero1level, "hero1level");
	AnimationCache::getInstance()->addAnimation(jineng1, "jineng1");
    auto rootNode = CSLoader::createNode("MainScene.csb");
	addChild(rootNode);
	rootNode->getChildByTag(171)->setZOrder(2);
	auto fanwei = Sprite::create("fanwei.png");
	fanwei->setScale(3);
	fanwei->setTag(101);
	fanwei->setOpacity(0);
	fanwei->setPosition(125, 90);
	rootNode->getChildByTag(171)->addChild(fanwei);
	auto weaponone = rootNode->getChildByName("Button_1");
	auto weaponone_ = (ui::Button*)weaponone;
	auto weapontwo = rootNode->getChildByName("Button_1_0");
	auto weapontwo_ = (ui::Button*)weapontwo;
	auto weaponthr = rootNode->getChildByName("Button_1_0_0");
	auto weaponthr_ = (ui::Button*)weaponthr;
	auto weaponfour = rootNode->getChildByName("Button_4");
	auto weaponfour_ = (ui::Button*)weaponfour;
	//weaponone_->setScale(0.5);
	auto mouse = EventListenerMouse::create();
	mouse->onMouseDown = [=](EventMouse*e){
		if (rootNode->getChildByTag(171)->getBoundingBox().containsPoint(e->getLocationInView()))
		{
			hero_create = true;
		}
	};
	mouse->onMouseMove = [=](EventMouse*e)
	{
		if (hero_create)
		{
			rootNode->getChildByTag(171)->getChildByTag(101)->setOpacity(255);
			rootNode->getChildByTag(171)->setPosition(e->getLocationInView());
		//	getChildByTag(101)->setOpacity(255);
		}
			
		
	};
	mouse->onMouseUp = [=](EventMouse*e)
	{
		hero_create = false;
		rootNode->getChildByTag(171)->getChildByTag(101)->setOpacity(0);
		//if (rootNode->getChildByTag(171)->getPosition().x>)
	};
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouse, this);//鼠标事件
	//schedule([=](float){
	//	auto xiaoguai = xiaoguai::create();
	//	xiaoguai->guai_hp = 410 + num * 100 * x->nandu;
	//	xiaoguai->max_num = 410 + num * 100 * x->nandu;
	//	xiaoguai->setPosition(50, 50);
	//	xiaoguai->setScale(1.5);
	//	addChild(xiaoguai);
	//	xiaoguai->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("tx")), CallFuncN::create([=](Node*){	
	//		vec_guai.push_back(xiaoguai);
	//	}), 0));
	//}, 2, "chuguai");//产生怪物
	schedule([=](float){

		for (list<xiaoguai*>::iterator it = vec_guai.begin(); it != vec_guai.end(); ++it)
		{

			
			if ((*it)->ok_move)
			{
            auto xue = LayerColor::create(Color4B::RED, 30, 6);
			(*it)->addChild(xue);
			xue->setPosition(0, 50);
			vec_xue.push_back(xue);
			(*it)->ok_move = false;
			}
			
			if ((*it)->getPosition() == Vec2(50, 50))
			{
				(*it)->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("v_rshang")));
				(*it)->ok_move == false;
				(*it)->runAction(MoveTo::create(5, Vec2(50, 575)));
			}
			if ((*it)->getPosition() == Vec2(50, 575))
			{
				(*it)->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("v_ryou")));
				(*it)->ok_move == true;
				(*it)->runAction(MoveTo::create(5, Vec2(650, 575)));
			}
			if ((*it)->getPosition() == Vec2(650, 575))
			{
				(*it)->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("v_rxia")));
				(*it)->ok_move == false;
				(*it)->runAction(MoveTo::create(5, Vec2(650, 50)));
			}
			if ((*it)->getPosition() == Vec2(650, 50))
			{
				(*it)->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("v_rzuo")));
				(*it)->ok_move == false;
				(*it)->runAction(MoveTo::create(5, Vec2(50, 50)));
			}



		}


	}, 0.1, "move");//怪物移动
	schedule([=](float){
		list<LayerColor*>::iterator it1=vec_xue.begin();
		for (list<xiaoguai*>::iterator it = vec_guai.begin(); it != vec_guai.end(); ++it,++it1)
		{


		
			(*it1)->setContentSize(Size((((*it)->guai_hp)*1.0 / (*it)->max_num) * 25, 6));
		}


	}, 0.1, "xue_select");//设置血条
	schedule([=](float){
		list<LayerColor*>::iterator it1 = vec_xue.begin();
		for (list<xiaoguai*>::iterator it = vec_guai.begin(); it != vec_guai.end(); ++it, ++it1)
		{
			int x1 = (*it)->getPosition().x - rootNode->getChildByTag(171)->getPosition().x;
			int y1 = (*it)->getPosition().y - rootNode->getChildByTag(171)->getPosition().y;
			if (pow(x1*x1 + y1*y1, 0.5) < 150)
			{
				rootNode->getChildByTag(171)->stopAllActions();
				rootNode->getChildByTag(171)->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("hero_actck")));
				(*it)->guai_hp -= hero_->attack_value();
				if (hero_->jineng_1 == true && hero_->jineng_1_ok == true)
				{
					hero_->jineng_1_ok = false;
					auto s = Sprite::create("jineng_1.png");
					jn1 = s;
					s->setTag(1011);
					s->setOpacity(254);
					addChild(s);
					s->setScale(0.6);
					this->jn = true;
					s->setPosition(rootNode->getChildByTag(171)->getPosition() + Vec2(0, 30));
					auto fangxiang = Vec2((*it)->getPosition() - rootNode->getChildByTag(171)->getPosition()).getNormalized();
					s->runAction(MoveBy::create(1, Vec2(fangxiang * 200)));

					s->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("jineng1")), CallFuncN::create([=](Node*){
						this->jn = false;
						s->runAction(RemoveSelf::create());
					}), 0));
				
				}
						if ((*it)->guai_hp <= 0)
						{
							money_hero = money_hero + 5;
							auto x = (*it)->getPosition();
							(*it)->runAction(RemoveSelf::create());
							vec_guai.erase(it);
							(*it1)->runAction(RemoveSelf::create());
							vec_xue.erase(it1);

							dead(x); return;
						}
						else
						{
							rootNode->getChildByTag(171)->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("stand")));
						}
						return;
			}
		}
	}, hero_->attack_sudu / 500.0, "atack");//怪物收到攻击
	schedule([=](float){
		char s[500];
		auto d = itoa(money_hero, s, 10);
		money_lable->setString(d);
		char s1[500];
		auto d1 = itoa(hero_->attack, s1, 10);
		attck_lable->setString(d1);
		char s2[500];
		auto d2 = itoa(hero_->attack_double, s2, 10);
		attck_double_lable->setString(d2);
		char s3[500];
		auto d3 = itoa(hero_->attack_sudu, s3, 10);
		attck_sudu_lable->setString(d3);
		char s4[500];
		auto d4 = itoa(hero_->Grade, s4, 10);
		level_lable->setString(d4);
		if (vec_guai.size() >= 20&&count==0)
		{
			count = 1;
			Director::getInstance()->pushScene(gameover::createScene());
		//	Director::getInstance()->

		}
	}, 0.1, "shop");//状态栏
	schedule([=](float){
	num++;
	}, 2.1, "guainum");//商店
	schedule([=](float){
		if (hero_->Grade >= 0&&hero_->jineng_1==false)
		{
			hero_->jineng_1  = true;
			return;
		}
		else
		{
			hero_->jineng_1 = false;
		}
		hero_->jineng_1_ok = true;
	}, 2, "jineng1");//技能冷却
	schedule([=](float){
		if (this->jn == true)
		{
		
		
		   	list<LayerColor*>::iterator it1=vec_xue.begin();
			for (list<xiaoguai*>::iterator it = vec_guai.begin(); it != vec_guai.end() && it1 != vec_xue.end(); ++it, ++it1)
			{
				if ((*it)->getBoundingBox().intersectsRect(getChildByTag(1011)->getBoundingBox()))
				{
					(*it)->guai_hp -= hero_->attack_value() * 3;
					if ((*it)->guai_hp <= 0)
					{
						money_hero = money_hero + 5;
						(*it)->setOpacity(0);
					
					    (*it1)->setOpacity(0);
					
					}
				}
			}
			}
	}, 0.3, "jinengshanghai");//商店
	//schedule([=](float){

	//	list<LayerColor*>::iterator it1 = vec_xue.begin();
	//	for (list<xiaoguai*>::iterator it = vec_guai.begin(); it != vec_guai.end() && it1 != vec_xue.end(); ++it, ++it1)
	//	{
	//		if ((*it)->guai_hp <= 0)
	//		{
	//			money_hero = money_hero + 5;
	//			auto x = (*it)->getPosition();
	//			(*it)->runAction(RemoveSelf::create());
	//			vec_guai.erase(it);
	//			(*it1)->runAction(RemoveSelf::create());
	//			vec_xue.erase(it1);

	//			dead(x); 
	//		}
	//	}
	//}, 0.1, "ded");//商店
	weaponone_->addClickEventListener([=](Ref*){
		if (money_hero >= 10)
		{
			money_hero -= 10;
			hero_->attack += 5;
			hero_->attack_sudu +=5;
		}

	});
	weapontwo_->addClickEventListener([=](Ref*){
		if (money_hero >= 10)
		{
			money_hero -= 10;
			hero_->attack_double +=5;
			hero_->attack_sudu +=3;
			if (hero_->attack_double > 100)
			{
				hero_->attack_double = 100;
			}
			

		}

	});
	weaponthr_->addClickEventListener([=](Ref*){
		if (money_hero >= 100&&hero_->jin==0)
		{
			hero_->jin = 1;
			money_hero -= 100;
			hero_->attack_double_double ++;
			hero_->attack_double += 20;
			if (hero_->attack_double > 100)
			{
				hero_->attack_double = 100;
			}
		}

	});
	weaponfour_->addClickEventListener([=](Ref*){
		if (money_hero >= 10)
		{
			money_hero -= 10;
			hero_->Grade+=1;
			hero_->attack += 5;
			hero_->attack_double += 3;
			hero_->attack_sudu += 5;
			if (hero_->attack_double > 100)
			{
				hero_->attack_double = 100;
			}
			auto s = Sprite::create();
			addChild(s);
			s->setScale(0.6);
			s->setPosition(rootNode->getChildByTag(171)->getPosition()+Vec2(0,30));
			s->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("hero1level")), CallFuncN::create([=](Node*){
				s->runAction(RemoveSelf::create());
				
			}), 0));
		}

	});
    return true;
}

DWORD WINAPI HelloWorld::threadcreate(LPVOID lp)
{
	HelloWorld* hello = (HelloWorld*)lp;
	
	hello->schedule([=](float){
		auto xiaoguai = xiaoguai::create();
		xiaoguai->guai_hp = 410 + hello->num * 100 ;
		xiaoguai->max_num = 410 + hello->num * 100 ;
		xiaoguai->setPosition(50, 50);
		xiaoguai->setScale(1.5);
		hello->addChild(xiaoguai);
		
		xiaoguai->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("tx")), CallFuncN::create([=](Node*){
			hello->vec_guai.push_back(xiaoguai);
		}), 0));
	}, 2, "chuguai");
	return 0;
}
void HelloWorld::dead(Vec2 x)
{
	int t = 0;
	if (x.x == 50 && x.y >= 50 && x.y < 575)//上
	{
		auto y1 = Sprite::create();
		addChild(y1);
		y1->setPosition(x);
		y1->setScale(1);
		y1->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("n2_shang")), CallFuncN::create([=](Node*){
			y1->runAction(RemoveSelf::create());
		}), 0));
	}
	if (x.y == 575 && x.x >= 50 && x.x < 650)//you
	{
		auto y1 = Sprite::create();
		addChild(y1);
		y1->setPosition(x);
		y1->setScale(1);
		y1->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("n2_you")), CallFuncN::create([=](Node*){
			y1->runAction(RemoveSelf::create());
		}), 0));
	}
	if (x.x == 650 && x.y >= 50 && x.y < 575)//xia
	{
		auto y1 = Sprite::create();
		addChild(y1);
		y1->setPosition(x);
		y1->setScale(1);
		y1->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("n2_xia")), CallFuncN::create([=](Node*){
			y1->runAction(RemoveSelf::create());
		}), 0));
	}
	if (x.y == 50 && x.x >= 50 && x.x < 650)//zuo
	{
		auto y1 = Sprite::create();
		addChild(y1);
		y1->setPosition(x);
		y1->setScale(1);
		y1->runAction(Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation("n2_zuo")), CallFuncN::create([=](Node*){
			y1->runAction(RemoveSelf::create());
		}), 0));
	}


}

