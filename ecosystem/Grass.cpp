#include "Grass.h"
#include "SettingData.h"


Grass::Grass()
{
	//Organism(int x, int y, int hp, int age, int rank, QString name, int type, int creattime, int size);
	setTotalHp(SettingData::mGrassHp);
	setHp(getTotalHp());
	setAge(0);
	setRank(-1);
	setName("grass");
	setTypeId(10);
	setCreatTime(0);
	setSize(SettingData::mGrassSize);
}


Grass::~Grass()
{
}

QString Grass::Info()
{
	QString str;
	str += "  Grass ";
	str += "Hp : " + QString::number(getHp(), 10) + "\n";
	str += "Coordinate : " + QString::number(getX(), 10) + "," + QString::number(getY(), 10);
	return str;
}


void Grass::saveInfo(QSettings* setting, QString key)
{
	setting->setValue(key + "mX", getX());
	setting->setValue(key + "mY",getY());
	setting->setValue(key + "mHp_cur", getHp());
}

bool Grass::loadInfo(QSettings * setting, QString key, SettingData* sd)
{
	bool ret = true;
	ret=ret&&	setX(setting->value(key + "mX").toInt());
	ret = ret&&	setY(setting->value(key + "mY").toInt()); //Î»ÖÃ
	ret = ret&&	setHp(setting->value(key + "mHp_cur").toInt()); //ÐÞ¸ÄÑªÁ¿
	return ret;
}
