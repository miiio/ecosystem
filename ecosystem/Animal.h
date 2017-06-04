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
	QRect getRect(); //���ؼ��Ϲ�����Χ��rect
	void saveInfo(QSettings* setting, QString key); //����
	void loadInfo(QSettings * setting, QString key, SettingData* sd); //����
	QString Info();
	virtual void move(int x,int y);
	int eat_default(Animal* other, QString& text);
	//��ʳ���� ���أ�0-û�з�����ʳ�� 1-�Ե��ˣ�2-�Լ����Ե���
	virtual int eat(Animal* other, QString& text); 
};

