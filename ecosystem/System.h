#pragma once
#include<Qvector>
#include<QPainter>
#include<QTextEdit>
#include<math.h>
#include "Organism.h"
#include "Animal.h"
#include "Grass.h"
#include "SettingData.h"

#include "Cattle.h"
#include "Chick.h"
#include "Deer.h"
#include "Lion.h"
#include "Pig.h"
#include "Tiger.h"
#include "Wolf.h"
#include "Elephant.h"

#define _CREAT(className) new className(x, y, mSettingData.mAnimalSetting[animalType].mHp, 0, PIXRANK[animalType], PIXNAMES[animalType] + "_" + QString::number(count), getRandNum(1, 2) == 1 ? "male" : "female", mSettingData.mAnimalSetting[animalType].mSpeed, mSettingData.mAnimalSetting[animalType].mAttackRange, count, mSettingData.mAnimalSetting[animalType].mSize)
#define IT_A QVector<Animal*>::iterator
#define G2 0.70710678118655
#define IT (*it)
struct Bone
{
	int x, y, endtime,size;
};
struct Born
{
	int type, n , x, y; //种类，数量, 坐标
};
class System
{
public:
	const QString PIXNAMES[11] = {"BG","cattle","chick" ,"deer","elephant","lion","pig","tiger","wolf","bone","grass" };
	const int PIXRANK[11] = {-1,1,1,1,1,4,1,3,2,-1,0};
	static const int PIXBG = 0;

	static const int PIXCATTLE = 1;
	static const int PIXCHICK = 2;
	static const int PIXDEER = 3;
	static const int PIXELEPHANT = 4;
	static const int PIXLION = 5;
	static const int PIXPIG = 6;
	static const int PIXTIGER = 7;
	static const int PIXWOLF = 8;

	static const int PIXBONE = 9;
	static const int PIXGRASS = 10;
	QPixmap mPixmaps[11];
	SettingData mSettingData;

	int count;
private:
	QVector<Animal*>* mAnimals;
	QVector<Grass*>* mGrass;
	QVector<Animal*> deadAnimals;
	Organism* selectedPointer = NULL; //当前被选中的生物
	QVector<Bone> bones;
	QVector<Born> born;

	QTextEdit* textEdit_output;
	QTextEdit* textEdit_animalInfo;
	bool checkXYForCreat(int x, int y, int attackrange,int size);
	double Direction[9][2] = {-G2,-G2,0,-1,G2,-G2,-1,0,0,0,1,0,-G2,G2,0,1,G2,G2};
 public:
	static int getRandNum(int a,int b);
	System();
	~System();
	bool run();	
	void moveXY(Animal* pa,int x, int y, int attackrange);
	void setOutputTextEdit(QTextEdit* te);
	void setAnimalInfoTextEdit(QTextEdit* te);
	void creatAnimal_xy(int animalType, int x, int y);
	void creatAnimal(int animalType);
	void creatAnimal(int animalType,int x,int y);
	void creatAnimal(int animalType, int n);
	void creatGrass();
	void setSettingData(SettingData setting);
	void show(QPainter* painter);
	void print(QString text);
	void select(int x,int y);
	double getDist(int x1,int y1,int x2,int y2);
	QString getOrganismInfo(int x,int y);
	int getSize();
	void saveStatus(QString path); //保存生态系统状态
	void loadStatus(QString path); //导入生态系统状态
};

