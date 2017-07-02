#include<QString>
#include<Qpixmap>
#include<qsettings.h>
#include "SettingData.h"
#pragma once
//�������
class Organism
{
private:
	int mX, mY; //���Ͻǵ�����
	int mPre; //��һ���ƶ��ķ���
	int mHp_total; //��Ѫ��
	int mHp_cur; //��ǰѪ��
	int mAge; //����
	int mRank; //��ʳ�����еĵȼ�
	int mTypeId; //����
	int mSize; //���
	int mCreatTime; //������ʱ��
	QString mName; //����

public:
	Organism();
	//Organism(int x, int y, int hp, int age, int rank, QString name, int type, int creattime, int size);
	virtual QRect getRect(); //���ظ������rect
	virtual bool move(int x, int y) { return true; };
	virtual QString Info() = 0;
	virtual void saveInfo(QSettings* setting, QString key) = 0; //����
	virtual bool loadInfo(QSettings * setting, QString key, SettingData* sd) = 0; //����
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
	bool addHp(int addhp); //��Ѫ
	bool addHp_percentage(int percentage); //�ٷֱȼ�Ѫ
};