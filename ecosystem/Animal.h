#pragma once
#include "Organism.h"
class Animal :
	public Organism
{
public:
	static const int PIXCATTLE = 1;
	static const int PIXCHICK = 2;
	static const int PIXDEER = 3;
	static const int PIXELEPHANT = 4;
	static const int PIXLION = 5;
	static const int PIXPIG = 6;
	static const int PIXTIGER = 7;
	static const int PIXWOLF = 8;

protected:
	QString mSex; //female,male
	int mSpeed;
	int mAttackRange;

public:
	int getSpeed() { return mSpeed; };
	int getAttackRange();
	QString getSex() { return mSex; };

	bool setSpeed(int speed);
	bool setAttackRange(int attackrange);
	bool setSex(QString sex);

public:
	~Animal();
	Animal();
	QRect getRect(); //返回加上攻击范围的rect
	void saveInfo(QSettings* setting, QString key); //保存
	bool loadInfo(QSettings * setting, QString key, SettingData* sd); //加载
	QString Info();

	virtual bool isPredator() = 0; //是否是捕食者

	virtual bool move(int x,int y);

	//扑食规则 返回：0-没有发生扑食， 1-吃掉了，2-自己被吃掉了
	int eat_default(Animal* other, QString& text);
	virtual int eat(Animal* other, QString& text);  //默认调用默认规则，子类可覆盖该方法

	//繁殖规则 返回数量
	int reproduce_default(Animal* other, SettingData* sd, QString& text);
	virtual int reproduce(Animal* other, SettingData* sd, QString& text); //默认调用默认规则，子类可覆盖该方法
};

