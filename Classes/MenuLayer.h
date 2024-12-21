#pragma once
#include "cocos2d.h"
class MenuLayer :public cocos2d::LayerColor
{
public:
	static MenuLayer* create(const cocos2d::Color4B& color);
	virtual bool initWithColor(const cocos2d::Color4B& color);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};