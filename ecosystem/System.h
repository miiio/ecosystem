#pragma once
#include<Qvector>
#include<Qqueue>
#include<QPainter>
#include<QTextEdit>
#include<math.h>
#include "Organism.h"
#include "Animal.h"
#include "Grass.h"
#include "SettingData.h"
#include "DataDialog.h"

#include "Cattle.h"
#include "Chick.h"
#include "Deer.h"
#include "Lion.h"
#include "Pig.h"
#include "Tiger.h"
#include "Wolf.h"
#include "Elephant.h"

#define _CREAT(className) new className(x, y, mSettingData.mAnimalSetting[animalType].mHp, 0, PIXRANK[animalType], PIXNAMES[animalType] + "_" + QString::number(count)+"_"+getRandName(), getRandNum(1, 2) == 1 ? "male" : "female", mSettingData.mAnimalSetting[animalType].mSpeed, mSettingData.mAnimalSetting[animalType].mAttackRange, count, mSettingData.mAnimalSetting[animalType].mSize)
#define IT_A QVector<Animal*>::iterator
#define G2 0.70710678118655
#define IT (*it)
class System
{
private:
	//死亡标记
	struct Bone
	{
		int x, y, endtime, size;
	};
	//新生
	struct Born
	{
		int type, n, x, y; //种类，数量, 坐标
	};
	//闪电
	struct Light
	{
		QRect rect;
		int  startTime;
	};
public:
	const QString PIXNAMES[12] = { "BG","cattle","chick" ,"deer","elephant","lion","pig","tiger","wolf","bone","grass","light" };
	const int PIXRANK[11] = { -1,1,1,1,1,4,1,4,2,-1,0 };  //食物链等级
	//各种生物的类型编号
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
	static const int PIXLIGHT = 11;

	//资源图
	QPixmap mPixmaps[12];
	//配置数据
	SettingData mSettingData;

	int count; //计时器
	QMap<int, DataDialog::NumNode>* mNumData; //动物数量信息

private:
	QVector<Animal*>* mAnimals; //存放所有动物
	QVector<Grass*>* mGrass; //存放草

	QQueue<Animal*> deadAnimals; //需要死亡的动物队列
	QQueue<Born> born;  

	QVector<Bone> bones; //存放需要显示的尸体标记
	QVector<Light> mLights; //闪电

	Organism* selectedPointer = NULL; //当前被选中的生物

	QTextEdit* textEdit_output; //用于输出记录的Text Edit
	QTextEdit* textEdit_animalInfo; //用于显示动物信息的Text Edit


	double Direction[9][2] = { -G2,-G2,0,-1,G2,-G2,-1,0,0,0,1,0,-G2,G2,0,1,G2,G2 };	//9个方向
	QString getRandName(); //生成一个随机的名字
	static int getRandNum(int a, int b); //生成[a,b]随机数
	void initRes(); //初始化资源
	bool checkXYForCreat(int x, int y, int attackrange, int size); //用于检测（x,y）是否可用来生成新的动物
	void Collision(Animal* pa, int x, int y, int attackrange); //检测碰撞
	Animal* creatAnimalPointer(int animalType); //实例化一个指定种类动物的对象
	void creatAnimal(int animalType); //在随机位置生成一个指定种类的动物
	void creatAnimal(int animalType, int x, int y); //在指定位置周围生成一个指定种类的动物
	void creatAnimalInXY(int animalType, int x, int y); //在指定位置生成一个指定种类的动物
	void creatGrass(); //随机生成一棵草
	void print(QString text); //输出信息到Text Edit
	double getDist(int x1, int y1, int x2, int y2); //计算两点之间的距离

public:
	System();
	~System();
	bool run();
	void setOutputTextEdit(QTextEdit* te);
	void setAnimalInfoTextEdit(QTextEdit* te);
	void show(QPainter* painter);
	void saveStatus(QString path); //保存生态系统状态
	void loadStatus(QString path); //导入生态系统状态
	int getSize(); //获取所有动物的数量
	void select(int x, int y);
	void setSettingData(SettingData setting);
	QString getOrganismInfo(int x, int y);
	void creatAnimal(int animalType, int n);
	void recordTheData();
	Organism* getSelectedOrganismP() { return selectedPointer; };

	//手动
	void earthquake();
	void lightn();
	bool kill(Organism* op); //杀死某生物
	bool trea(Organism* op); //治疗某生物
};

