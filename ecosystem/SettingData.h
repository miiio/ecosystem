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
	static const int mGrassSize = 40; //�ݵ����
	static const int mGrassHp = 10; //�ݵ�Ѫ��
	static const int mGrassAdd = 20; //�Բݻظ���Ѫ�����ٷֱ�
	static const int mGrassHpLimit = 90; //Ѫ�����ڶ��ٲųԲ�
	static const int mGrassNum = 10; //����ͼ�ϲݵ�����ά����һ��������

	int mMapWidth = 900;
	int mMapHeight = 600; //1000x700
	int mapPadding = 20; //��ͼ��λ�������������Ͻǵļ��
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
	bool loadFromFile();
	bool saveToFile(QString path);
};