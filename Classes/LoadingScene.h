#pragma once
#include "cocos2d.h"

class LoadingScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(LoadingScene);

    void startGame(Ref* sender);  // 开始游戏按钮回调
    void quitGame(Ref* sender);   // 退出按钮回调
};
