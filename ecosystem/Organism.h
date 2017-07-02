#include<QString>
#include<Qpixmap>
#include<qsettings.h>
#include "SettingData.h"
#pragma once
//生物基类
class Organism
{
private:
	int mX, mY; //左上角的坐标
	int mPre; //上一次移动的方向
	int mHp_total; //总血量
	int mHp_cur; //当前血量
	int mAge; //年龄
	int mRank; //在食物链中的等级
	int mTypeId; //物种
	int mSize; //体积
	int mCreatTime; //创建的时间
	QString mName; //名字

public:
	Organism();
	//Organism(int x, int y, int hp, int age, int rank, QString name, int type, int creattime, int size);
	virtual QRect getRect(); //返回该生物的rect
	virtual bool move(int x, int y) { return true; };
	virtual QString Info() = 0;
	virtual void saveInfo(QSettings* setting, QString key) = 0; //保存
	virtual bool loadInfo(QSettings * setting, QString key, SettingData* sd) = 0; //加载
	~Organism();

	//get/set
	const int getX() { return mX; };
	const int getY() { return mY; };
	const int getPreDirection() { return mPre; };
	const int getTotalHp() { return mHp_total; };
	const int getHp() { return mHp_cur; };
	const int getHp_percentage() { return mHp_cur * 100 / mHp_total; };
	const int getAge() { return mAge; };
	const int getRank() { return mRank; };
	const int getTypeId() { return mTypeId; };
	const int getSize() { return mSize; };
	const int getCreatTime() { return mCreatTime; };
	const QString getName() { return mName; };

	bool setX(int x);
	bool setY(int y);
	bool setPreDirection(int pre);
	bool setTotalHp(int hp_total);
	bool setHp(int hp_cur);
	bool setAge(int age);
	bool setRank(int rank);
	bool setTypeId(int typeId);
	bool setSize(int size);
	bool setCreatTime(int creattime);
	bool setName(QString name);
	bool addHp(int addhp); //加血
	bool addHp_percentage(int percentage); //百分比加血
};