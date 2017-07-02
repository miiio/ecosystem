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
	QRect getRect(); //���ؼ��Ϲ�����Χ��rect
	void saveInfo(QSettings* setting, QString key); //����
	bool loadInfo(QSettings * setting, QString key, SettingData* sd); //����
	QString Info();

	virtual bool isPredator() = 0; //�Ƿ��ǲ�ʳ��

	virtual bool move(int x,int y);

	//��ʳ���� ���أ�0-û�з�����ʳ�� 1-�Ե��ˣ�2-�Լ����Ե���
	int eat_default(Animal* other, QString& text);
	virtual int eat(Animal* other, QString& text);  //Ĭ�ϵ���Ĭ�Ϲ�������ɸ��Ǹ÷���

	//��ֳ���� ��������
	int reproduce_default(Animal* other, SettingData* sd, QString& text);
	virtual int reproduce(Animal* other, SettingData* sd, QString& text); //Ĭ�ϵ���Ĭ�Ϲ�������ɸ��Ǹ÷���
};

