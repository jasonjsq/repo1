#ifndef __HLLOWORLD_SCENE_H__
#define __HLLOWORLD_SCENE_H__

#include "cocos2d.h"
#include<list>
#include<windows.h>
using namespace std;
#include"changjing.h"
#include"gameover.h"
class xiaoguai :public cocos2d::Sprite
{
public:

	cocos2d::LayerColor* xuetiao;
	int guai_hp;
	int guai_num;
	bool ok_move;
	bool xue;
	int max_num;
	
	virtual bool init();
	CREATE_FUNC(xiaoguai);

};
class hero :public cocos2d::Sprite
{
public:
	int nandu;
	int num;
	int Grade;
	int jin;
	int attack;
	int attack_sudu;
	int attack_double;
	bool jineng_1;
	bool jineng_1_ok;
	int attack_double_double;
	int attack_value();
	virtual bool init();
	CREATE_FUNC(hero);

};
  //hero *v=new  hero();

class HelloWorld : public cocos2d::Layer
{
public:
	//cocos2d::Label* money_lable;
    int jn;
	int num;
	int money_hero;
    static cocos2d::Scene* createScene();
    virtual bool init();
	bool hero_create;
	list<xiaoguai*>vec_guai;
	cocos2d::Sprite*jn1;
	list<cocos2d::LayerColor*>vec_xue;

	void dead(cocos2d::Vec2 x);
	hero* hero_;
	cocos2d::String doutoa(double a);
	static DWORD WINAPI threadcreate(LPVOID);
	HANDLE h;
	int count;
    CREATE_FUNC(HelloWorld);
};
#endif // __HELLOWORLD_SCENE_H__
