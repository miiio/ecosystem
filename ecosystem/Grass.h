#pragma once
#include "Organism.h"
class Grass :
	public Organism
{
public:
	Grass();
	//Grass(int x,int y);
	~Grass();
	QString Info();
	void saveInfo(QSettings* setting, QString key); //±£¥Ê
	bool loadInfo(QSettings * setting, QString key, SettingData* sd); //º”‘ÿ
};

