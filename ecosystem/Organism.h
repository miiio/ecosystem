#include<QString>
#include<Qpixmap>
#include<qsettings.h>
#include "SettingData.h"
#pragma once
//生物基类
class Organism
{
public:
	int mX, mY; //左上角的坐标
	int mPre; //上一次移动的方向
	int mHp_total;
	int mHp_cur;
	int mAge;
	int mRank; //在食物链中的等级
	int mTypeId;
	int mSize;
	int mCreatTime; //创建的时间
	QString mName;
public:
	Organism();
	Organism(int x, int y,int hp, int age,int rank,QString name,int type,int creattime,int size);
	virtual QRect getRect(); //返回该生物的rect
	virtual void move(int x, int y) {};
	virtual QString Info() =0 ;
	virtual void saveInfo(QSettings* setting, QString key) = 0; //保存
	virtual void loadInfo(QSettings * setting, QString key, SettingData* sd) = 0; //加载
	~Organism();
};