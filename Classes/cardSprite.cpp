#include "cardSprite.h"
bool CardSprite::init()
{
	//标准init
	if (!Sprite::init())
		return false;
	else
		return true;
}

//初始化卡片，数字，尺寸，坐标
void CardSprite::cardInit(int num, int cardWidth, int cardHeight, float px, float py)
{
	number = num;
	cardBgColour = LayerColor::create(Color4B(200, 190, 180, 255), cardWidth - 5, cardHeight - 5);
	cardBgColour->setPosition(Point(px, py));
	if (number > 0) //如果有数字，则显示数字
	{
		cardLabel = LabelTTF::create(String::createWithFormat("%d", number)->getCString(), "Arial", 50);
		//因为是加入到父节点中，所以此处用相对坐标
		cardLabel->setPosition(cardBgColour->getContentSize().width / 2, cardBgColour->getContentSize().height / 2);
		cardBgColour->addChild(cardLabel); //将文字标签加入到卡片层

	}
	else    //否则则是空卡片
	{
		cardLabel = LabelTTF::create("", "Arial", 50);
		cardLabel->setPosition(cardBgColour->getContentSize().width / 2, cardBgColour->getContentSize().height / 2);
		cardBgColour->addChild(cardLabel);
	}
	this->addChild(cardBgColour);  //将卡片层加入到卡片精灵
}

//返回一个卡片精灵的指针
CardSprite* CardSprite::createCard(int num, int cardWidth, int cardHeight, float px, float py)
{
	CardSprite* card = new CardSprite();
	if (!card->init())
	{
		CC_SAFE_RELEASE(card);
		return NULL;
	}
	card->autorelease();  //设置为自动回收
	card->cardInit(num, cardWidth, cardHeight, px, py);
	return card;
}

//设置卡片的数字
void CardSprite::setNumber(int num)
{
	number = num;
	//根据不同的数字范围显示不同的颜色
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

	if (number > 0)  //当数字大于0时才显示数字
		cardLabel->setString(String::createWithFormat("%d", number)->getCString());
	else  //否则显示空
		cardLabel->setString("");
}

//获得卡片数字
int CardSprite::getNumber()
{
	return number;
}

//获得卡片层
LayerColor* CardSprite::getCardLayer()
{
	return cardBgColour;
}