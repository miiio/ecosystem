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

	QString mSex; //female,male
	int mSpeed;
	int mAttackRange;
public:
	Animal(int x, int y, int hp, int age, int rank, 
		QString name,QString mSex,int speed,int attackrange,int type,int creattime,int size);
	~Animal();
	Animal();
	int getAttackRange(); 
	QRect getRect(); //返回加上攻击范围的rect
	void saveInfo(QSettings* setting, QString key); //保存
	void loadInfo(QSettings * setting, QString key, SettingData* sd); //加载
	QString Info();
	virtual void move(int x,int y);
	int eat_default(Animal* other, QString& text);
	//扑食规则 返回：0-没有发生扑食， 1-吃掉了，2-自己被吃掉了
	virtual int eat(Animal* other, QString& text); 
};

