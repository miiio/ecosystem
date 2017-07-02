#include "Elephant.h"

Elephant::Elephant()
{
	setTypeId(PIXELEPHANT);
}

int Elephant::reproduce(Animal * other, SettingData * sd, QString & text)
{
	//大象每胎一般只生一只
	if (reproduce_default(other, sd, text))
	{
		if (SettingData::getRandNum(1, 100) < 95)
			return 1;
		else
			return SettingData::getRandNum(2,3); //百分之五的几率生2~3只
	}
	else
		return 0; //不符合规则
}

Elephant::~Elephant()
{
}
