#include "SettingData.h"



int SettingData::getRandNum(int a, int b)
{
	return (rand() % (a ? b : b + 1)) + a;
}

SettingData::SettingData()
{
	loadFromFile();
}


SettingData::~SettingData()
{
}

bool SettingData::loadFromFile(QString path)
{
	QSettings setting(path, QSettings::IniFormat);//读取配置
	setting.beginGroup("config");
	mMapWidth = setting.value("mMapWidth").toInt();
	mMapHeight = setting.value("mMapHeight").toInt();
	mBoneTime = setting.value("mBoneTime").toInt();
	mAge = setting.value("mAge").toInt();
	mReproduceAge = setting.value("mReproduceAge").toInt();
	mReproduceHp = setting.value("mReproduceHp").toInt();
	mReproduceProportion = setting.value("mReproduceProportion").toInt();
	mDeadAGe = setting.value("mDeadAGe").toInt();
	mAnimalLimit = setting.value("mAnimalLimit").toInt();
	for (int i = 1; i <= 8; i++)
	{
		QString key = "Animal" + QString::number(i, 10) + "_";
		mAnimalSetting[i].mHp = setting.value(key + "mHp").toInt();
		mAnimalSetting[i].mSpeed = setting.value(key + "mSpeed").toInt();
		mAnimalSetting[i].mAttackRange = setting.value(key + "mAttackRange").toInt();
		mAnimalSetting[i].mSize = setting.value(key + "mSize").toInt();
		mAnimalSetting[i].mNum = setting.value(key + "mNum").toInt();
	}
	setting.endGroup();
	return true;
}

bool SettingData::loadFromFile()
{
	return loadFromFile("C:\\C++\\C++\\ecosystem\\default.sd");
}

bool SettingData::saveToFile(QString path)
{
	QSettings setting(path, QSettings::IniFormat);//生成配置文件
	setting.beginGroup("config");
	setting.setValue("mMapWidth", QVariant(mMapWidth));
	setting.setValue("mMapHeight", QVariant(mMapHeight));
	setting.setValue("mBoneTime", QVariant(mBoneTime));
	setting.setValue("mAge", QVariant(mAge));
	setting.setValue("mReproduceAge", QVariant(mReproduceAge));
	setting.setValue("mReproduceHp", QVariant(mReproduceHp));
	setting.setValue("mReproduceProportion", QVariant(mReproduceProportion));
	setting.setValue("mDeadAGe", QVariant(mDeadAGe));
	setting.setValue("mAnimalLimit", QVariant(mAnimalLimit));
	for (int i = 1; i <= 8; i++)
	{
		QString key = "Animal" + QString::number(i, 10) + "_";
		setting.setValue(key + "mHp", QVariant(mAnimalSetting[i].mHp));
		setting.setValue(key + "mSpeed", QVariant(mAnimalSetting[i].mSpeed));
		setting.setValue(key + "mAttackRange", QVariant(mAnimalSetting[i].mAttackRange));
		setting.setValue(key + "mSize", QVariant(mAnimalSetting[i].mSize));
		setting.setValue(key + "mNum", QVariant(mAnimalSetting[i].mNum));
	}
	setting.endGroup();
	return true;
}