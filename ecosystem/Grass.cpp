#include "Grass.h"
#include "SettingData.h"


Grass::Grass()
{
}

Grass::Grass(int x,int y) :
	Organism(x, y, 10, 0, 0, "grass", 10, -1, SettingData::mGrassSize)
{

}


Grass::~Grass()
{
}

QString Grass::Info()
{
	QString str;
	str += "  Grass ";
	str += "Hp : " + QString::number(mHp_cur, 10) + "\n";
	str += "Coordinate : " + QString::number(mX, 10) + "," + QString::number(mY, 10);
	return str;
}


void Grass::saveInfo(QSettings* setting, QString key)
{
	setting->setValue(key + "mX", mX);
	setting->setValue(key + "mY", mY);
	setting->setValue(key + "mHp_cur", mHp_cur);
}

void Grass::loadInfo(QSettings * setting, QString key, SettingData* sd)
{
	mX = setting->value(key + "mX").toInt();
	mY =setting->value(key + "mY").toInt(); //Î»ÖÃ
	mHp_cur = setting->value(key + "mHp_cur").toInt(); //ÐÞ¸ÄÑªÁ¿
}
