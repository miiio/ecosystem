#include "Wolf.h"

Wolf::Wolf()
{
	setTypeId(PIXWOLF);
}

//扑食规则 返回：0-没有发生扑食， 1-吃掉了，2-自己被吃掉了
int Wolf::eat(Animal * other, QString & text)
{
	if (typeid(other) == typeid(Wolf)) //同类
	{
		if (SettingData::getRandNum(1, 2)==1)
		{
			other->addHp_percentage(-10);
			return 0;
		}
		else
		{
			addHp_percentage(-10);
			return 0;
		}
	}
	return eat_default(other,text);
}

Wolf::~Wolf()
{
}
