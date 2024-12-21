#include "LoadingScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

Scene* LoadingScene::createScene()
{
    auto scene = Scene::create();
    auto layer = LoadingScene::create();
    scene->addChild(layer);
    return scene;
}

bool LoadingScene::init()
{
    if (Layer::init())
    {
        // 创建背景颜色为橙色 (与原始背景色一致)
        auto bkGround = LayerColor::create(Color4B(255, 165, 0, 255));
        this->addChild(bkGround);

        // 创建游戏标题
        auto logo = LabelTTF::create("HOHO's 2048", "Arial", 30);
        logo->setColor(Color3B(255, 255, 255));  // 设置白色字体
        logo->setPosition(bkGround->getContentSize().width / 2, bkGround->getContentSize().height / 2 + 100);
        bkGround->addChild(logo);

        // 创建开始游戏按钮
        auto startButton = MenuItemFont::create("Start Game", CC_CALLBACK_1(LoadingScene::startGame, this));
        startButton->setPosition(bkGround->getContentSize().width / 2, bkGround->getContentSize().height / 2);

        // 创建退出按钮
        auto quitButton = MenuItemFont::create("Quit Game", CC_CALLBACK_1(LoadingScene::quitGame, this));
        quitButton->setPosition(bkGround->getContentSize().width / 2, bkGround->getContentSize().height / 2 - 50);

        // 创建菜单并添加按钮
        auto menu = Menu::create(startButton, quitButton, nullptr);
        menu->setPosition(Vec2::ZERO);  // 将菜单项的位置设置为 (0, 0)
        bkGround->addChild(menu);

        return true;
    }

    return false;
}

// 开始游戏按钮的回调函数
void LoadingScene::startGame(Ref* sender)
{
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f, scene));
}

// 退出游戏按钮的回调函数
void LoadingScene::quitGame(Ref* sender)
{
    Director::getInstance()->end();  // 退出游戏
}
