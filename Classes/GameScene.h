#pragma once
#include "cocos2d.h"
#include "cardSprite.h"
#include "MenuLayer.h"
#include "LoadingScene.h"

class GameScene :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
	void update(float dt);  // ������Ϸ����ѭ��
	void onPauseButtonClicked(Ref* sender);  // ��ͣ��ť�ص�
	void onResumeButtonClicked(Ref* sender); // �ָ���ť�ص�
	void onExitButtonClicked(Ref* sender);   // �˳���ť�ص�
	void stopGameLogic();  // ֹͣ��Ϸ�߼�
	void resumeGameLogic(); // �ָ���Ϸ�߼�
	void onSoundButtonClicked(Ref* sender);

public:
	
	//��������
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event); //ע������Ҫ�������ռ�������cocos2d
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	//�������һ�������
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();
	//����4*4��Ƭ����
	void createCardArr(Size size);
	void randomCreateCard();
	//�ж���ϷӮ��
	void checkGameWin();
	void checkGameOver();
	void restart(Ref* sender); //���¿�ʼ��Ϸ�˵���
private:
	bool isPaused;  // ��Ϸ�Ƿ���ͣ
	bool isTouchEnabled;      // �Ƿ����ô����¼�
	MenuItemFont* pauseButton;  // ��ͣ��ť
	MenuItemFont* resumeButton; // �ָ���ť
	MenuItemFont* exitButton;   // �˳���ť
	LayerColor* pauseLayer;  // ��͸����ͣ��
	int score;  //��ǰ����
	int bestScore; //��÷���
	bool sound; //��������
	cocos2d::LabelTTF* scoreLabel;
	LabelTTF* restartBtn; //���¿�ʼ�İ�ť
	LabelTTF* isSoundBtn; //�����л���ť
	CardSprite* cardArr[4][4];  //���ֿ�Ƭ����
	CardSprite* cardArrAction[4][4]; //���ڶ�������ʱ���ֿ�Ƭ����
	Point startPt; //������ʼ��
	int offsetX, offsetY;  //����ˮƽ����ֱ����ƫ����
	MenuLayer* menuLayer; //�˵���
	timeval tv; //��ǰʱ��
};