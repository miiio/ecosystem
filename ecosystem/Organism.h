#include<QString>
#include<Qpixmap>
#include<qsettings.h>
#include "SettingData.h"
#pragma once
//�������
class Organism
{
public:
	int mX, mY; //���Ͻǵ�����
	int mPre; //��һ���ƶ��ķ���
	int mHp_total;
	int mHp_cur;
	int mAge;
	int mRank; //��ʳ�����еĵȼ�
	int mTypeId;
	int mSize;
	int mCreatTime; //������ʱ��
	QString mName;
public:
	Organism();
	Organism(int x, int y,int hp, int age,int rank,QString name,int type,int creattime,int size);
	virtual QRect getRect(); //���ظ������rect
	virtual void move(int x, int y) {};
	virtual QString Info() =0 ;
	virtual void saveInfo(QSettings* setting, QString key) = 0; //����
	virtual void loadInfo(QSettings * setting, QString key, SettingData* sd) = 0; //����
	~Organism();
};