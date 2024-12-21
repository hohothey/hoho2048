#include "AppDelegate.h"
#include "GameScene.h"
#include "LoadingScene.h"
USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    if (!glview) {
        glview = GLViewImpl::createWithRect("HOHO'S 2048", Rect(0, 0, 500, 800));  // 设置视口大小
        director->setOpenGLView(glview);
    }
    glview->setDesignResolutionSize(268, 512, ResolutionPolicy::EXACT_FIT);
    director->setDisplayStats(false);  // 发布版本不显示FPS
    director->setAnimationInterval(1.0 / 60);
    auto scene = LoadingScene::createScene();  // 确保LoadingScene.h有createScene方法

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
