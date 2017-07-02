#pragma once
#include <qstring.h>
#include <QSettings>
using namespace std;
//用来存动物数量和基本信息
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
	static const int mGrassSize = 40; //草的体积
	static const int mGrassHp = 10; //草的血量
	static const int mGrassAdd = 20; //吃草回复的血量，百分比
	static const int mGrassHpLimit = 90; //血量低于多少才吃草
	static const int mGrassNum = 15; //将地图上草的数量维持在一定的数量

	static const int LightTime = 5; //闪电持续时间
	static const int LightWidth = 100; //闪电宽度
	static const int LightHeight = 100;  //闪电高度
	static const int LightHurt = 90; //闪电减少的百分百血量

	static const int earthquakeTime = 20; //地震抖动次数
	static const int earthquakeHurt = 10; //地震减少的百分百血量

	int mMapWidth = 900;
	int mMapHeight = 600; //900x600
	int mapPadding = 20; //地图的位于软件界面左上角的间距
	int mBoneTime = 8; //死亡标志显示时间
	int mAge = 10; //多久年龄增加一次
	int mReproduceAge = 3;//繁殖年龄
	int mReproduceHp = 80; //繁殖所需要的血量，百分比
	int mReproduceProportion = 40; //繁殖成功的概率
	int mDeadAGe = 100; //死亡年龄
	int mAnimalLimit = 130; //动物数量限制
	int mBornRange = 150; //繁殖生成动物距离范围
	AnimalSetting mAnimalSetting[9]; //动物数量和基本信息 1~8
public:
	SettingData();
	~SettingData();
	bool loadFromFile(QString path);
	bool loadFromFile(); //加载默认配置
	bool saveToFile(QString path);
};
