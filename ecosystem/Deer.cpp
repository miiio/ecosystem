#include "Deer.h"

Deer::Deer()
{
	setTypeId(PIXDEER);
}

int Deer::eat(Animal * other, QString & text)
{
	int _default = eat_default(other,text);
	if (_default == 2 && getHp_percentage()>50)//被吃 且当前血量大于50%
	{
		if (SettingData::getRandNum(1, 10) < 4) //有40%的几率逃脱
			return 0;
		else
			return 2;
	}
	return _default;
}

Deer::~Deer()
{
}
