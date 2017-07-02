#pragma once
#include <qstring.h>
#include <QSettings>
using namespace std;
//�����涯�������ͻ�����Ϣ
struct AnimalSetting
{
	int mHp;
	int mSpeed;
	int mAttackRange;
	int mSize;
	int mNum;
};
Q_DECLARE_METATYPE(AnimalSetting)
class SettingData
{
public:
	static int getRandNum(int a, int b);
	static const int mGrassSize = 40; //�ݵ����
	static const int mGrassHp = 10; //�ݵ�Ѫ��
	static const int mGrassAdd = 20; //�Բݻظ���Ѫ�����ٷֱ�
	static const int mGrassHpLimit = 90; //Ѫ�����ڶ��ٲųԲ�
	static const int mGrassNum = 15; //����ͼ�ϲݵ�����ά����һ��������

	static const int LightTime = 5; //�������ʱ��
	static const int LightWidth = 100; //������
	static const int LightHeight = 100;  //����߶�
	static const int LightHurt = 90; //������ٵİٷְ�Ѫ��

	static const int earthquakeTime = 20; //���𶶶�����
	static const int earthquakeHurt = 10; //������ٵİٷְ�Ѫ��

	int mMapWidth = 900;
	int mMapHeight = 600; //900x600
	int mapPadding = 20; //��ͼ��λ������������Ͻǵļ��
	int mBoneTime = 8; //������־��ʾʱ��
	int mAge = 10; //�����������һ��
	int mReproduceAge = 3;//��ֳ����
	int mReproduceHp = 80; //��ֳ����Ҫ��Ѫ�����ٷֱ�
	int mReproduceProportion = 40; //��ֳ�ɹ��ĸ���
	int mDeadAGe = 100; //��������
	int mAnimalLimit = 130; //������������
	int mBornRange = 150; //��ֳ���ɶ�����뷶Χ
	AnimalSetting mAnimalSetting[9]; //���������ͻ�����Ϣ 1~8
public:
	SettingData();
	~SettingData();
	bool loadFromFile(QString path);
	bool loadFromFile(); //����Ĭ������
	bool saveToFile(QString path);
};
