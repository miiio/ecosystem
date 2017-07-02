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
	//�������
	struct Bone
	{
		int x, y, endtime, size;
	};
	//����
	struct Born
	{
		int type, n, x, y; //���࣬����, ����
	};
	//����
	struct Light
	{
		QRect rect;
		int  startTime;
	};
public:
	const QString PIXNAMES[12] = { "BG","cattle","chick" ,"deer","elephant","lion","pig","tiger","wolf","bone","grass","light" };
	const int PIXRANK[11] = { -1,1,1,1,1,4,1,4,2,-1,0 };  //ʳ�����ȼ�
	//������������ͱ��
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

	//��Դͼ
	QPixmap mPixmaps[12];
	//��������
	SettingData mSettingData;

	int count; //��ʱ��
	QMap<int, DataDialog::NumNode>* mNumData; //����������Ϣ

private:
	QVector<Animal*>* mAnimals; //������ж���
	QVector<Grass*>* mGrass; //��Ų�

	QQueue<Animal*> deadAnimals; //��Ҫ�����Ķ������
	QQueue<Born> born;  

	QVector<Bone> bones; //�����Ҫ��ʾ��ʬ����
	QVector<Light> mLights; //����

	Organism* selectedPointer = NULL; //��ǰ��ѡ�е�����

	QTextEdit* textEdit_output; //���������¼��Text Edit
	QTextEdit* textEdit_animalInfo; //������ʾ������Ϣ��Text Edit


	double Direction[9][2] = { -G2,-G2,0,-1,G2,-G2,-1,0,0,0,1,0,-G2,G2,0,1,G2,G2 };	//9������
	QString getRandName(); //����һ�����������
	static int getRandNum(int a, int b); //����[a,b]�����
	void initRes(); //��ʼ����Դ
	bool checkXYForCreat(int x, int y, int attackrange, int size); //���ڼ�⣨x,y���Ƿ�����������µĶ���
	void Collision(Animal* pa, int x, int y, int attackrange); //�����ײ
	Animal* creatAnimalPointer(int animalType); //ʵ����һ��ָ�����ද��Ķ���
	void creatAnimal(int animalType); //�����λ������һ��ָ������Ķ���
	void creatAnimal(int animalType, int x, int y); //��ָ��λ����Χ����һ��ָ������Ķ���
	void creatAnimalInXY(int animalType, int x, int y); //��ָ��λ������һ��ָ������Ķ���
	void creatGrass(); //�������һ�ò�
	void print(QString text); //�����Ϣ��Text Edit
	double getDist(int x1, int y1, int x2, int y2); //��������֮��ľ���

public:
	System();
	~System();
	bool run();
	void setOutputTextEdit(QTextEdit* te);
	void setAnimalInfoTextEdit(QTextEdit* te);
	void show(QPainter* painter);
	void saveStatus(QString path); //������̬ϵͳ״̬
	void loadStatus(QString path); //������̬ϵͳ״̬
	int getSize(); //��ȡ���ж��������
	void select(int x, int y);
	void setSettingData(SettingData setting);
	QString getOrganismInfo(int x, int y);
	void creatAnimal(int animalType, int n);
	void recordTheData();
	Organism* getSelectedOrganismP() { return selectedPointer; };

	//�ֶ�
	void earthquake();
	void lightn();
	bool kill(Organism* op); //ɱ��ĳ����
	bool trea(Organism* op); //����ĳ����
};

