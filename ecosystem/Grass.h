#pragma once
#include "Organism.h"
class Grass :
	public Organism
{
public:
	Grass();
	Grass(int x,int y);
	~Grass();
	QString Info();
	void saveInfo(QSettings* setting, QString key); //����
	void loadInfo(QSettings * setting, QString key, SettingData* sd); //����
};

