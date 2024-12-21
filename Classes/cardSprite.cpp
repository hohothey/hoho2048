#include "cardSprite.h"
bool CardSprite::init()
{
	//��׼init
	if (!Sprite::init())
		return false;
	else
		return true;
}

//��ʼ����Ƭ�����֣��ߴ磬����
void CardSprite::cardInit(int num, int cardWidth, int cardHeight, float px, float py)
{
	number = num;
	cardBgColour = LayerColor::create(Color4B(200, 190, 180, 255), cardWidth - 5, cardHeight - 5);
	cardBgColour->setPosition(Point(px, py));
	if (number > 0) //��������֣�����ʾ����
	{
		cardLabel = LabelTTF::create(String::createWithFormat("%d", number)->getCString(), "Arial", 50);
		//��Ϊ�Ǽ��뵽���ڵ��У����Դ˴����������
		cardLabel->setPosition(cardBgColour->getContentSize().width / 2, cardBgColour->getContentSize().height / 2);
		cardBgColour->addChild(cardLabel); //�����ֱ�ǩ���뵽��Ƭ��

	}
	else    //�������ǿտ�Ƭ
	{
		cardLabel = LabelTTF::create("", "Arial", 50);
		cardLabel->setPosition(cardBgColour->getContentSize().width / 2, cardBgColour->getContentSize().height / 2);
		cardBgColour->addChild(cardLabel);
	}
	this->addChild(cardBgColour);  //����Ƭ����뵽��Ƭ����
}

//����һ����Ƭ�����ָ��
CardSprite* CardSprite::createCard(int num, int cardWidth, int cardHeight, float px, float py)
{
	CardSprite* card = new CardSprite();
	if (!card->init())
	{
		CC_SAFE_RELEASE(card);
		return NULL;
	}
	card->autorelease();  //����Ϊ�Զ�����
	card->cardInit(num, cardWidth, cardHeight, px, py);
	return card;
}

//���ÿ�Ƭ������
void CardSprite::setNumber(int num)
{
	number = num;
	//���ݲ�ͬ�����ַ�Χ��ʾ��ͬ����ɫ
	if (number >= 0 && number < 16)
	{
		cardLabel->setFontSize(50);
	}
	if (number >= 16 && number < 128)
	{
		cardLabel->setFontSize(40);
	}
	if (number >= 128 && number < 1024)
	{
		cardLabel->setFontSize(30);
	}
	if (number >= 1024)
	{
		cardLabel->setFontSize(20);
	}
	if (number == 0)
	{
		cardBgColour->setColor(Color3B(200, 190, 180));
	}
	if (number == 2)
	{
		cardBgColour->setColor(Color3B(139, 0, 0));
	}
	if (number == 4)
	{
		cardBgColour->setColor(Color3B(0, 100, 0));
	}
	if (number == 8) {
		cardBgColour->setColor(Color3B(300,100, 100));
	}
	if (number == 16)
	{
		cardBgColour->setColor(Color3B(100, 60, 100));
	}
	if (number == 32)
	{
		cardBgColour->setColor(Color3B(100, 140, 180));
	}
	if (number == 64)
	{
		cardBgColour->setColor(Color3B(180, 130, 130));
	}
	if (number == 128)
	{
		cardBgColour->setColor(Color3B(150, 70, 0));
	}
	if (number == 256)
	{
		cardBgColour->setColor(Color3B(120, 150, 40));
	}
	if (number == 512)
	{
		cardBgColour->setColor(Color3B(180, 60, 60));
	}
	if (number == 1024)
	{
		cardBgColour->setColor(Color3B(150, 150, 200));
	}
	if (number == 2048)
	{
		cardBgColour->setColor(Color3B(180, 120, 0));
	}

	if (number > 0)  //�����ִ���0ʱ����ʾ����
		cardLabel->setString(String::createWithFormat("%d", number)->getCString());
	else  //������ʾ��
		cardLabel->setString("");
}

//��ÿ�Ƭ����
int CardSprite::getNumber()
{
	return number;
}

//��ÿ�Ƭ��
LayerColor* CardSprite::getCardLayer()
{
	return cardBgColour;
}