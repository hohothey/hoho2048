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
        glview = GLViewImpl::createWithRect("HOHO'S 2048", Rect(0, 0, 500, 800));  // �����ӿڴ�С
        director->setOpenGLView(glview);
    }
    glview->setDesignResolutionSize(268, 512, ResolutionPolicy::EXACT_FIT);
    director->setDisplayStats(false);  // �����汾����ʾFPS
    director->setAnimationInterval(1.0 / 60);
    auto scene = LoadingScene::createScene();  // ȷ��LoadingScene.h��createScene����

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
